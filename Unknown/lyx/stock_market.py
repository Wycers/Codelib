'''
Welcome to Forma.ai stock statement generator! In this problem, you will be coding up a transaction
statement generator for a existing trader on our stock trading system. The inputs are provided below, and
the exact output you are to generate is provided after the inputs.

actions: the timestamped actions that the stock trader performed, it can be BUY or SELL type, and they can
buy or sell a few different stocks. However, you should assume that the number of ticker is not limited to
3 types as in the example below, but potentially infinite, so the ticker should not be hardcoded anywhere.

stock_actions: the timestamped actions that the stock performed regardless of who the trader is. It includes
stock splits, and dividend payouts. Even though these actions are not performed by our trader, it still affects
our trader's portfolios, so it should be recorded in the statement that we prepare.

We are looking for easy to understand/extend program that doesn't perform any unnecessary actions.

Feel free to extend the test cases to include new ones that exercises your program to the fullest.
'''

# input
import datetime as datetime

actions = [{'date': '1992/07/14 11:12:30', 'action': 'BUY', 'price': '12.3', 'ticker': 'AAPL', 'shares': '500'},
           {'date': '1992/09/13 11:15:20', 'action': 'SELL', 'price': '15.3', 'ticker': 'AAPL', 'shares': '100'},
           {'date': '1992/10/14 15:14:20', 'action': 'BUY', 'price': '20', 'ticker': 'MSFT', 'shares': '300'},
           {'date': '1992/10/17 16:14:30', 'action': 'SELL', 'price': '20.2', 'ticker': 'MSFT', 'shares': '200'},
           {'date': '1992/10/19 15:14:20', 'action': 'BUY', 'price': '21', 'ticker': 'MSFT', 'shares': '500'},
           {'date': '1992/10/23 16:14:30', 'action': 'SELL', 'price': '18.2', 'ticker': 'MSFT', 'shares': '600'},
           {'date': '1992/10/25 10:15:20', 'action': 'SELL', 'price': '20.3', 'ticker': 'AAPL', 'shares': '300'},
           {'date': '1992/10/25 16:12:10', 'action': 'BUY', 'price': '18.3', 'ticker': 'MSFT', 'shares': '500'}]
stock_actions = [{'date': '1992/08/14', 'dividend': '0.10', 'split': '', 'stock': 'AAPL'},
                 {'date': '1992/09/01', 'dividend': '', 'split': '3', 'stock': 'AAPL'},
                 {'date': '1992/10/15', 'dividend': '0.20', 'split': '', 'stock': 'MSFT'},
                 {'date': '1992/10/16', 'dividend': '0.20', 'split': '', 'stock': 'ABC'}]

# output:

"""
On 1992-07-14, you have:
    - 500 shares of AAPL at $12.30 per share
    - $0 of dividend income
  Transactions:
    - You bought 500 shares of AAPL at a price of $12.30 per share
On 1992-08-14, you have:
    - 500 shares of AAPL at $12.30 per share
    - $50.00 of dividend income
  Transactions:
    - AAPL paid out $0.10 dividend per share, and you have 500 shares
On 1992-09-01, you have:
    - 1500 shares of AAPL at $4.10 per share
    - $50.00 of dividend income
  Transactions:
    - AAPL split 3 to 1, and you have 1500 shares
On 1992-09-13, you have:
    - 1400 shares of AAPL at $4.10 per share
    - $50.00 of dividend income
  Transactions:
    - You sold 100 shares of AAPL at a price of $15.30 per share for a profit of $1120.00
On 1992-10-14, you have:
    - 1400 shares of AAPL at $4.10 per share
    - 300 shares of MSFT at $20.00 per share
    - $50.00 of dividend income
  Transactions:
    - You bought 300 shares of MSFT at a price of $20.00 per share
On 1992-10-15, you have:
    - 1400 shares of AAPL at $4.10 per share
    - 300 shares of MSFT at $20.00 per share
    - $110.00 of dividend income
  Transactions:
    - MSFT paid out $0.20 dividend per share, and you have 300 shares
On 1992-10-17, you have:
    - 1400 shares of AAPL at $4.10 per share
    - 100 shares of MSFT at $20.00 per share
    - $110.00 of dividend income
  Transactions:
    - You sold 200 shares of MSFT at a price of $20.20 per share for a profit of $40.00
On 1992-10-19, you have:
    - 1400 shares of AAPL at $4.10 per share
    - 600 shares of MSFT at $20.83 per share
    - $110.00 of dividend income
  Transactions:
    - You bought 500 shares of MSFT at a price of $21.00 per share
On 1992-10-23, you have:
    - 1400 shares of AAPL at $4.10 per share
    - $110.00 of dividend income
  Transactions:
    - You sold 600 shares of MSFT at a price of $18.20 per share for a loss of $-1580.00
On 1992-10-25, you have:
    - 1100 shares of AAPL at $4.10 per share
    - 500 shares of MSFT at $18.30 per share
    - $110.00 of dividend income
  Transactions:
    - You sold 300 shares of AAPL at a price of $20.30 per share for a profit of $4860.00
    - You bought 500 shares of MSFT at a price of $18.30 per share
"""


class Transaction(object):
    pass


class Split(Transaction):
    def __init__(self, name: str, split: float, amount: int):
        self.name = name
        self.split = split
        self.amount = amount

    def __str__(self):
        return "%s split %f to 1, and you have %d shares" % (self.name, self.split, self.amount)


class Dividend(Transaction):
    def __init__(self, name: str, dividend: float, amount: int):
        self.name = name
        self.dividend = dividend
        self.amount = amount

    def __str__(self):
        return "%s paid out $%.2f dividend per share, and you have %d shares" % (self.name, self.dividend, self.amount)


class Buy(Transaction):
    def __init__(self, name: str, amount: int, price: float):
        self.name = name
        self.amount = amount
        self.price = price

    def __str__(self):
        return "You bought %d shares of %s at a price of $%.2f per share" % (self.amount, self.name, self.price)


class Sell(Transaction):
    def __init__(self, name: str, amount: int, price: float, cost_price:float ):
        self.name = name
        self.amount = amount
        self.price = price
        self.profit = self.amount * (price - cost_price)

    def __str__(self):
        if self.profit < 0:
            return "You sold %d shares of %s at a price of $%.2f per share for a loss of $%.2f" % (
                self.amount, self.name, self.price, self.profit)
        else:
            return "You sold %d shares of %s at a price of $%.2f per share for a profit of $%.2f" % (
                self.amount, self.name, self.price, self.profit)


from datetime import datetime


def data_handler():
    global actions, stock_actions

    for action in actions:
        action['date'] = datetime.strptime(action['date'], '%Y/%m/%d %H:%M:%S')
    actions.sort(key=(lambda action: (action['date'].date(), action['action'])))

    for stock_action in stock_actions:
        stock_action['date'] = datetime.strptime(stock_action['date'], '%Y/%m/%d')
    actions.sort(key=(lambda action: action['date'].date()))


def ActionGenerator():
    global actions, stock_actions
    i, n = 0, len(actions)
    j, m = 0, len(stock_actions)

    while i < n and j < m:
        if actions[i]['date'].date() >= stock_actions[j]['date'].date():
            yield True, stock_actions[j]
            j += 1
        else:
            yield False, actions[i]
            i += 1
    while i < n:
        yield False, actions[i]
        i += 1
    while j < m:
        yield True, stock_actions[j]
        j += 1


my_shares = {}
my_costs = {}

stocks = {}
dividend_income = 0.0
transactions = []


def display(date: datetime):
    global my_shares, dividend_income, transactions
    if len(transactions) == 0:
        return

    print("On %s, you have:" % date.strftime("%Y-%m-%d"))
    for (key, value) in my_shares.items():
        print("    - %d shares of %s at $%.2f per share" % (value, key, my_costs[key] / my_shares[key]))
    print("    - $%.2f of dividend income" % dividend_income)
    print("Transactions:")
    for transaction in transactions:
        print("    - %s" % transaction)


if __name__ == '__main__':
    data_handler()

    # for action in actions:
    #     print(action)
    # for stock_action in stock_actions:
    #     print(stock_action)
    # print("==============")

    lastDate = None
    for isStock, action in ActionGenerator():
        if lastDate is not None and lastDate.date() != action['date'].date():
            # settle down
            display(lastDate)
            transactions = []
        # print()
        # print(action)
        lastDate = action['date']
        if isStock:
            stock = action['stock']
            if stock not in my_shares:
                continue

            split = action['split']
            dividend = action['dividend']

            if (split == '' and dividend == '') or (split != '' and dividend != ''):
                print("invalid action")
            else:
                if split == '':
                    dividend = float(dividend)

                    dividend_income += dividend * my_shares[stock]
                    transactions.append(Dividend(stock, dividend, my_shares[stock]))
                if dividend == '':
                    split = float(split)
                    my_shares[stock] *= split
                    transactions.append(Split(stock, split, my_shares[stock]))

        else:
            # print(action)
            ticker = action['ticker']
            amount = int(action['shares'])
            price = float(action['price'])
            if action['action'] == 'BUY':

                if ticker not in my_shares:
                    my_shares[ticker] = 0
                    my_costs[ticker] = 0
                my_shares[ticker] += amount
                my_costs[ticker] += amount * price

                stocks[ticker] = price
                transactions.append(Buy(ticker, amount, price))
            elif action['action'] == 'SELL':
                if ticker not in my_shares:
                    continue

                transactions.append(Sell(ticker, amount, price, my_costs[ticker] / my_shares[ticker]))
                my_costs[ticker] -= amount * my_costs[ticker] / my_shares[ticker]
                my_shares[ticker] -= amount

                if my_shares[ticker] == 0:
                    del my_shares[ticker]
                    del my_costs[ticker]
                stocks[ticker] = price
            else:
                print("invalid action")

    display(lastDate)