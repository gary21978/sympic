"""Exact function-section parsing for the frozen r61b integration."""
import re

ROOTS = (
    "_ZM31pushJ_vlo_K1_setup_weights_x0x1P19pushJ_weight_bank_tP17pushJ_vlo_state_tPdilPK11pushJ_ctx_t",
    "_ZM30pushJ_vlo_K2_push_weights_x2x3P19pushJ_weight_bank_tP17pushJ_vlo_state_tPKdS4_S4_PK11pushJ_ctx_ti",
    "_ZM39pushJ_vlo_K3_deposit_writeback_particlePK19pushJ_weight_bank_tP17pushJ_vlo_state_tPK11pushJ_ctx_tPDv8_dPdil",
)
IDENT = r"[A-Za-z_.$][A-Za-z0-9_.$]*"

def _code(text):
    """Mask comments without changing offsets or touching literal strings."""
    pattern = r'"(?:\\.|[^"\\])*"|/\*[\s\S]*?\*/|//[^\n]*'
    return re.sub(pattern, lambda m: m[0] if m[0].startswith('"') else
                  re.sub(r"[^\n]", " ", m[0]), text)


def _token(symbol):
    return re.compile(r"(?<![\w.$])" + re.escape(symbol) + r"(?![\w.$])")


def _labels(text):
    return re.findall(r"(?m)^[ \t]*(" + IDENT + r"):[ \t]*$", _code(text))


def _span(text, symbol):
    code = _code(text)
    escaped = re.escape(symbol)
    starts = list(re.finditer(r"(?m)^[ \t]*\.section[^\n]*" + escaped +
                              r"(?![A-Za-z0-9_$])[^\n]*\n", code))
    if len(starts) != 1:
        raise ValueError("expected one function section: " + symbol)
    start = starts[0].start()
    sizes = list(re.finditer(r"(?m)^[ \t]*\.size[ \t]+" + escaped +
                             r"[ \t]*,[^\n]*(?:\n|$)", code))
    if len(sizes) != 1 or sizes[0].start() < start:
        raise ValueError("expected one trailing .size: " + symbol)
    end = sizes[0].end()
    if len(re.findall(r"(?m)^[ \t]*\.section\b", code[start:end])) != 1:
        raise ValueError("function crosses another section: " + symbol)
    if _labels(text).count(symbol) != 1 or _labels(text[start:end]).count(symbol) != 1:
        raise ValueError("expected one entry label: " + symbol)
    return start, end


def _entry(text, symbol):
    match = re.search(r"(?m)^[ \t]*" + re.escape(symbol) + r":[ \t]*(?:\n|$)", _code(text))
    if match is None:
        raise ValueError("expected standalone function entry: " + symbol)
    return match
