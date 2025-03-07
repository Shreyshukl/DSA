class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        
         dp[0][0]  = arr[0][0]; //running
         dp[0][1]  = arr[0][1]; //fighting
         dp[0][2]  = arr[0][2]; //Learning
        
        for(int i = 1 ; i<n ; i++)
        {
            dp[i][0] = arr[i][0] + max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = arr[i][2] + max(dp[i-1][0],dp[i-1][1]);
            
        }
        return max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]});
    }
};
