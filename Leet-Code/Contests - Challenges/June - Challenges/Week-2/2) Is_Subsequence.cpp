class Solution {
public:
    bool isSubsequence(string s, string t) {
    int temp = 0;
	for (int i = 0; i < t.size() && temp < s.size(); i++) {
		if (t[i] == s[temp])
			temp++;
	}
	return temp == s.size();
}        
    
};

	
