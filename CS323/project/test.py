from pathlib import Path
import os

test_path = Path("./test")

for file in test_path.rglob("*.spl"):
    print(file.resolve())
    tmp_out_path = Path("/tmp/{file.stem}_tmp.out")
    std_out_path = test_path / (file.stem + ".out")

    os.system(f"./bin/splc {file.resolve()} > {tmp_out_path.resolve()}")

    if os.system(f"diff -Z {std_out_path} {tmp_out_path.resolve()}") != 0:
        print("You:", tmp_out_path.open().read())
        print("Std:", std_out_path.open().read())
        print("!")
        input()
    else:
        print("OK")
