
class Solution {
public:
    bool canFinish(int& numCourses, vector<vector<int>>& prerequisites) {
        vector<int> G[numCourses],in(numCourses,0);
        int i,c;
        queue<int> q;
        //make graph
        for(auto& p:prerequisites){
            G[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        // Kahns algorithm
        for(i=0;i<in.size();i++) if(in[i]==0) q.push(i);        
        while(!q.empty()){
            c = q.front();q.pop();
            for(auto&u:G[c]){
                if(--in[u]==0)q.push(u);
            }
        }
		//if any node left in graph(indegree of some node!=0) return false else return true
        for(i=0;i<in.size();i++) if(in[i]!=0)return false;
        return true;
    }
};
