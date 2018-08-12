import requests, time

session = requests.session()
session.get("https://moar_horse.tjctf.org/")

while (True):
    content = session.get("https://moar_horse.tjctf.org/legs").content.decode()
    if content.find("tjctf") != -1:
        print(content)
        break