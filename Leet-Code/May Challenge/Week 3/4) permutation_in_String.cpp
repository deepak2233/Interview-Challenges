class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> pv(26,0);
        vector<int> sv(26,0);
        
        if(s1.length()>s2.length())
            return false;
        
        for(int i=0;i<s1.length();i++){
            pv[s1[i]-'a']++;
            sv[s2[i]-'a']++;
        }
        if(sv==pv)
            return true;
        for(int i=s1.length();i<s2.length();i++){
            sv[s2[i]-'a']++;
            sv[s2[i-s1.length()]-'a']--;
            
            if(sv==pv)
                return true;
        }
        return false;
    }
};
