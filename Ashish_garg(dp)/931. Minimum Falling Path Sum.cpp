class Solution {
public:
    int dp[2000][2000];
    int solve(int i  , int j , int m , int n , vector<vector<int>>& matrix)
    {
        if(i==m-1)
        {
            return matrix[i][j];
        }

        if(i>=m || j>=n)
        {
            return 1e9;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int down     =  matrix[i][j]  + solve(i+1 , j , m , n , matrix);
        int digLeft  =  (j-1>=0) ? matrix[i][j]  + solve(i+1 , j-1 , m , n , matrix) : 1e9;
        int digRight =  (j+1< n) ? matrix[i][j]  + solve(i+1 , j+1 , m , n , matrix) : 1e9;

        return dp[i][j]=min({down , digLeft , digRight });
        

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1e9;
        memset(dp,-1,sizeof(dp));
        for(int j = 0 ; j<n ; j++)
        {
            ans = min(ans , solve(0 , j , m , n , matrix));
        }
        return ans;
    }
};
