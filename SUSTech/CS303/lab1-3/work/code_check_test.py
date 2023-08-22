#!/usr/bin/env python3
from code_check import CodeCheck


def main():
    code_checker = CodeCheck("mcts/index.py", 15)
    if not code_checker.check_code():
        print(code_checker.errormsg)
    else:
        print('pass')


if __name__ == '__main__':
    main()
