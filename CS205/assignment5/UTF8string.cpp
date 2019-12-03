//
// Created by Wycer on 2019/12/3.
//

#include "UTF8string.hpp"
#include "utf8.h"
#include "string.h"
#include "stack"

UTF8string::UTF8string() {

}


UTF8string::UTF8string(const char *ptr) {
    origin = std::string(ptr);
}

UTF8string::UTF8string(std::string str) {
    origin = str;
}


unsigned int UTF8string::length() {
    return utf8_charlen((unsigned char *) origin.c_str());
}

unsigned int UTF8string::bytes() const {
    return origin.length();
}

unsigned int UTF8string::find(const char *sub) {
    unsigned char *ptr = utf8_search((unsigned char *) origin.c_str(), (unsigned char *) sub);
    if (ptr == NULL)
        return -1;
    char tmp = *ptr;
    *ptr = '\0';
    unsigned int res = utf8_charlen((unsigned char *) origin.c_str());
    *ptr = tmp;
    return res;
}

unsigned int UTF8string::find(const std::string &str) {
    return find(str.c_str());
}

void UTF8string::replace(UTF8string to_remove, UTF8string replacement) {
    // From StackoverFlow
    if (to_remove.origin.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = origin.find(to_remove.origin, start_pos)) != std::string::npos) {
        origin.replace(start_pos, to_remove.origin.length(), replacement.origin);
        start_pos += replacement.origin.length();
    }
}

std::string UTF8string::string() const {
    return this->origin;
}


std::ostream &operator<<(std::ostream &os, const UTF8string &u) {
    os << u.string();
    return os;
}

UTF8string operator+(const UTF8string &u1, const UTF8string &u2) {
    return UTF8string(u1.origin + u2.origin);
}

UTF8string &operator+=(UTF8string &a, const UTF8string &b) {
    a.origin += b.origin;
    return a;
}

UTF8string operator*(const UTF8string &a, const unsigned int &b) {
    UTF8string res;
    std::string tmp = a.origin;
    for (unsigned int i = 1; i <= b; i <<= 1, tmp += tmp)
        if (b & i)
            res.origin += tmp;
    return res;
}

UTF8string operator*(const unsigned int &a, const UTF8string &b) {
    return b * a;
}

UTF8string operator!(const UTF8string &a) {
    std::stack<unsigned int> st;
    while (!st.empty())
        st.pop();

    unsigned int str_bytes = a.bytes();
    unsigned char *ptr = (unsigned char *) a.origin.c_str();
    unsigned char *end = (unsigned char *)(a.origin.c_str() + str_bytes);
    int tmp = 0;
    UTF8string res;

    while (ptr < end)
    {
        utf8_to_codepoint(ptr, &tmp);
        st.push(tmp);
        ptr += tmp;
    }

    while (!st.empty())
    {
        int len = st.top();
        str_bytes -= len;
        res.origin += a.origin.substr(str_bytes, len);
        st.pop();
    }
    return res;
}
