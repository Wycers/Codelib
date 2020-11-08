from pathlib import Path

import websocket

res = {}

try:
    import thread
except ImportError:
    import _thread as thread


def on_message(ws, message: str):
    print(message)
    print("====")
    if message == "Please input your token: ":
        ws.send(
            "1716:MEUCIAj3vUnhyiI2u58LzU4HZehjHjIKg+dco+tBBcoLLYV0AiEAi60mhNWJbHPboMIOnoGVm0EfBVDSbKygjKl+TMTS1rM=\n")
    elif message.find("Challenge") > -1:
        num = message[message.index(":") + 1:-2]
        xd = int(num)
        if "114514" in res and xd in res["114514"]:
            ans = res["114514"][xd].replace("//", "/")
            print(ans)
            ws.send(ans + "\n")
        elif "14514" in res and xd in res["14514"]:
            ans = res["14514"][xd].replace("//", "/")
            ans = f"1*({ans})"
            print(ans)
            ws.send(ans + "\n")
        else:
            print("gg")
            ws.close()


def on_error(ws, error):
    print(error)


def on_close(ws):
    print("### closed ###")


def on_open(ws):
    pass


import json

if __name__ == '__main__':
    STR = "114514"

    for seg in ["14514", "114514"]:
        path = Path(f"{seg}.json")
        if path.is_file():
            with path.open() as f:
                tmp = json.loads(f.read())
            res[seg] = {}
            for k in tmp:
                res[seg][int(k)] = tmp[k]

    # while True:
    #     xd = int(input())
    #     for seg in res:
    #         if xd in res[seg]:
    #             print(f"{seg}: {res[seg][xd].replace('//', '/')}")

    websocket.enableTrace(True)
    ws = websocket.WebSocketApp("ws://202.38.93.111:10240/shell",
                                on_message=on_message,
                                on_error=on_error,
                                on_close=on_close)
    ws.on_open = on_open
    ws.run_forever()
