if __name__ == '__main__':
    # print(ord("ß"))
    # Thanks to https://stackoverflow.com/questions/319426/how-do-i-do-a-case-insensitive-string-comparison
    # for i in range(0, 0x110000):
    #     ch = chr(i).upper()
    #     if "FLAG".find(ch) > -1:
    #         print(i, chr(i), ch)
    #         print("GG!!!!!!!!!!!!!!!!!!!!!!!!!!!!")

    # import re

    # r = re.compile('[fF][lL][aA][gG]')
    # for i in range(0, 0x110000):
    #     ch = chr(i).upper()
    #     try:
    #         s = ch.encode()
    #         if s.decode() != s.decode("utf-7"):
    #             print(s)
    #     except:
    #         pass
    # "flag"
    # 01100110 01101100 01100001 01100111
    # 011001 100110 110001 100001 011001 110000

    # 00000000 01100110
    # 000000 000110 011000
    # AGY

    print(b"+AGY-lag".decode("utf-7"))
