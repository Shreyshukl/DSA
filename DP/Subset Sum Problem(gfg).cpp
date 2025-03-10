class Solution {
  public:
  
    bool solve(int i,int n,vector<int>&arr,int target,vector<vector<int>>&dp)
    {
        if(target == 0) //milgya
        {
            return true;
        }
        if(i>=n || target<0) //nhi mila ya subset invalid h
        {
          return false;  
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        bool take = false;
        if(arr[i]<=target)
        {
             take = solve(i+1 , n , arr , target-arr[i] , dp);
        }
        bool skip = solve(i+1 , n , arr , target, dp);
        return dp[i][target]=take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n+1 , vector<int>(target+1,-1));
        return solve(0,n,arr,target,dp);
    }
};
