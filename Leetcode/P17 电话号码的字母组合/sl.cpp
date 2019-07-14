/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
// #include <bits/stdc++.h>
// using namespace std;
class Solution {
public:
    vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void work(string &digits, int now, string res)
    {
        // cout << digits << " " << now << endl;
        if (now == digits.length())
        {
            ans.push_back(res);
            return;
        }
        string* tmp = &table[digits[now] - '2'];
        // cout << tmp->length();
        for (int i = 0, len = tmp->length(); i < len; ++i)
            work(digits, now + 1, res + (*tmp)[i]);
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() != 0)
            work(digits, 0, "");
        return ans;
    }
};

// int main()
// {
//     Solution sl;

//     vector<string> ans = sl.letterCombinations("23");
//     for (string &i : ans)
//         cout << i << endl;
// }
