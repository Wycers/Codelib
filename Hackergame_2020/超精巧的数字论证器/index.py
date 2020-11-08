from multiprocessing import Process

segs = {}

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


def work(seg):
    print(f"working: {seg}")
    global segs

    set_ans(seg, seg)

    for i in range(1, len(seg)):

        left = seg[:i]
        right = seg[i:]
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


if __name__ == '__main__':
    str = "114514"
    for i in range(0, len(str)):
        for j in range(i, len(str)):
            segs[str[i:j + 1]] = 1

    for seg in segs:
        print(seg)

    for l in range(1, len(str) + 1):
        # print(l)

        threads = []

        for seg in segs:
            if len(seg) == l:
                import json
                from pathlib import Path

                path = Path(f"{seg}.json")
                res[seg] = {}
                if path.is_file():
                    with path.open() as f:
                        tmp = json.loads(f.read())
                    for k in tmp:
                        res[seg][int(k)] = tmp[k]
                else:
                    t = Process(target=work, args=(seg,))
                    threads.append(t)
                    t.start()

        # 等待所有线程任务结束。
        for t in threads:
            t.join()
        for seg in segs:
            if len(seg) == l:
                path = Path(f"{seg}.json")
                with path.open("w") as f:
                    f.write(json.dumps(res[seg]))
                print(f"{seg}: ", len(res[seg]))
                print("=================================")
    # print(str)
    print(len(res[str]))
