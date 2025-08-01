class Solution {
public:
    int dp[1001];
    int solve(int i , int n , vector<int>& cost)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int step1 = cost[i]+solve(i+1,n,cost);
        int step2 = cost[i]+solve(i+2 , n , cost);

        return dp[i]=min(step1 ,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();

        memset(dp ,-1 ,sizeof(dp));
        return min(solve(0,n,cost) , solve(1,n,cost));
    }
};
