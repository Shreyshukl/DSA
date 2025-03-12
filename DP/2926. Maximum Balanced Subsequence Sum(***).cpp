class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int , long long>mp;  //nums[i]-i , sum
        long long result = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            long long sum = nums[i];
            auto it = mp.upper_bound(nums[i]-i) ; //nums[j]-j dhundo
            if(it!=mp.begin())
            {
                it--;
                sum+=it->second; 
                //dhundha, milne p uske maxbalancedsubsequencesum apna nums[i] jod diya
            }

            mp[nums[i]-i] = max(mp[nums[i]-i] , sum); // ab jo bda hoga vo map m store ho

            it = mp.upper_bound(nums[i]-i); 
//just bda no khojo aur dekho agr uska sum ise chota h to vo no delete krdo map se
            while(it!=mp.end() && it->second<=sum)
            {
                mp.erase(it++);
            }
            result = max(result , sum);
        }
        return result;
    }
};



//top-down(TLE)
class Solution {
public:
    unordered_map<string , long long>mp;
    long long solve(int i , int prev , vector<int>&nums , int n)
    {
        if(i>=n)
        {
            return 0; //no element sum is zero
        }
        string key = to_string(prev)+" "+to_string(i);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        long long take  = 0;
        if(prev==-1||nums[i] - i >= nums[prev] - prev)
        {
            //agr y no liya apna subsequence m to vo add hoga he agla kaunsa no hoga
            take = nums[i] + solve(i+1, i , nums , n);
        }
        long long skip = solve(i+1 , prev , nums , n);

        return mp[key]=max(take,skip);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
       int n = nums.size();
       long long  result = *max_element(nums.begin() , nums.end());
       if(result<=0)
       {
        return result; //agr sare negative no h to usme kuch bhi add kroge vo chota hoye
       }
      
       return solve(0, -1 , nums , n); 
    }
};




//bottom-up (TLE)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
       int n = nums.size();
       long long result = *max_element(nums.begin() , nums.end());
       if(result<=0)
       {
        return result;
       }
       //dp[i] = maxBalancedSubsequenceSum(dp[i])
      //sare element khudme he ek subsequence h to unka sum vo khud hojayenge

      vector<long long>dp(n,0);

      for(int i = 0 ; i<n ; i++)
      {
        dp[i] = nums[i];
      }
       
       long long maxSum = result;
       for(int i = 0 ; i<n ; i++)
       {
        for(int j = 0 ; j<i ; j++)
        {
            if(nums[i]-i>=nums[j]-j)
            {
                 dp[i] = max<long long>(dp[i] , dp[j]+nums[i]);
                 maxSum = max(maxSum , dp[i]);
            }
        }
       }
       return maxSum;
    }
};
