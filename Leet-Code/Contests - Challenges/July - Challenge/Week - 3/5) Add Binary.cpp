class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size())
            return addBinary(b, a);
        
        int x = 0, y = 0, carry = 0;
        for(int i = a.size() - 1; i >= 0; i--){
            int ib = b.size() - a.size() + i;
            y = ib >= 0 ? b[ib] - '0' : 0;
            x = a[i] - '0';
            a[i] = (x + y + carry) % 2 + '0';
            carry = x + y + carry >= 2 ? 1 : 0;
        }
        
        if(carry) a = "1" + a;
        return a;
    }
};
