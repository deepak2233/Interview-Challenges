class Solution {
    public:
        bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
        {
            vector<vector<int>> graph(N+1); // ('people' are 1-based)
            for(auto& p : dislikes)
            {
                graph[p.front()].push_back(p.back());
                graph[p.back()].push_back(p.front());
            }

            vector<int> groups(N+1); // 0 = not assigned; 1 = group 1; -1 = group 2.
            for(int i = 1; i < graph.size(); ++i) // (1-based)
            {
                // if not assigned - should be able to assign to group 1
                if(groups[i] == 0 && !assign_group(graph, groups, i, 1))
                    return false;
            }
            return true;
        }

    protected:
        bool assign_group(vector<vector<int>>& graph, vector<int>& groups, int indx, int group)
        {
            groups[indx] = group;
            // make sure all it's 'dislikes' assigned or can be assigned to the opposite group
            for(int n : graph[indx]) 
            {
                if(groups[n] == group) 
                    return false;
                if(groups[n] == 0 && !assign_group(graph, groups, n, -group)) 
                    return false;
            }
            return true;
        }
};
