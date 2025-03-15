// minimise the maximum (binary search on answer)
class Solution {
public:
    bool isPossible(int mid , vector<int>&nums , int k)
    {
        int house = 0;
        for(int i = 0; i<nums.size() ;i++)
        {
            if(nums[i]<=mid)
            {
                house++;
                i++; //taki adjacent house m na jau
            }
        }
        if(house>=k)
        {
            return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin() , nums.end());
        int r = *max_element(nums.begin() , nums.end());


        int result = r; //filhaal k liye maxValue he mere capability h
        while(l<=r)
        { 
            int mid = l+(r-l)/2; //capability
            if(isPossible(mid , nums , k)==true)
            {
                result = mid;
                r=mid-1; //to minimize the capability
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
    }
};
//TLE (top-down)
class Solution {
public:
    
    int solve(int i , int k , vector<int>&nums , int n , vector<vector<int>>&dp)
    {
        if(k==0)
        {
            return 0; //no more house to be covered
        }
        if(i>=n)
        {
            return INT_MAX; //invalid case out of bound hogye but k bacha h
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        int take = max(nums[i],solve(i+2 ,k-1 , nums , n, dp));
        int skip = solve(i+1 , k , nums ,n , dp);

        return dp[i][k]=min(take,skip);
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(k+1,-1));
        return solve(0,k,nums,n,dp);
    }
};
