/*You are given an API bool isBadVersion(version) which will return whether version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to the API.*/


class Solution {
public:
    int firstBadVersion(int n) {
        int from,to,mid;
        from=1;to=n;
        while(from!=to)
        {
            mid=((long long)from+to)/2;
            if(isBadVersion(mid)==true)
            {
                to=mid;
            }
            else
            {
                from=mid+1;
            }
        }
        return from;
    }
};
