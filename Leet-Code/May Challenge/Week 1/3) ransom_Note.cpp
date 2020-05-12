  
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26]={0};
        for(char c: magazine)
        {
            freq[c-97]++;
        }
        for(char c: ransomNote)
        {
            freq[c-97]--;
            if(freq[c-97]<0)
            {
                return false;
            }
        }
        return true;
    }
};
