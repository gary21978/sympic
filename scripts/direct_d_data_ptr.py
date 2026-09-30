#!/usr/bin/env python3
"""统一地址空间: 消除 mapsMemobjGetPhysicalAddress 语句表达式包装.

  ((__DDR int *)({
          uint64_t __d_data_address_tmp2;
          mapsMemobjGetPhysicalAddress(kerstr->cu_xyzw->d_data, &__d_data_address_tmp2);
          __d_data_address_tmp2;
        }))
    ->  ((__DDR int *)(kerstr->cu_xyzw->d_data))

前提(用户确认): 运行时不再区分 d_data 的虚拟/物理地址, 内核参数直接
传 d_data 指针. 这是语义变更, 必须配合模拟器算例回归验证.

只匹配标准形态: 强转(__DDR 可选) + GNU 语句表达式, 体内恰好是
  uint64_t V[ = 0]; mapsMemobjGetPhysicalAddress(E, &V); V;
其他用法(宏定义内等)不碰, 由人工处理.

用法: python3 scripts/direct_d_data_ptr.py [--dry-run]
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

CAST = r"\(\s*(?:__DDR\s+)?[A-Za-z_]\w*\s*\*\s*\)"
# 外( + 强转 + ({ + uint64_t V; + mapsMemobjGetPhysicalAddress(
BODY = re.compile(
    rf"\(\s*({CAST})\s*\(\{{\s*"
    rf"uint64_t\s+(\w+)\s*(?:=\s*0\s*)?;\s*"
    rf"mapsMemobjGetPhysicalAddress\s*\(",
    re.S,
)


def protected_spans(text: str) -> list[tuple[int, int]]:
    spans, i, n = [], 0, len(text)
    pp = False
    while i < n:
        if text[i] == "\n":
            i += 1
            continue
        nl = text.find("\n", i)
        line_end = n if nl == -1 else nl
        line = text[i:line_end]
        jump = None
        if pp or line.lstrip().startswith("#"):
            spans.append((i, line_end))
        else:
            j = 0
            while j < len(line):
                c = line[j]
                if c in "\"'":
                    k = j + 1
                    while k < len(line) and line[k] != c:
                        k += 2 if line[k] == "\\" else 1
                    spans.append((i + j, i + min(k + 1, len(line))))
                    j = k + 1
                elif line.startswith("//", j):
                    spans.append((i + j, line_end))
                    break
                elif line.startswith("/*", j):
                    end = text.find("*/", i + j)
                    end = n if end == -1 else end + 2
                    spans.append((i + j, end))
                    if end > line_end:
                        jump = end
                        break
                    j = end - i
                else:
                    j += 1
        if jump is not None:
            i = jump
            pp = False
            continue
        pp = line.rstrip().endswith("\\")
        i = line_end + 1 if nl != -1 else n
    return spans


def in_protected(pos: int, spans) -> bool:
    return any(a <= pos < b for a, b in spans)


def match_delim(text: str, open_pos: int, o: str, c: str) -> int | None:
    depth = 0
    for i in range(open_pos, len(text)):
        if text[i] == o:
            depth += 1
        elif text[i] == c:
            depth -= 1
            if depth == 0:
                return i
    return None


def split_args(s: str) -> list[str] | None:
    """按顶层逗号切分实参."""
    args, depth, cur = [], 0, []
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            args.append("".join(cur))
            cur = []
        else:
            cur.append(ch)
    args.append("".join(cur))
    return args if len(args) == 2 else None


def transform_text(text: str, spans) -> tuple[str, int]:
    out, i, n, count = [], 0, len(text), 0
    while i < n:
        m = BODY.match(text, i)
        if m and not in_protected(i, spans):
            cast, var = m.group(1), m.group(2)
            open_call = m.end() - 1  # mapsMemobjGetPhysicalAddress 的 '('
            close_call = match_delim(text, open_call, "(", ")")
            if close_call is not None:
                args = split_args(text[open_call + 1 : close_call])
                # 体内剩余: ; V ; }) )   (先闭语句表达式的 }, 再闭外层包裹 )
                tail = re.match(rf"\s*;\s*{re.escape(var)}\s*;\s*\}}\s*\)\s*\)", text[close_call + 1 :])
                if args and tail:
                    arg0 = args[0].strip()
                    if arg0:
                        out.append(f"{cast}({arg0})")
                        count += 1
                        i = close_call + 1 + tail.end()
                        continue
        out.append(text[i])
        i += 1
    return "".join(out), count


def main() -> None:
    dry_run = "--dry-run" in sys.argv[1:]
    total = 0
    for p in sorted(ROOT.joinpath("src").rglob("*.sc")):
        text = p.read_text()
        spans = protected_spans(text)
        new, count = transform_text(text, spans)
        if count:
            total += count
            if not dry_run:
                p.write_text(new)
            print(f"{p.relative_to(ROOT)}: {count} 处")
    print(f"\n共转换 {total} 处" + ("（dry-run，未写入）" if dry_run else ""))


if __name__ == "__main__":
    main()
