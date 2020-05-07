class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> count;
	int i = 0;
	for (auto s : strs)
	{
		sort(s.begin(), s.end());
		count[s].push_back(strs[i++]);
	}
	vector<vector<string>> res;
	for (auto n : count){
		sort(n.second.begin(), n.second.end());
		res.push_back(n.second);
	}
	return res;
}
};
