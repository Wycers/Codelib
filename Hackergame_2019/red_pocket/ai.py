from queue import Queue
import json

wc = {}


class Node():
    def __init__(self, word, u, v):
        self.word = word
        self.u = u
        self.v = v
        self.next = []
        self.sg = None

    def push_front(self, word):
        self.pre.append(word)

    def push_back(self, word):
        self.next.append(word)

    def cal_sg(self):
        if self.sg is not None and self.sg == 1:
            return False
        if len(self.next) == 0:
            self.sg = 0
            return True
        for i in self.next:
            if i.sg == 0:
                self.sg = 1
                return True

        for i in self.next:
            if i.sg is None:
                return False
        self.sg = 0
        print('=>', self.word)
        return True

    def __str__(self):
        if self.sg is None:
            return '%s' % self.word
        else:
            return '%s %d' % (self.word, self.sg)

    def __repr__(self):
        if self.sg is None:
            return '%s' % self.word
        else:
            return '%s %d' % (self.word, self.sg)


class AI():
    def __init__(self):
        # Read in
        with open('idl.json', 'rb') as load_f:
            words = json.load(load_f)
            for word in words:
                wc[word] = Node(word=word, u=words[word]['first'], v=words[word]['last'])

        self.word_starts_with = {}
        for w in wc:
            if wc[w].u in self.word_starts_with:
                self.word_starts_with[wc[w].u].append(wc[w])
            else:
                self.word_starts_with[wc[w].u] = [wc[w]]

        self.word_ends_with = {}
        for w in wc:
            if wc[w].v in self.word_ends_with:
                self.word_ends_with[wc[w].v].append(wc[w])
            else:
                self.word_ends_with[wc[w].v] = [wc[w]]

        for w in wc:
            if wc[w].v in self.word_starts_with:
                for g in self.word_starts_with[wc[w].v]:
                    if g.word == w:
                        continue
                    wc[w].push_back(g)

        self.done = []
        self.greedy()

    def greedy(self):
        last = len(self.done)
        while len(self.done) != len(wc):
            for w in wc:
                if w in self.done:
                    continue
                if wc[w].cal_sg():
                    self.done.append(w)

            if len(self.done) == last:
                break
            last = len(self.done)


    def greedy2(self, first):
        q = Queue()
        q.put(first)
        inq = {}
        inq[first] = True

        while not q.empty():
            first = q.get()
            if first in self.word_ends_with:
                for w in self.word_ends_with[first]:
                    if not w.sg is None:
                        continue
                    if w.cal_sg():
                        if w.u in inq and inq[w.u]:
                            continue
                        q.put(w.u)
                        inq[w.u] = True
                        self.done.append(w)
            inq[first] = False


    def go(self, input_word):
        node = wc[input_word]
        if node.sg is None:
            node.sg = 1
            self.done.append(input_word)
            self.greedy2(node.u)
        return node.next

    def query(self, input_word):
        node = wc[input_word]
        print(node.sg)
        print(node.next)


if __name__ == '__main__':
    ai = AI()
