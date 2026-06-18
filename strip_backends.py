import re
import sys

def find_matching_brace(text, start):
    brace_count = 0
    found_open = False
    i = start
    in_line_comment = False
    in_block_comment = False
    while i < len(text):
        c = text[i]
        if in_line_comment:
            if c == '\n':
                in_line_comment = False
            i += 1
            continue
        if in_block_comment:
            if c == '*' and i + 1 < len(text) and text[i + 1] == '/':
                in_block_comment = False
                i += 2
                continue
            i += 1
            continue
        if c == '/' and i + 1 < len(text):
            if text[i + 1] == '/':
                in_line_comment = True
                i += 2
                continue
            if text[i + 1] == '*':
                in_block_comment = True
                i += 2
                continue
        if c == '{':
            brace_count += 1
            found_open = True
        elif c == '}':
            brace_count -= 1
            if found_open and brace_count == 0:
                return i
        i += 1
    return -1

def find_matching_paren(text, start):
    depth = 0
    i = start
    while i < len(text):
        if text[i] == '(':
            depth += 1
        elif text[i] == ')':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1

def skip_whitespace(text, pos):
    while pos < len(text) and text[pos] in ' \t\n\r':
        pos += 1
    return pos

def process_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()
    original = content

    # Step 1: Remove c_/openmp_ #include lines
    lines = content.split('\n')
    new_lines = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('#include "c_/') or stripped.startswith('#include "openmp_/'):
            continue
        if stripped == '#include "c_yeefdtd.h"' or stripped == '#include "openmp_yeefdtd.h"':
            continue
        new_lines.append(line)
    content = '\n'.join(new_lines)

    # Step 2: Delete c_* and openmp_* function implementations
    for prefix in ['c_', 'openmp_']:
        pattern = re.compile(r'^int ' + re.escape(prefix) + r'\w+\s*\(', re.MULTILINE)
        matches = list(pattern.finditer(content))
        for match in reversed(matches):
            func_start = match.start()
            brace_pos = content.find('{', func_start)
            if brace_pos == -1:
                continue
            func_end = find_matching_brace(content, brace_pos)
            if func_end == -1:
                print(f"WARNING: Could not find end of {prefix} function at line {content[:func_start].count(chr(10)) + 1}")
                continue
            line_start = content.rfind('\n', 0, func_start)
            if line_start == -1:
                line_start = 0
            content = content[:line_start] + content[func_end + 1:]

    # Step 3: Simplify blas_* dispatch functions that contain CD_type
    pattern = re.compile(r'^int (blas_\w+_Field3D_Seq)\s*\(', re.MULTILINE)
    matches = list(pattern.finditer(content))
    for match in reversed(matches):
        func_name = match.group(1)
        func_start = match.start()
        brace_pos = content.find('{', func_start)
        if brace_pos == -1:
            continue
        func_end = find_matching_brace(content, brace_pos)
        if func_end == -1:
            continue
        func_text = content[func_start:func_end + 1]
        if 'CD_type' not in func_text:
            continue

        paren_start = content.find('(', func_start)
        paren_end = find_matching_paren(content, paren_start)
        params = content[paren_start + 1:paren_end]

        cuda_func = 'cuda_' + func_name

        param_names = []
        for param in params.split(','):
            param = param.strip()
            if param:
                parts = param.split()
                if parts:
                    name = parts[-1].lstrip('*')
                    param_names.append(name)
        args = ', '.join(param_names)

        sig_text = content[func_start:brace_pos].rstrip()

        new_func = f'{sig_text} {{\n  return {cuda_func}({args});\n}}'
        content = content[:func_start] + new_func + content[func_end + 1:]

    # Step 4: Handle inline CD_type dispatch patterns in other functions
    def replace_ifelse_dispatch(content):
        changed = True
        while changed:
            changed = False
            pat = re.compile(
                r'if\s*\(\s*\(\s*0\s*==\s*CD_type\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*if\s*\(\s*\(\s*1\s*==\s*CD_type\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*if\s*\(\s*\(\s*2\s*==\s*CD_type\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*0;\s*'
                r'\}\s*\}\s*\}',
                re.DOTALL
            )
            match = pat.search(content)
            if match:
                cuda_block = match.group(3).strip()
                content = content[:match.start()] + cuda_block + content[match.end():]
                changed = True
        return content

    def replace_ifelse_dispatch_expr(content):
        changed = True
        while changed:
            changed = False
            pat = re.compile(
                r'if\s*\(\s*\(\s*0\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*if\s*\(\s*\(\s*1\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*if\s*\(\s*\(\s*2\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\{'
                r'([^{}]*?)'
                r'\}\s*else\s*\{'
                r'\s*0;\s*'
                r'\}\s*\}\s*\}',
                re.DOTALL
            )
            match = pat.search(content)
            if match:
                c_block = match.group(1).strip()
                openmp_block = match.group(2).strip()
                cuda_block = match.group(3).strip()
                if re.search(r'\bc_\w+', c_block) and re.search(r'\bopenmp_\w+', openmp_block):
                    content = content[:match.start()] + cuda_block + content[match.end():]
                    changed = True
        return content

    def replace_ifelse_num_dispatch(content):
        changed = True
        while changed:
            changed = False
            pat = re.compile(
                r'if\s*\(\s*\(\s*num\s*==\s*0\s*\)\s*\)\s*\{'
                r'\s*return\s+sizeof\(([^)]+)\);\s*'
                r'\}\s*else\s*\{\s*'
                r'if\s*\(\s*\(\s*num\s*==\s*1\s*\)\s*\)\s*\{'
                r'\s*return\s+sizeof\(([^)]+)\);\s*'
                r'\}\s*else\s*\{\s*'
                r'if\s*\(\s*\(\s*num\s*==\s*2\s*\)\s*\)\s*\{'
                r'\s*return\s+sizeof\(([^)]+)\);\s*'
                r'\}\s*else\s*\{\s*'
                r'return\s+0;\s*'
                r'\}\s*\}\s*\}',
                re.DOTALL
            )
            match = pat.search(content)
            if match:
                t1, t2, t3 = match.group(1).strip(), match.group(2).strip(), match.group(3).strip()
                if t1 == t2 == t3:
                    content = content[:match.start()] + 'return sizeof(' + t1 + ');' + content[match.end():]
                    changed = True
        return content

    def replace_ternary_dispatch(content):
        changed = True
        while changed:
            changed = False
            pat_start = re.compile(r'\(\s*\(\s*0\s*==\s*CD_type\s*\)\s*\)\s*\?')
            match = pat_start.search(content)
            if not match:
                continue
            start = match.start()
            pos = skip_whitespace(content, match.end())
            expr1_start = pos
            depth = 0
            while pos < len(content):
                c = content[pos]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos += 1
            expr1 = content[expr1_start:pos].strip()

            pos = skip_whitespace(content, pos + 1)

            pat1 = re.compile(r'\(\s*\(\s*1\s*==\s*CD_type\s*\)\s*\)\s*\?')
            m1 = pat1.match(content, pos)
            if not m1:
                continue
            pos = skip_whitespace(content, m1.end())
            expr2_start = pos
            depth = 0
            while pos < len(content):
                c = content[pos]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos += 1
            expr2 = content[expr2_start:pos].strip()

            pos = skip_whitespace(content, pos + 1)

            pat2 = re.compile(r'\(\s*\(\s*2\s*==\s*CD_type\s*\)\s*\)\s*\?')
            m2 = pat2.match(content, pos)
            if not m2:
                continue
            pos = skip_whitespace(content, m2.end())
            expr3_start = pos
            depth = 0
            pos2 = expr3_start
            while pos2 < len(content):
                c = content[pos2]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                    if depth < 0:
                        break
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos2 += 1
            expr3 = content[expr3_start:pos2].strip()

            total_depth = 0
            end_pos = len(content)
            for i in range(start, len(content)):
                c = content[i]
                if c == '(':
                    total_depth += 1
                elif c == ')':
                    total_depth -= 1
                    if total_depth == 0:
                        end_pos = i + 1
                        break

            content = content[:start] + expr3 + content[end_pos:]
            changed = True
        return content

    def replace_ternary_dispatch_expr(content):
        changed = True
        while changed:
            changed = False
            pat_start = re.compile(r'\(\s*\(\s*0\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\?')
            match = pat_start.search(content)
            if not match:
                continue
            start = match.start()
            rest = content[match.end():match.end()+500]
            if not re.search(r'\(\s*\(\s*1\s*==\s*[\w>.\-]+\s*\)\s*\)', rest):
                continue
            if not re.search(r'\(\s*\(\s*2\s*==\s*[\w>.\-]+\s*\)\s*\)', rest):
                continue

            pos = skip_whitespace(content, match.end())
            expr1_start = pos
            depth = 0
            while pos < len(content):
                c = content[pos]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos += 1
            expr1 = content[expr1_start:pos].strip()

            if not re.search(r'\bc_\w+', expr1):
                continue

            pos = skip_whitespace(content, pos + 1)

            pat1 = re.compile(r'\(\s*\(\s*1\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\?')
            m1 = pat1.match(content, pos)
            if not m1:
                continue
            pos = skip_whitespace(content, m1.end())
            expr2_start = pos
            depth = 0
            while pos < len(content):
                c = content[pos]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos += 1
            expr2 = content[expr2_start:pos].strip()

            if not re.search(r'\bopenmp_\w+', expr2):
                continue

            pos = skip_whitespace(content, pos + 1)

            pat2 = re.compile(r'\(\s*\(\s*2\s*==\s*[\w>.\-]+\s*\)\s*\)\s*\?')
            m2 = pat2.match(content, pos)
            if not m2:
                continue
            pos = skip_whitespace(content, m2.end())
            expr3_start = pos
            depth = 0
            pos2 = expr3_start
            while pos2 < len(content):
                c = content[pos2]
                if c == '(':
                    depth += 1
                elif c == ')':
                    depth -= 1
                    if depth < 0:
                        break
                elif c == ':' and depth == 0:
                    break
                elif c == '?' and depth == 0:
                    break
                pos2 += 1
            expr3 = content[expr3_start:pos2].strip()

            total_depth = 0
            end_pos = len(content)
            for i in range(start, len(content)):
                c = content[i]
                if c == '(':
                    total_depth += 1
                elif c == ')':
                    total_depth -= 1
                    if total_depth == 0:
                        end_pos = i + 1
                        break

            content = content[:start] + expr3 + content[end_pos:]
            changed = True
        return content

    content = replace_ifelse_dispatch(content)
    content = replace_ifelse_dispatch_expr(content)
    content = replace_ifelse_num_dispatch(content)
    content = replace_ternary_dispatch(content)
    content = replace_ternary_dispatch_expr(content)

    # Step 5: Replace remaining c_*/openmp_* function CALLS with cuda_* equivalents
    call_prefixes = [
        'pscmc', 'Yee', 'call', 'blas', 'split_pass', 'One_Particle',
        'delete', 'alloc', 'command', 'dump', 'calculate',
        'split_pass_x_scmc', 'split_pass_y_scmc', 'split_pass_z_scmc',
        'split_pass_x_abs_charge_scmc', 'split_pass_y_abs_charge_scmc', 'split_pass_z_abs_charge_scmc',
    ]
    for pfx in call_prefixes:
        content = re.sub(r'\bc_' + re.escape(pfx) + r'_(\w+)\(', r'cuda_' + pfx + r'_\1(', content)
        content = re.sub(r'\bopenmp_' + re.escape(pfx) + r'_(\w+)\(', r'cuda_' + pfx + r'_\1(', content)

    # Step 6: Replace c_*/openmp_* type references
    content = re.sub(r'\bc_pscmc_env\b', r'cuda_pscmc_env', content)
    content = re.sub(r'\bopenmp_pscmc_env\b', r'cuda_pscmc_env', content)
    content = re.sub(r'\bc_pscmc_mem\b', r'cuda_pscmc_mem', content)
    content = re.sub(r'\bopenmp_pscmc_mem\b', r'cuda_pscmc_mem', content)
    content = re.sub(r'\bc_(\w+_struct)\b', r'cuda_\1', content)
    content = re.sub(r'\bopenmp_(\w+_struct)\b', r'cuda_\1', content)

    # Step 7: Simplify unified ternary dispatch where all branches are now cuda_*
    # Pattern: (((0 == CD_type)) ? (X) : ((((1 == CD_type)) ? (X) : ((((2 == CD_type)) ? (X) : (0))))))
    def simplify_unified_ternary(content):
        changed = True
        while changed:
            changed = False
            pat = re.compile(r'\(\s*\(\s*0\s*==\s*[\w>.\-()]+\s*\)\s*\)\s*\?')
            match = pat.search(content)
            if not match:
                break
            inner_start = match.start()
            outer_start = inner_start
            while outer_start > 0 and content[outer_start - 1] in ' \t\n\r':
                outer_start -= 1
            if outer_start == 0 or content[outer_start - 1] != '(':
                break
            outer_start -= 1
            whole_end = find_matching_paren(content, outer_start)
            if whole_end == -1:
                break
            sub = content[outer_start:whole_end + 1]
            # Find the three ? that belong to 0/1/2 dispatch
            q_positions = []
            for m in re.finditer(r'\?', sub):
                # ensure this ? is preceded by a 0/1/2 condition at depth 1
                q_pos = m.start()
                # look back for pattern like (N == expr))
                back = sub[max(0, q_pos - 60):q_pos]
                if re.search(r'\(\s*\(\s*[012]\s*==\s*[\w>.\-()]+\s*\)\s*\)\s*$', back):
                    q_positions.append(q_pos)
            if len(q_positions) < 3:
                break

            def find_colon_after_question(s, q_pos):
                depth = 0
                for i in range(q_pos + 1, len(s)):
                    c = s[i]
                    if c == '(':
                        depth += 1
                    elif c == ')':
                        depth -= 1
                    elif c == ':' and depth == 0:
                        return i
                return -1

            colons = [find_colon_after_question(sub, q) for q in q_positions[:3]]
            if any(c == -1 for c in colons):
                break

            def strip_outer_parens(s):
                s = s.strip()
                while s.startswith('(') and s.endswith(')'):
                    inner = s[1:-1].strip()
                    if inner.count('(') == inner.count(')'):
                        s = inner
                    else:
                        break
                return s

            expr1 = strip_outer_parens(sub[q_positions[0] + 1:colons[0]])
            expr2 = strip_outer_parens(sub[q_positions[1] + 1:colons[1]])
            expr3 = strip_outer_parens(sub[q_positions[2] + 1:colons[2]])

            def normalize_expr(s):
                s = re.sub(r'\s+', ' ', s).strip()
                s = re.sub(r'\(\s+', '(', s)
                s = re.sub(r'\s+\)', ')', s)
                s = re.sub(r',\s+', ', ', s)
                return s

            if normalize_expr(expr1) == normalize_expr(expr2) == normalize_expr(expr3):
                content = content[:outer_start] + '(' + normalize_expr(expr1) + ')' + content[whole_end + 1:]
                changed = True
        return content

    content = simplify_unified_ternary(content)

    # Step 8: Remove CD_type variable declarations
    content = re.sub(r'\n\s*int CD_type = \(pthis\)->CD_type;\n', '\n', content)
    content = re.sub(r'\n\s*int CD_type = \(input_E\)->CD_type;\n', '\n', content)
    content = re.sub(r'\n\s*int CD_type = [^;]+;\n', '\n', content)

    # Step 9: Simplify redundant sizeof() ternary dispatch (all branches now identical after Step 6)
    # Pattern: malloc((((0 == CD_type)) ? (sizeof(cuda_X)) : ((((1 == CD_type)) ? (sizeof(cuda_X)) : ((((2 == CD_type)) ? (sizeof(cuda_X)) : (0)))))))
    # Simplify to: malloc(sizeof(cuda_X))
    def simplify_sizeof_ternary(content):
        pat = re.compile(r'malloc\(')
        result = []
        last_end = 0
        for m in pat.finditer(content):
            result.append(content[last_end:m.start()])
            malloc_start = m.start()
            paren_pos = m.end() - 1
            paren_end = find_matching_paren(content, paren_pos)
            if paren_end == -1:
                result.append(content[m.start():])
                last_end = len(content)
                break
            inner = content[m.end():paren_end]
            sizeof_pat = re.compile(r'sizeof\((\w+)\)')
            all_sizeofs = sizeof_pat.findall(inner)
            if len(all_sizeofs) == 3 and all_sizeofs[0] == all_sizeofs[1] == all_sizeofs[2] and '0 ==' in inner:
                result.append('malloc(sizeof(' + all_sizeofs[0] + '))')
            else:
                result.append(content[m.start():paren_end + 1])
            last_end = paren_end + 1
        result.append(content[last_end:])
        return ''.join(result)

    content = simplify_sizeof_ternary(content)

    # Step 10: Simplify redundant if-else dispatch where all branches are now identical
    def simplify_redundant_ifelse(content):
        changed = True
        while changed:
            changed = False
            pat = re.compile(
                r'if\s*\(\s*\(\s*num\s*==\s*0\s*\)\s*\)\s*\{'
                r'\s*return\s+([^;]+);\s*'
                r'\}\s*else\s*\{\s*'
                r'if\s*\(\s*\(\s*num\s*==\s*1\s*\)\s*\)\s*\{'
                r'\s*return\s+([^;]+);\s*'
                r'\}\s*else\s*\{\s*'
                r'if\s*\(\s*\(\s*num\s*==\s*2\s*\)\s*\)\s*\{'
                r'\s*return\s+([^;]+);\s*'
                r'\}\s*else\s*\{\s*'
                r'return\s+0;\s*'
                r'\}\s*\}\s*\}',
                re.DOTALL
            )
            match = pat.search(content)
            if match:
                expr1 = match.group(1).strip()
                expr2 = match.group(2).strip()
                expr3 = match.group(3).strip()
                if expr1 == expr2 == expr3:
                    content = content[:match.start()] + 'return ' + expr1 + ';' + content[match.end():]
                    changed = True
        return content

    content = simplify_redundant_ifelse(content)

    # Clean up multiple blank lines
    content = re.sub(r'\n{4,}', '\n\n\n', content)

    if content != original:
        with open(filepath, 'w') as f:
            f.write(content)
        orig_lines = original.count('\n')
        new_lines = content.count('\n')
        print(f"Modified: {filepath}")
        print(f"  Original: {orig_lines} lines {len(original)} chars")
        print(f"  New:      {new_lines} lines {len(content)} chars")
        print(f"  Removed:  {orig_lines - new_lines} lines ({100*(orig_lines-new_lines)//orig_lines if orig_lines else 0}%)")
    else:
        print(f"No changes: {filepath}")

def process_header_file(filepath):
    with open(filepath, 'r') as f:
        content = f.read()
    original = content

    lines = content.split('\n')
    new_lines = []
    skip_continuation = False
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()

        if skip_continuation:
            if stripped.endswith(';'):
                skip_continuation = False
            i += 1
            continue

        if re.match(r'^int\s+c_\w+\(', stripped) or re.match(r'^int\s+openmp_\w+\(', stripped) or \
           re.match(r'^void\s+c_\w+\(', stripped) or re.match(r'^void\s+openmp_\w+\(', stripped) or \
           re.match(r'^double\s+c_\w+\(', stripped) or re.match(r'^double\s+openmp_\w+\(', stripped) or \
           re.match(r'^long\s+c_\w+\(', stripped) or re.match(r'^long\s+openmp_\w+\(', stripped):
            if not stripped.endswith(';'):
                skip_continuation = True
            i += 1
            continue

        new_lines.append(line)
        i += 1

    content = '\n'.join(new_lines)

    # Clean up multiple blank lines
    content = re.sub(r'\n{4,}', '\n\n\n', content)

    if content != original:
        with open(filepath, 'w') as f:
            f.write(content)
        orig_lines = original.count('\n')
        new_lines = content.count('\n')
        print(f"Modified: {filepath}")
        print(f"  Original: {orig_lines} lines {len(original)} chars")
        print(f"  New:      {new_lines} lines {len(content)} chars")
        print(f"  Removed:  {orig_lines - new_lines} lines ({100*(orig_lines-new_lines)//orig_lines if orig_lines else 0}%)")
    else:
        print(f"No changes: {filepath}")

if __name__ == '__main__':
    for filepath in sys.argv[1:]:
        if filepath.endswith('.h'):
            process_header_file(filepath)
        else:
            process_file(filepath)