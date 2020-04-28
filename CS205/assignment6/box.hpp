#ifndef BOX_HPP
#define BOX_HPP

#include <ostream>

class Box {
private:
    int l, b, h;
public:
    Box() : l(0), b(0), h(0) {};

    Box(int l, int b, int h) : l(l), b(b), h(h) {};

    Box(const Box &box) : l(box.l), b(box.b), h(box.h) {};

    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() {
        return 1ll * l * b * h;
    }

    bool operator<(const Box &box) const {
        if (l == box.l) {
            if (b == box.b)
                return h < box.h;
            return b < box.b;
        }
        return l < box.l;
    }

    friend std::ostream &operator<<(std::ostream &os, const Box &box) {
        os << box.l << " " << box.b << " " << box.h;
        return os;
    }
};

#endif