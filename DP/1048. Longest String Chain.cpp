// top-down
class Solution {
public:
    int dp[1001][1001];
    bool isPredecessor(string&word1 , string&word2)
    {
        int m = word1.length();
        int n = word2.length();

        if(n-m==1)
        {
           int i = 0;
           int j = 0;
           while(j<n)
           {
                if(word1[i]==word2[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
           }
           if(i==m)
           {
            return true;
           }
        }
        return false;
    }
    int solve(int i , int prev , vector<string>& words , int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }

        int take = 0;
        if(prev==-1||isPredecessor(words[prev],words[i]))
        {
            take = 1+solve(i+1 , i , words , n);
        }
        int skip = solve(i+1 , prev , words, n);

        return dp[i][prev+1]=max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        auto lambda = [](string&word1 , string&word2)
        {
            return word1.length()<word2.length();
        };
        sort(words.begin() , words.end() , lambda);
        memset(dp , -1 , sizeof(dp));
        return solve(0 , -1 , words , n);
    }
};

//bottom-up

class Solution {
public:
    int dp[1001][1001];
    bool isPredecessor(string&word1 , string&word2)
    {
        int m = word1.length();
        int n = word2.length();

        if(n-m==1)
        {
           int i = 0;
           int j = 0;
           while(j<n)
           {
                if(word1[i]==word2[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
           }
           if(i==m)
           {
            return true;
           }
        }
        return false;
    }
   
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n ,1);
        auto lambda = [](string&word1 , string&word2)
        {
            return word1.length()<word2.length();
        };
        sort(words.begin(),words.end(),lambda);
        int maxlen = 1;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(isPredecessor(words[j],words[i]))
                {
                    dp[i] = max(dp[i] , dp[j]+1);
                    maxlen = max(maxlen , dp[i]);
                }
            }
        }
        return maxlen;
    }
};
