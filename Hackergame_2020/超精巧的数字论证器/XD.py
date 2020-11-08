
from functools import reduce


class Expression():
    maxValue = 1000000
    operators = ['*', '+', '-']
    priority = {
        '!': 1,
        # '**': 2,
        '*': 3,
        '+': 4,
        '-': 4
    }
    operation = {
        # '**': lambda a, b: a ** b,
        '*': lambda a, b: a * b,
        '-': lambda a, b: a - b,
        '+': lambda a, b: a + b,
        '!': lambda n: ~n # reduce(lambda x, y: x * y, range(1, n + 1), 1)
    }

    def __init__(self, value=0, exp='', priority=0):
        self.value = value
        self.exp = exp
        self.priority = priority


class Node():
    def __init__(self):
        self.expressions = {}

    def add_child(self, lnode, rnode):
        for lval, lexp in lnode.expressions.items():
            for rval, rexp in rnode.expressions.items():
                for opt in Expression.operators:
                    lstr = lexp.exp
                    rstr = rexp.exp
                    if rexp.value < 0 and opt == '**':
                        continue
                    optResult = Expression.operation[opt](
                        lval, rval)
                    if optResult > Expression.maxValue:
                        continue

                    if lexp.priority > Expression.priority[opt]:
                        lstr = '(' + lstr + ')'
                    if rexp.priority > Expression.priority[opt]:
                        rstr = '(' + rstr + ')'
                    # 不支持结合律
                    if (opt == '-' or opt == '**') and Expression.priority[opt] == rexp.priority:
                        rstr = '(' + rstr + ')'

                    self.expressions[optResult] = Expression(optResult, lstr + opt +
                                                             rstr, Expression.priority[opt])
                    if optResult <= 5:
                        val = Expression.operation['!'](optResult)
                        s = lstr + opt + rstr
                        if Expression.priority[opt] > Expression.priority['!']:
                            s = '(' + s + ')'
                        self.expressions[val] = Expression(
                            val, s + '!', Expression.priority['!'])

    def add_expression(self, expression):
        self.expressions[expression.value] = expression


class SuujiRonshou():
    def __init__(self, digits="114514"):
        self.digits = digits
        self.generate()

    def generate(self):
        visitedNode = {}

        def dfs(l, r):
            if (l, r) in visitedNode:
                return visitedNode[(l, r)]
            elif l > r:
                return None
            elif (l == r):
                d = self.digits[l]
                root = Node()
                root.add_expression(Expression(int(d), d, 0))
                if l == 0:  # 第一个数可以为负数
                    root.add_expression(Expression(-int(d), '-' + d, 0))
                visitedNode[(l, r)] = root
                return root
            else:
                root = Node()
                for mid in range(l, r):

                    lnode = dfs(l, mid)
                    rnode = dfs(mid + 1, r)
                    root.add_child(lnode, rnode)

                visitedNode[(l, r)] = root
                return root

        node = dfs(0, len(self.digits) - 1)
        self.expressions = node.expressions

    def print_all(self, l, r):
        for i in range(l, r):
            if self.find(i) == "None":
                continue
            print(i, self.find(i))

    def find(self, target):
        if target not in self.expressions:
            return "None"
        else:
            return self.expressions[target].exp


if __name__ == "__main__":
    solver = SuujiRonshou()
    solver.print_all(1, 114514 + 1)