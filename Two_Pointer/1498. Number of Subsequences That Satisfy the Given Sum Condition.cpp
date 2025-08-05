class Solution {
public:
    const int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int l = 0 , r = n-1;
        int count = 0;

        vector<int>power(n,1);
        for(int i = 1 ; i<n ;i++)
        {
            power[i] = (power[i-1]*2)%MOD;
        }
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                count=(count+power[r-l])%MOD; //left ko fix krke
                l++; 
            }
            else
            {
                r--;
            }
        }
        return count;
    }
};



class Solution {
public:
    int count = 0;
    const int MOD = 1e9+7;
    void solve(int i , vector<int>& nums , vector<int>& path ,int target)
    {
       if(i == nums.size())
       {
            if(path.size()>0)
            {
            int mini = *min_element(path.begin() , path.end());
            int maxi = *max_element(path.begin() , path.end());

            if(mini+maxi <=target)
            {
                count = (count+1)%MOD;
            }
            }
            return;
       }
            path.push_back(nums[i]);
            solve(i+1 , nums,  path , target); //include
            path.pop_back();

            solve(i+1 , nums,  path , target); //exclude;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>path;
        solve(0 , nums , path , target);
        return count ; 
    }
};
