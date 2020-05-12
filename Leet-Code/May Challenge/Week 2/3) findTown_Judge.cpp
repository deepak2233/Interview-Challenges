  
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> in(N+1);
    vector<int> out(N+1);
    int jud = -1;
    
    for(int i=0;i<trust.size();i++)
    {
        in[trust[i][1]]++;
        out[trust[i][0]]++;
    }
    
    for(int i=1;i<=N;i++)
    {
       if(in[i]==N-1 && out[i]==0)
        {
            jud = i;
        }
    }
    
    return jud;
}
};
