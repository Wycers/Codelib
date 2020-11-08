import json
from multiprocessing import Process
from pathlib import Path

res = {}


def raw_set(seg, exp, val):
    if val in res[seg]:
        if len(exp) >= len(res[seg][val]):
            return
    res[seg][val] = exp


def set(seg, exp):
    val = int(eval(exp))
    # print(exp, val)
    raw_set(seg, exp, val)


def set_ans(seg, exp):
    set(seg, f"({exp})")
    set(seg, f"(-({exp}))")
    set(seg, f"(~({exp}))")

    tmp = f"({exp})"
    while len(tmp) < 32:
        tmp = f"~-{tmp}"
        set(seg, tmp)

    tmp = f"({exp})"
    while len(tmp) < 32:
        tmp = f"-~{tmp}"
        set(seg, tmp)


def readin(seg):
    path = Path(f"{seg}.json")
    if path.is_file():
        with path.open() as f:
            tmp = json.loads(f.read())
        res[seg] = {}
        for k in tmp:
            res[seg][int(k)] = tmp[k]
        return True
    return False


def work(seg):
    print(f"working: {seg}")

    if readin(seg):
        return

    res[seg] = {}
    set_ans(seg, seg)

    for i in range(1, len(seg)):
        left = seg[:i]
        right = seg[i:]
        if left not in res:
            readin(left)
        if right not in res:
            readin(right)

        for l in res[left]:
            for r in res[right]:
                for ch in ["+", "-", "*", "&", "|", "^"]:
                    exp = "(%s)%s(%s)" % (res[left][l], ch, res[right][r])
                    # print(exp)
                    set_ans(seg, exp)
                if r != 0:
                    for ch in ["//", "%"]:
                        exp = "(%s)%s(%s)" % (res[left][l], ch, res[right][r])
                        # print(exp)
                        set_ans(seg, exp)

    path = Path(f"{seg}.json")
    with path.open("w") as f:
        f.write(json.dumps(res[seg]))
    print(f"{seg}: ", len(res[seg]))
    print("=================================")


if __name__ == '__main__':
    STR = "114514"

    for l in range(1, len(STR) + 1):
        processes = []
        for i in range(0, len(STR) - l + 1):
            p = Process(target=work, args=(STR[i:i + l],))
            processes.append(p)
            p.start()

        for p in processes:
            p.join()
