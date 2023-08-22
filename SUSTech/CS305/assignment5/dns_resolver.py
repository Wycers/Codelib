from socket import socket, AF_INET, SOCK_DGRAM
import time

SERVER_ADDR = '0.0.0.0'
SERVER_PORT = 5300

# Upsteam Address, use 114 DNS
UPSTREAM_ADDR = '114.114.114.114'
UPSTREAM_PORT = 53

# Duration to cleanup caches
CACHE_TTL = 1800

caches = []


# Query without EDNS
class SimplifiedQuery(object):
    def __init__(self, data):
        self.raw_data = list(data)

        self.header = self.raw_data[0: 12]
        # Refer to https://juejin.im/post/5ab719c151882577b45ef9d9
        # 标识字段，客户端会解析服务器返回的DNS应答报文，获取ID值与请求报文设置的ID值做比较，如果相同，则认为是同一个DNS会话。
        self.id = self.raw_data[0:2]

        # 2个字节(16bit)的标志字段。
        self.flags = self.raw_data[2:4]

        # 无符号16bit整数表示报文请求段中的问题记录数。
        self.qdcount = self.raw_data[4:6]

        # 无符号16bit整数表示报文回答段中的回答记录数。
        self.ancount = self.raw_data[6:8]

        # 无符号16bit整数表示报文授权段中的授权记录数。
        self.nscount = self.raw_data[8:10]

        # 无符号16bit整数表示报文附加段中的附加记录数。
        self.arcount = self.raw_data[10:12]

        # Bypass Header Section
        data = self.raw_data[12:]
        # QNAME ends with 0x00
        end_of_qname = data.index(0x00)

        # Whole question is from end of header to end of qclass
        self.question = data[:end_of_qname + 1 + 4]

        # QTYPE, QCLASS are the next 4 bytes
        self.qname = data[:end_of_qname + 1]
        self.qtype = data[end_of_qname + 1: end_of_qname + 1 + 2]
        self.qclass = data[end_of_qname + 1 + 2: end_of_qname + 1 + 4]

    def simple_data(self):
        tmp = self.header + self.question
        # Set arcount to 0
        tmp[11] = 0x0
        return bytes(tmp)


def from_bytes(data):
    return int.from_bytes(data, byteorder='big')

# DNS Answer Cache


class DNSRecord(SimplifiedQuery):
    def __init__(self, _query, _response):
        super().__init__(_response)
        self.query = _query
        self.time = time.time()
        self.ttl = []
        # Record Answer RR Counts
        count = from_bytes(bytes(self.arcount)) + \
            from_bytes(bytes(self.nscount))
        # Refer to https://juejin.im/post/5ab71be3f265da238d50acac
        # Bypass Header & Question Section
        pt = len(self.simple_data())
        rr_cnt = 0
        while rr_cnt < count:
            # Bypass NAME
            # Refer to https://blog.csdn.net/tianxuhong/article/details/74922454
            if self.raw_data[pt] & 0xc0 == 0xc0:
                # Pointer, 2 bytes
                pt += 2
            else:
                # Plain name, ends with 0x0
                while self.raw_data[pt] != 0x0:
                    pt += 1
                pt += 1
            # Bypass TYPE & CLASS
            pt += 4
            # Record the position and value of TTL
            self.ttl.append(
                [pt, from_bytes(bytes(self.raw_data[pt:(pt + 4)]))])
            pt += 4
            # Bypass RLENGTH and RDATA
            rlength = from_bytes(bytes(self.raw_data[pt:(pt + 2)]))
            pt += 2 + rlength
            rr_cnt += 1

    # Rewrite compare method to use list.index() for searching
    def __eq__(self, _query: SimplifiedQuery) -> bool:
        return self.query.question == _query.question

    def get_response(self, new_query) -> bytes:
        rr = self.raw_data
        # Use ID from new_query
        rr[0:2] = new_query.id

        # Check the TTL
        t_elapse = int(time.time() - self.time)
        for r_ttl in self.ttl:
            pt = r_ttl[0]
            new_ttl = r_ttl[1] - t_elapse
            if new_ttl <= 0:
                # Update the record from upstream
                self.__init__(self.query, query_upstream(self.query))
                return self.get_response(new_query)
            rr[pt:(pt + 4)] = int.to_bytes(new_ttl, length=4, byteorder='big')

        return bytes(rr)

    def revoked(self) -> bool:
        t_elapse = int(time.time() - self.time)
        for r_ttl in self.ttl:
            if r_ttl[1] <= t_elapse:
                return True
        return False


def query_upstream(_query) -> bytes:
    print("fetch from upstream")
    client_socket.sendto(_query.simple_data(), (UPSTREAM_ADDR, UPSTREAM_PORT))
    _response, _ = client_socket.recvfrom(2048)
    return _response


if __name__ == '__main__':
    t_start = time.time()
    server_socket = socket(AF_INET, SOCK_DGRAM)
    server_socket.bind((SERVER_ADDR, SERVER_PORT))
    print('The server is ready at {}:{}'.format(SERVER_ADDR, SERVER_PORT))

    client_socket = socket(AF_INET, SOCK_DGRAM)

    while True:
        # Cleanup outdated, unpopular cache
        if time.time() - t_start >= CACHE_TTL:
            for c in caches:
                if c.revoked():
                    caches.remove(c)
        message, client_address = server_socket.recvfrom(2048)
        query = SimplifiedQuery(message)
        try:
            cache = caches[caches.index(query)]
            # The query has already been cached
            response = cache.get_response(query)
        except ValueError:
            # No cached record matched, send query to the upstream server
            response = query_upstream(query)
            # Add the response to caches
            caches.append(DNSRecord(query, response))
        server_socket.sendto(response, client_address)
