import emoji
import string

letters = list(string.ascii_letters)
digits = list(string.digits)
whitespace = [' ', '\n', '\t']

keyboard_symbols = list(string.punctuation)
extra_symbols = [
    '“', '”', '‘', '’', '–', '—', '…',
    '•', '·', '§', '¶', '©', '®', '™',
    '°', '±', '×', '÷', 'µ', 'Ω', '∞',
    '←', '→', '↑', '↓', '↔', '↕',
    '★', '☆', '✓', '✔', '✕', '✖', '✗', '✘',
    '☀', '☁', '☂', '☃', '☄', '♠', '♣', '♥', '♦',
    '⛔', '⚠', '⚡', '⏳', '⌛', '🔒', '🔓', '🔑', '🗝️'
]

all_emojis = list(emoji.EMOJI_DATA.keys())

base_tokens = letters + digits + whitespace + keyboard_symbols + extra_symbols + all_emojis

ase_tokens = list(dict.fromkeys(base_tokens))

vocab_path = "Tokenizer/vocab.txt"
with open(vocab_path, "w", encoding="utf-8") as f:
    for token in base_tokens:
        f.write(token + "\n")
