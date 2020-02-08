class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res;
        int count = 0, tm[128] = {0}, sm[128] = {0};
        for (char i : T)
            ++tm[i];
        for (int l = 0, r = 0; r < S.size(); ++r) {
            if (tm[S[r]] == 0)
                continue;
            ++sm[S[r]];
            if (sm[S[r]] <= tm[S[r]])
                ++count;
            while (count == T.size()) {
                if (res.empty() || r - l + 1 < res.size()) {
                    res = S.substr(l, r - l + 1);
                }
                if (tm[S[l]] != 0) {
                    --sm[S[l]];
                    if (sm[S[l]] < tm[S[l]]) --count;
                }
                ++l;
            }
        }
        return res;
    }
};