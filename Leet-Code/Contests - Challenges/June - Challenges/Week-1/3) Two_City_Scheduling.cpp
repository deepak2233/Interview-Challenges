class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp=[](auto a,auto b)
        {
            return a[1]-a[0]>b[1]-b[0];
        };
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        for(int i=0 ; i<costs.size() ; i++)
        {
            if(i<costs.size()/2) ans+=costs[i][0];
            else ans+=costs[i][1];
        }
        return ans;
    }
};
