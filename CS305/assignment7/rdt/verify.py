from rdt import datagram

test = datagram()
test.dtype = 0
test.seq = 1
test.seq_ack = 2
test.payload = b'wdnmd'

print(test)
print("=============")
gg = test()
print(datagram(gg))
