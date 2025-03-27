class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m  = obstacleGrid.size();
        int n  = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
        {
            return 0; // 1st ya last m obstacle hua to kbhi pahuch he nhi payega
        }
        obstacleGrid[0][0]=1;

        for(int i = 1 ; i<m ; i++)
        {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 1) ? 0 : obstacleGrid[i-1][0];
        }
        for(int j = 1 ; j<n ; j++)
        {
            obstacleGrid[0][j] =  (obstacleGrid[0][j] == 1) ? 0 : obstacleGrid[0][j-1];
        }

        for(int i = 1 ; i<m ; i++)
        {
            for(int j = 1 ; j<n ; j++)
            {
               if(obstacleGrid[i][j]==1)
               {
                    obstacleGrid[i][j]=0;
               }
               else
               {
                  obstacleGrid[i][j] = obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
               }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};




class Solution {
public:
    int dp[101][101];
    int solve(int i , int j , int m , int n , vector<vector<int>>& obstacleGrid)
    {
         if(i>=m || j>=n)
        {
            return 0;
        }
        if(obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==m-1 && j ==n-1)
        {
            return 1;
        }
        
       
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down = solve(i+1 , j ,  m , n , obstacleGrid);
        int right = solve(i , j+1 , m , n , obstacleGrid);

        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m  = obstacleGrid.size();
        int n  = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , m , n ,obstacleGrid);
    }
};
