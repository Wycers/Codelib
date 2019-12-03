//
// Created by Wycer on 2019/12/3.
//

#include "UTF8string.h"

UTF8string::UTF8string() {

}

UTF8string::UTF8string(const char *ptr) {
    origin = std::string(ptr);
}

UTF8string::UTF8string(std::string str) {
    origin = str;
}

unsigned int UTF8string::length() {
    return 0;
}

unsigned int UTF8string::bytes() {
    return origin.length();
}





