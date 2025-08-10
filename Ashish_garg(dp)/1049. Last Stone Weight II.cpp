class Solution {
public:
    int dp[31][101];
    int solve(int i , int n , int totalSum , int target , int tempSum ,vector<int>&stones,vector<vector<int>>&dp)
    {
        if(i>=n || tempSum>=target)
        {
            return abs(tempSum - (totalSum-tempSum));
        }
        if(dp[i][tempSum]!=-1)
        {
            return dp[i][tempSum];
        }
        int option1 = solve(i+1,n,totalSum ,target ,tempSum+stones[i],stones,dp);
        int option2 = solve(i+1,n,totalSum ,target ,tempSum,stones,dp);

        return dp[i][tempSum]=min(option1,option2);
         
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin() , stones.end() , 0);
        int target = ceil(totalSum/2);
        vector<vector<int>>dp(n+1 , vector<int>(target,-1));
        return solve(0 , n , totalSum , target , 0 , stones,dp);
    }
};
