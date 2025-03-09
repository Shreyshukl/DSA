class Solution {
public:
    long long dp[100001][2];
    long long solve(int idx , bool flag , vector<int>& nums , int n)
    {
        if(idx>=n)
        {
            return 0;
        }
        if(dp[idx][flag]!=-1)
        {
            return dp[idx][flag];
        }
        long long skip = solve(idx+1 , flag , nums , n); //flag same rhega
        //ab take krna h to value chahiye aur value k saath sign kya hoga
        long long val = nums[idx];
        if(flag==false)
        {
            val = -val;
        }
        long long take = solve(idx+1, !flag , nums , n)+val;

        return dp[idx][flag]=max(take,skip);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        memset(dp,-1,sizeof(dp));
        return solve(0 , flag , nums , n);
    }
};
