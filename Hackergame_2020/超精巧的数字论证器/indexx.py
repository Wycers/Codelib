segs = {}

res = {}


def set_ans(seg, exp):
    res[seg].append(exp)
    res[seg].append("-(" + exp + ")")
    res[seg].append("~(" + exp + ")")


def work(seg):
    global segs

    set_ans(seg, seg)

    for i in range(1, len(seg)):

        left = seg[:i]
        right = seg[i:]
        for l in res[left]:
            for r in res[right]:
                for ch in ["+", "-", "*", "&", "|", "^"]:
                    exp = "(%s)%s(%s)" % (l, ch, r)
                    if seg == "514":
                        print(exp)
                    set_ans(seg, exp)
                if r != 0:
                    for ch in ["//", "%"]:
                        exp = "(%s)%s(%s)" % (l, ch, r)
                        if seg == "514":
                            print(exp)
                        set_ans(seg, exp)


if __name__ == '__main__':
    str = "114514"
    for i in range(0, len(str)):
        for j in range(i, len(str)):
            segs[str[i:j + 1]] = 1

    for seg in segs:
        print(seg)

    for l in range(1, 4):
        for seg in segs:
            if len(seg) == l:
                res[seg] = []
                work(seg)
                print("===========================")
                # print(res[seg])
    # print(len(res["114514"]))
    print(res["451"])
    print(len(res["451"]))
