class Solution {
public:
    int countSubstrings(string s, int k) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; ++i) {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '0') zeros++;
                else ones++;

                if (zeros <= k || ones <= k) {
                    total++;
                } else {
                    break; // No need to go further from this i
                }
            }
        }

        return total;
    }
};
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int count=0;
        int zeroCount = 0;
        int oneCount = 0;
        int i=0;
            for(int j = 0 ; j<n ; j++)
            {   
                if(s[j]=='0')
                {
                    zeroCount++;
                }
                if(s[j]=='1')
                {
                    oneCount++;
                }
                while(zeroCount>k&&oneCount>k)
                {
                    if(s[i]=='0')
                    {
                        zeroCount--;
                    }
                     if(s[i]=='1')
                    {
                        oneCount--;
                    }
                    i++;
                }
                if(zeroCount<=k || oneCount<=k)
                {
                    count+=j-i+1;
                }
            }
        return count;
    }
};
