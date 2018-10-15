#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string last = "";
    int cnt = 0;
    string encode(string longUrl) {
        last = longUrl;
        return "http://tinyurl.com/1";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return last;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));