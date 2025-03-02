class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0 ; i<=n-k ; i++)
        {
            unordered_set<int>unique_window;
            for(int j = i  ; j<i+k ; j++)
            {
                unique_window.insert(nums[j]);
            }

            for(int i  : unique_window)
            {
                  mp[i]++;
            }
        }
        int maxV = INT_MIN;
        for(auto it : mp)
        {
            if(it.second == 1)
            {
                if(it.first>maxV)
                {
                    maxV = it.first;
                }
            }
        }
        return (maxV==INT_MIN) ? -1 : maxV ;
    }
};
