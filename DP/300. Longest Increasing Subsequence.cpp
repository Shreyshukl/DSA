//Bottom_UP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>dp(n,1); //longest increasing subsequence ending at ith index
       int maxLIS = 1;
       for(int i = 0 ; i<n ; i++)
       {
        for(int j = 0 ; j<i ; j++)
        {
            if(nums[j]<nums[i])
            {
                dp[i] = max(dp[i] , dp[j]+1);
                maxLIS = max(maxLIS , dp[i]);
            }
        }
       }
       return maxLIS;
    }
};
//top_down
class Solution {
public:
    int dp[2501][2501];
    int solve(int i , int prev , vector<int>& nums , int n )
    {
        if(i>=n)
        {
            return 0;
        }
        if(prev!=-1 && dp[i][prev]!=-1)
        {
            return dp[i][prev];
        }
        int take = 0;
        if(prev==-1||nums[prev]<nums[i])
        {
             take = 1 + solve(i+1, i, nums , n);
        }
        int skip = solve(i+1 , prev , nums , n);
        if(prev!=-1)
        {
            dp[i][prev] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0 ,-1 , nums , n);
    }
};
