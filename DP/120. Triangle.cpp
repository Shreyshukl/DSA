class Solution {
public:
    int dp[201][201];
    int solve(int i , int j , vector<vector<int>>& triangle)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int down  = solve(i+1 , j   , triangle);
        int right = solve(i+1 , j+1 , triangle);

        return dp[i][j]=triangle[i][j]+min(down ,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , triangle);

    }
};
