#!/usr/bin/env python3
import argparse
import re
import sys
from pathlib import Path


PAIR_RE = re.compile(r"([A-Za-z0-9_]+)=([-+0-9.eE]+)")


def parse_pairs(line):
    return {k: float(v) for k, v in PAIR_RE.findall(line)}


def avg(values):
    return sum(values) / len(values) if values else 0.0


def parse_log(path, skip_step0=True):
    steps = {}
    sort = {}
    with open(path, "r", errors="replace") as f:
        for line in f:
            if "PROFILE_STEP" in line:
                vals = parse_pairs(line)
                step = int(vals.get("step", -1))
                if step >= 0:
                    steps[step] = vals
            elif "PROFILE_SORT" in line:
                vals = parse_pairs(line)
                step = int(vals.get("step", -1))
                if step >= 0:
                    sort[step] = vals

    selected = []
    for step in sorted(steps):
        if skip_step0 and step == 0:
            continue
        row = dict(steps[step])
        srow = sort.get(step, {})
        particle_total = row.get("particle_sort", 0.0)
        local_sort = srow.get("local_sort_compute", 0.0)
        particle_comm = srow.get("particle_sort_comm", particle_total)
        host_roundtrip = srow.get("host_roundtrip", 0.0)
        push_deposit = row.get("push_deposit", 0.0)
        total = row.get("total", 0.0)
        field_sync = total - push_deposit - local_sort - particle_comm - host_roundtrip
        selected.append(
            {
                "step": step,
                "total": total,
                "push_deposit": push_deposit,
                "local_sort_compute": local_sort,
                "particle_sort_comm": particle_comm,
                "host_roundtrip": host_roundtrip,
                "field_sync_comm": field_sync,
                "particle_sort_total": particle_total,
            }
        )
    return selected


def print_report(path, rows):
    print(f"log={path}")
    if not rows:
        print("  no PROFILE_STEP rows found")
        return

    keys = [
        "field_sync_comm",
        "particle_sort_comm",
        "host_roundtrip",
        "push_deposit",
        "local_sort_compute",
        "total",
    ]
    avgs = {k: avg([r[k] for r in rows]) for k in keys}
    balance = (
        avgs["field_sync_comm"]
        + avgs["particle_sort_comm"]
        + avgs["host_roundtrip"]
        + avgs["push_deposit"]
        + avgs["local_sort_compute"]
    )
    print(f"  steps={len(rows)} range={rows[0]['step']}..{rows[-1]['step']} avg_ms")
    print(f"  COMM field_sync      {avgs['field_sync_comm'] * 1000.0:10.3f}")
    print(f"  COMM particle_sort   {avgs['particle_sort_comm'] * 1000.0:10.3f}")
    print(f"  COMM host_roundtrip  {avgs['host_roundtrip'] * 1000.0:10.3f}")
    print(f"  COMP push_deposit    {avgs['push_deposit'] * 1000.0:10.3f}")
    print(f"  COMP local_sort      {avgs['local_sort_compute'] * 1000.0:10.3f}")
    print(f"  TOTAL                {avgs['total'] * 1000.0:10.3f}")
    print(f"  BALANCE              {balance * 1000.0:10.3f} diff={(avgs['total'] - balance) * 1000.0:+.6f} ms")


def print_csv(path, rows):
    if not rows:
        return
    keys = ["field_sync_comm", "particle_sort_comm", "host_roundtrip", "push_deposit", "local_sort_compute", "total"]
    avgs = {k: avg([r[k] for r in rows]) * 1000.0 for k in keys}
    print(",".join(["log", "steps", "first_step", "last_step"] + keys))
    print(",".join([str(path), str(len(rows)), str(rows[0]["step"]), str(rows[-1]["step"])] + [f"{avgs[k]:.6f}" for k in keys]))


def main(argv):
    ap = argparse.ArgumentParser(description="Parse SymPIC PROFILE_STEP/PROFILE_SORT logs into five profiling buckets.")
    ap.add_argument("logs", nargs="+", type=Path)
    ap.add_argument("--include-step0", action="store_true")
    ap.add_argument("--csv", action="store_true")
    args = ap.parse_args(argv)

    for i, path in enumerate(args.logs):
        rows = parse_log(path, skip_step0=not args.include_step0)
        if args.csv:
            print_csv(path, rows)
        else:
            if i:
                print()
            print_report(path, rows)


if __name__ == "__main__":
    main(sys.argv[1:])
