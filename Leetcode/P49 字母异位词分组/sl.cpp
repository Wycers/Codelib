class Solution {
#define int unsigned long long
public:
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                      103};

    int get_hash(string &str) {
        vector<int> cnt(26, 0);
        int res = 1;
        for (char &c: str) {
            res *= prime[c - 'a'];
            res %= 1000000000000009;
        }
        return res;
    }

    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        int n = strs.size();
        vector<int> hash(n), tag(n);

        for (int i = 0; i < n; ++i) {
            hash[i] = get_hash(strs[i]);
            tag[i] = i;
        }

        sort(tag.begin(), tag.end(), [&hash](int a, int b) -> bool {
            return hash[a] < hash[b];
        });

        vector <vector<string>> ans;
        vector <string> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(strs[tag[i]]);
            if (i + 1 < n && hash[tag[i]] == hash[tag[i + 1]])
                continue;

            ans.push_back(tmp);
            tmp.clear();
        }

        return ans;
    }

#undef int
};