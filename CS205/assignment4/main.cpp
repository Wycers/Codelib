#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <regex>
#include "utf8.h"

using namespace std;
const int MAX_ARR = 305;

void _Warning(int x) {
    //TODO: illegal input
    cout << "illegal!" << endl;
}

int check_s(string &s) {
    int l = s.length(), r = -1;

    for (int i = 0; i < s.length(); ++i)
        if (s[i] != ' ') {
            l = i;
            break;
        }
    if (l >= s.length())
        return 0;

    for (int i = s.length() - 1; i >= 0; i--)
        if (s[i] != ' ') {
            r = i;
            break;
        }

    if (r < 0)
        return 0;
    if (r < l)
        return 0;

    string str;
    for (int i = l; i <= r; i++)
        str += s[i];
    s = str;
    return 1;
}

int hex2dec(string s) {
    int x = 0;
    for (const char &i : s) {
        if ('0' <= i && i <= '9')
            x = x * 16 + (i - '0');
        else if (i >= 'A' && i <= 'F')
            x = x * 16 + 10 + (i - 'A');
    }
    return x;
}

struct block {
    string name;
    int startpoint = 0, endpoint = 0, cnt = 0;

    block() {}

    void from(const string &str) {
        regex ip_reg("^(.*)\\.\\.(.*);\\s+(.*)$");
        smatch matchResult;

        if (std::regex_match(str, matchResult, ip_reg)) {
            startpoint = hex2dec(matchResult[1]);
            endpoint = hex2dec(matchResult[2]);
            name = matchResult[3];

        } else {
            cout << "Not Match!";
        }
    }

    bool match(const int c) {
        //TODO: block contains the number or not
        return startpoint <= c && c <= endpoint;
    }

    void inc() {
        ++cnt;
    }
} blocks[MAX_ARR];

inline bool cmp(const block &a, const block &b) {
    return a.cnt > b.cnt;
}

const int BUFFER_SIZE = 3;
char buffer[BUFFER_SIZE];
void start_your_performance() {
    freopen("testdata/sample6.txt","r", stdin);
    while(fgets(buffer, BUFFER_SIZE, stdin))
    {
        unsigned char *ptr = (unsigned char *)buffer;
        while (*ptr != '\0')
        {
            unsigned int res = 0, cnt = 0;
            if ((0b11111000 & *ptr) == 0b11110000) {
                res = *ptr & 0b00000111;
                cnt = 3;
            }
            else if ((0b11110000 & *ptr) == 0b11100000) {
                res = *ptr & 0b00001111;
                cnt = 2;
            }
            else if ((0b11100000 & *ptr) == 0b11000000) {
                res = *ptr & 0b00011111;
                cnt = 1;
            } else {
                res = *ptr & 0b01111111;
                cnt = 0;
            }
            ++ptr;
            for (int i = 0; i < cnt; ++i) {
                if (*ptr == '\0') {
                    fgets(buffer, BUFFER_SIZE, stdin);
                    ptr = (unsigned char *)buffer;
                }
                res <<= 6;
                res |= *(ptr++) & 0b00111111;
            }
            for (block &bk: blocks) {
                if (bk.match(res)) {
                    bk.inc();
                    break;
                }
            }
        }
    }
    int mx = blocks[0].cnt;
    string ans = blocks[0].name;
    for (const block &bk: blocks) {
        if (bk.cnt > mx) {
            mx = bk.cnt;
            ans = bk.name;
        }
    }
    cout << ans << endl;
}


int main() {
    ifstream file;
    file.open("Blocks.txt");
    if (!file) {
        //file open failed
        _Warning(2);
        return 0;
    }
    string str;
    int cnt = 0;
    while (getline(file, str)) {
        if (check_s(str) == 0) str = "";
        if (str.empty() || str[0] == '#')
            continue;
        blocks[cnt++].from(str);
    }
    file.close();
    start_your_performance();
    return 0;
}