class Solution {
public:
    int cheapestFlight(int n,int** adjMatrix, int src, int dst, int K,bool* visited,int** memo){
        //Base case
        if(src==dst){
            return 0;
        }
        if(K==0){
            return -1;
        }
        
        if(memo[src][K]!=0){
            return memo[src][K];
        }
        
        visited[src]=true;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(!visited[i]&&adjMatrix[src][i]!=0){
                int op=cheapestFlight(n,adjMatrix,i,dst,K-1,visited,memo);
                if(op!=-1){ //If we are able to get to destination in K-1 steps if we go from src->i, thus our ans is not -1
                    op+=adjMatrix[src][i];
                    ans=min(ans,op);
                }
            }
        }
        visited[src]=false; 
        if(ans==INT_MAX){ //If ans is not updated, there is no possible way to reach destination in K steps, return -1
            memo[src][K]=-1;
            return memo[src][K];
        }
        memo[src][K]=ans;
        return ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //I will use DFS with memoization here
        int** adjMatrix=new int*[n];
        for(int i=0;i<n;i++){
            adjMatrix[i]=new int[n];
            for(int j=0;j<n;j++){
                adjMatrix[i][j]=0;
            }
        }
        bool* visited=new bool[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        //Putting values in our weighted adjacency Matrix
        for(int i=0;i<flights.size();i++){
            adjMatrix[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        //In our memo array,at memo[i][j]-> I will store minimum amount of money needed to reach from ith city to dst within k steps
        int** memo=new int*[n+1];
        for(int i=0;i<=n;i++){
            memo[i]=new int[K+2];
            for(int j=0;j<=K+1;j++){
                memo[i][j]=0;    //I initialized my memo with 0 instead of -1, because we can have -1 as answer
            }
        }
        return cheapestFlight(n,adjMatrix,src,dst,K+1,visited,memo);
    }
};
