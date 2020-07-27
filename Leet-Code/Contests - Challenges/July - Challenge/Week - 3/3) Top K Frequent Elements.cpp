class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // creating handbook frequency map
        unordered_map<int, int> f;
        for (int n: nums) f[n]++;
        int pivot = 0, len = f.size(), step_index;
        // getting a support vector of uniques
        vector<int> u(len);
        for (auto e: f) u[pivot++] = e.first;
        partial_sort(begin(u), begin(u) + k, end(u), [&f](int a, int b){return f[a] > f[b];});
        return vector<int>(begin(u), begin(u) + k);
    }
};
