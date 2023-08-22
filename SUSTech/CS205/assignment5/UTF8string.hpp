//
// Created by Wycer on 2019/12/3.
//

#ifndef ASSIGNMENT5_UTF8STRING_HPP
#define ASSIGNMENT5_UTF8STRING_HPP

#include <string>
#include "utf8.h"

class UTF8string {
private:
    std::string origin;
public:
    UTF8string();

    UTF8string(const char *ptr);

    UTF8string(std::string str);

    std::string string() const;

    friend std::ostream &operator<<(std::ostream &os, const UTF8string &u);

    unsigned int length();

    unsigned int bytes() const;

    unsigned int find(const char *ptr);

    unsigned int find(const std::string &str);

    void replace(UTF8string to_remove, UTF8string replacement);

    friend UTF8string operator+(const UTF8string &a, const UTF8string &b);

    friend UTF8string &operator+=(UTF8string &a, const UTF8string &b);

    friend UTF8string operator*(const UTF8string &a, const unsigned int &b);

    friend UTF8string operator*(const unsigned int &a, const UTF8string &b);

    friend UTF8string operator!(const UTF8string &a);
};


#endif //ASSIGNMENT5_UTF8STRING_HPP
