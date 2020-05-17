
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, sc(26, 0), pc(26, 0);
        for (char c : p)
            pc[c - 'a']++;
        for (int i = 0, j = -p.size(); i < s.size(); i++, j = i - p.size()) {
            sc[s[i] - 'a']++;
            if (j >= 0)
                sc[s[j] - 'a']--;
            if (pc == sc)
                res.push_back(j + 1);
        }
        return res;
    }
};
