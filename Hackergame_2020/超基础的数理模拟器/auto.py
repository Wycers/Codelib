import http.cookiejar
from math import *

import requests
from scipy import integrate

s = requests.Session()
from requests_html import HTMLSession

sqrt(1)
session = HTMLSession()
session.cookies = http.cookiejar.MozillaCookieJar("anything.txt")
mn, mx = 0, 0


def int_(x):
    def wrapper(a, b=x):
        global mn, mx
        mn = b
        mx = a
        return 0

    return wrapper


def frac(x):
    def wrapper(a, b=x):
        return b / a

    return wrapper


def f_(st):
    def wrapper(a, b=st):
        x = a
        return eval(b)

    return wrapper


if __name__ == '__main__':

    res = session.get(
        "http://202.38.93.111:10190/login?token=1716%3AMEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg%2Bdco%2BtBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl%2BTMTS1rM%3D")
    total = 0
    while True:
        total += 1
        center = res.html.find('center', first=False)
        p = center[0].find("p")
        txt = p[0].text
        # print(txt)

        txt = txt.replace(" ", "")

        txt = txt.replace("\\left", "")
        txt = txt.replace("\\right", "")

        txt = txt.replace("\\,", "*")

        txt = txt.replace("\\sqrt", "sqrt")

        txt = txt.replace("{", "(")
        txt = txt.replace("}", ")")

        txt = txt.replace("e^", "exp")

        txt = txt.replace("\\ln", "log")

        txt = txt.replace("\\sin", "sin")
        txt = txt.replace("\\cos", "cos")
        txt = txt.replace("\\tan", "tan")

        txt = txt.replace("\\arcsin", "asin")
        txt = txt.replace("\\arccos", "acos")
        txt = txt.replace("\\arctan", "atan")

        txt = txt.replace("\\frac", "frac")

        txt = txt.replace("\\int_", "int_")
        txt = txt.replace("^", "", 1)

        txt = txt.replace("^", "**")
        txt = txt[1:-6]

        cnt = 0
        seg = 0
        for i in range(0, len(txt)):
            if txt[i] == "(":
                cnt += 1
            if txt[i] == ")":
                cnt -= 1
                if cnt == 0:
                    seg += 1
                if seg == 2:
                    txt1 = txt[:i + 1]
                    txt2 = txt[i + 1:]
                    break

        eval(txt1)
        # print(txt1, mn, mx)

        # cnt = 0
        # in_frac = False
        # i = 0
        # while i < len(txt2):
        #     if txt2[i: i + 4] == "frac":
        #         in_frac == True
        #
        #     if txt2[i] == "(":
        #         cnt += 1
        #     if txt2[i] == ")":
        #         cnt -= 1
        #         if cnt == 0:
        #             seg += 1
        #         if seg == 2:
        #             txt1 = txt2[:i + 1]
        #             txt2 = txt2[i + 1:]
        #             break

        # print(txt2)

        try:
            # print("xd")
            # xd = input()
            res, err = integrate.quad(f_(txt2), mn, mx)
            print(mn, mx, res)
            res = session.post("http://202.38.93.111:10190/submit", data={
                "ans": "%f" % res
            })
            print("success!!", total)
            print(res.content)
        except Exception as e:
            res = session.post("http://202.38.93.111:10190/submit", data={
                "ans": "2.33333333"
            })

