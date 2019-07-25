class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word;
        while (iss >> word)
            ;
        return word.size();
    }
};
