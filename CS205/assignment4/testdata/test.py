with open('test.txt', 'rb') as f:
    data = f.read()

for i in data:
    print(bin(i))
