//
// Created by Wycer on 2019/12/3.
//

#ifndef ASSIGNMENT5_UTF8STRING_H
#define ASSIGNMENT5_UTF8STRING_H

#include <string>

class UTF8string {
private:
    std::string origin;
public:
    UTF8string();
    UTF8string(const char* ptr);
    UTF8string(std::string str);
    unsigned int length();
    unsigned int bytes();
    unsigned int find(const char* ptr);
    unsigned int find(const std::string &str);
    void replace(UTF8string to_remove, UTF8string replacement);
};


#endif //ASSIGNMENT5_UTF8STRING_H
