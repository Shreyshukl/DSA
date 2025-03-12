//bottom up

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        vector<int>dp(n,1);
        vector<int>prev_idx(n,-1);

  
        int LastchosenIndex = 0;
        int maxlen = 1;
        //dp[i] means larget divisible subset till dp[i];
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                if(nums[i]%nums[j]==0)
                {
                   if(dp[i]<dp[j]+1)
                   {
                     dp[i] = dp[j]+1;
                     prev_idx[i] = j;
                   }
                   if(dp[i]>maxlen)
                   {
                    maxlen = dp[i];
                    LastchosenIndex = i;
                   }
                }
            }
        }
        vector<int>result;
        while(LastchosenIndex!=-1)
        {
            result.push_back(nums[LastchosenIndex]);
            LastchosenIndex=prev_idx[LastchosenIndex];
        }
        return result;
    }
};




class Solution {
public:
    void solve(int i, int prev, vector<int>&nums, vector<int>&temp ,vector<int>&result ,int n)
    {
        if(i>=n)
        {
            if(temp.size()>result.size())
            {
                result = temp;
            }
            return;
        }
        if(prev==-1||nums[i]%nums[prev] == 0 || nums[prev]%nums[i] == 0)
        { 
            temp.push_back(nums[i]);  
            solve(i+1 , i , nums, temp , result, n);
            temp.pop_back(); 
        }
        solve(i+1 , prev , nums , temp , result , n);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int>temp;
        vector<int>result;
        solve(0,-1,nums,temp,result,n);    
        return result;
    }
};
