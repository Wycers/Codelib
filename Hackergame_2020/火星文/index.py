from pathlib import Path

p = Path("gibberish_message.txt")
with p.open(encoding="utf-8") as f:
    txt = f.read()
    print(txt.encode("gbk").decode("utf-8").encode("latin1").decode("gbk"))
