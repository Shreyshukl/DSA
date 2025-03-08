class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n , vector<int>(n));

        for(int col = 0 ; col < n ; col++)
        {
            dp[0][col] = matrix[0][col];
        }
        for(int row = 1 ; row<n ; row++)
        {
            for(int col = 0 ; col<n ;col++)
            {
                int a = INT_MAX;
                int b = INT_MAX;

                if(col-1>=0)
                {
                    a = dp[row-1][col-1];
                }
                if(col+1<n)
                {
                    b = dp[row-1][col+1];
                }
                dp[row][col] = matrix[row][col]+ min({dp[row-1][col] , a , b});
            }
        }
        int row = n-1;
        int result = INT_MAX;
        for(int col = 0 ; col<n ; col++)
        {
            result = min(result, dp[row][col]);
        }
        return result;
    }
};
