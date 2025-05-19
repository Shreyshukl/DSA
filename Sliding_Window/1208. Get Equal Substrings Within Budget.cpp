class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxlen = 0;
        int i = 0 , j = 0 ;
        int cost = 0;
        while(j<n)
        {
            cost+=abs(s[j]-t[j]);
            while(cost > maxCost)
            {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};
