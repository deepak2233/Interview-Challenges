class Solution {
public:
    string frequencySort(string s) {
        int cnt[256]={0};                // char -> counter
        int ixs[256];                    // position -> char; prepare for sorting
        for(int c=0;c<256;c++) ixs[c]=c; // initiate: fill with all possible chars
        for(char c:s) cnt[c]++;
        sort(begin(ixs), end(ixs), 
             [&](const int a, const int b) { return cnt[a]>cnt[b]; }); // descending
        string res="";
        for(int c:ixs) res+=string(cnt[c], c); // repeat 'c' severeal times 
        return res;
    }
};
