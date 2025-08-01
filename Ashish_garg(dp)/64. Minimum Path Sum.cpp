class Solution {
public:
    int dp[201][201];
    int solve(int i , int j , int m , int n , vector<vector<int>>& grid)
    {
        if(i==m-1&&j==n-1)
        {
            return grid[i][j];
        }
        if(i>=m || j>=n)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int right = grid[i][j] + solve(i , j+1 , m , n , grid);
        int down =  grid[i][j] + solve(i+1 , j , m , n , grid);

        return dp[i][j]=min(right,down);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        int ans = INT_MAX;
        memset(dp,-1,sizeof(dp));
        ans = min(ans,solve(0 , 0 , m , n , grid));

        return ans;
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = 0 ;
        int down = 0;
        for(int i=1 ; i<m ; i++)
        {
            grid[i][0]+=grid[i-1][0];
        }

         for(int j=1 ; j<n ; j++)
        {
            grid[0][j]+=grid[0][j-1];
        }

       for(int i = 1 ; i<m ; i++)
       {
        for(int j = 1 ; j<n ; j++)
        {
           grid[i][j]+= min(grid[i][j-1],grid[i-1][j]);
        }
       }
       return grid[m-1][n-1];
    }
};
