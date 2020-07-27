class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses],in(numCourses,0),sol;
        int i,c;
        queue<int> q;
        //make graph
        for(auto& p:prerequisites){
            G[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        // Kahns
        for(i=0;i<in.size();i++) if(in[i]==0) q.push(i);        
        while(!q.empty()){
            c = q.front();q.pop();
            sol.push_back(c);
            for(auto&u:G[c]){
                if(--in[u]==0)q.push(u);
            }
        }
		//Check if any node is left in graph(ie indegree of some node!=0). If such a node is present then no solution exists return empty vector. Else return the sol vector.
        for(i=0;i<in.size();i++) if(in[i]!=0){
            sol.clear();
            break;
        }
        return sol;
    }
};
