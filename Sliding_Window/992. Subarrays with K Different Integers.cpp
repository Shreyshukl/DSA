class Solution {
public:
    int SlidingWindow(vector<int>nums,int k)
    {
        unordered_map<int,int>mp;
        int result = 0;
        int i = 0 ; 
        for(int j = 0 ; j<nums.size() ; j++)
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }

            result+=j-i+1;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int a =  SlidingWindow(nums , k);
        int b =  SlidingWindow(nums , k-1);

        return a-b;
    }      
};
