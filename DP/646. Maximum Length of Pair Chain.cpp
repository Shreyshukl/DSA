class Solution {
public:
    int dp[1001][1001]; 

    int solve(int i, int prev_idx, int n, vector<vector<int>>& pairs) {
        if (i >= n) {
            return 0;
        }
        
        if (dp[i][prev_idx + 1] != -1) {
            return dp[i][prev_idx + 1];  // Return cached result
        }
        
        int take = 0;
        if (prev_idx == -1 || pairs[i][0] > pairs[prev_idx][1]) {
            take = 1 + solve(i + 1, i, n, pairs);
        }
        
        int skip = solve(i + 1, prev_idx, n, pairs);
        
        return dp[i][prev_idx + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, -1, n, pairs);
    }
};
//bottom up
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int>dp(n,1);
        sort(pairs.begin() , pairs.end());

        int maxlen = 1;
        for(int i= 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i] = max(dp[i] , dp[j]+1);
                    maxlen = max(maxlen , dp[i]);
                }
            }
        }
        return maxlen;

    }
};
