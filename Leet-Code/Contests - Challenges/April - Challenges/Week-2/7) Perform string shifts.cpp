class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        
        int sum=0;
        for(int i=0;i<shift.size();i++){
            
            if(shift[i][0]==1){
                sum+=shift[i][1];
            }else{
                sum-=shift[i][1];
            }
        }
        int n=s.size();
        do{     
        sum=(sum+n)%n;
        }while(sum<0);
        string str="";
        for(int i=n-sum;i<n;i++){
            str+=s[i];
        }
        for(int i=0;i<n-sum;i++){
            str+=s[i];
        }
        return str;
    }
};
