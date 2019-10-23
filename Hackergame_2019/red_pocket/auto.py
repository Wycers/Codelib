from main import AI
import pychrome
import json
import queue

browser = pychrome.Browser(url="http://127.0.0.1:23333")
tab = browser.new_tab()

q = queue.Queue()

def request_will_be_sent(**kwargs):
    print("loading: %s" % kwargs.get('url'))

def webSocketFrameReceived(**kwargs):
    res = kwargs.get('response').get('payloadData')
    index = res.find('[')
    if index > -1:
        try:
            js = json.loads(res[index:])
            if js[0] != 'reply':
                return

            data = js[1]['data']

            flag = data.find('R0lGODlhCAEIAfZCAH') > -1
            data = data[:4]
            if data == '服务器给':
                return
            if data == '成功领取':
                print(res)
            q.put((data, flag))
        except Exception as e:
            pass

def response(data):
    custom_result = tab.Runtime.evaluate(
        expression="""$('#text').val('%s'); $('#emit').submit()""" % data,
        awaitPromise=True,
        timeout=1000
    )

tab.Network.webSocketFrameReceived = webSocketFrameReceived

# start the tab
tab.start()

# call method
tab.Network.enable()
# call method with timeout
tab.Page.navigate(url="http://202.38.73.168:8081/?token=865%3AMEQCIHcvwjFKzacxB6Khkrl6SX5cD%2FkMYLHohtDRoJM0LHI2AiBlXlH2x83wCZs7psm37UhVkjyaDXDOqI0NWbQT7%2Fxp7Q%3D%3D", _timeout=5)



# wait for loading
tab.wait(5)
custom_result = tab.Runtime.evaluate(
    expression="""""",
    awaitPromise=True,
    timeout=1000
)
ai = AI()
while True:
    u, flag = q.get(block=True)
    print("Server: %s" % u)
    if u == '成功领取':
        ai = AI()
        continue
    if u == '错误的拼':
        continue
    # print(flag)
    if flag:
        print(ai.query(u))
        break
    avaliable = ai.go(u)
    v = None
    for w in avaliable:
        if w.sg == 0:
            v = w
            break

    if v is None:
        for w in avaliable:
            if w.sg == 1:
                continue
            v = w
            break

    # print(avaliable)
    if v is None:
        print(ai.query(u))
        print("gg")
    else:
        print("Client: ", v)
        response(v.word)
        ai.go(v.word)


# close tab
# browser.close_tab(tab)
