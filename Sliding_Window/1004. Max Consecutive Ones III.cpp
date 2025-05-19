class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 ;
        int ZeroCount = 0;
        int maxlen = 0;
        for(int j = 0 ; j<n ; j++)
        {
            if(nums[j]==0)
            {
                ZeroCount++;
            }
            while(ZeroCount>k)
            {
                if(nums[i]==0)
                {
                    ZeroCount--;
                }
                i++;
            }
            maxlen = max(maxlen , j-i+1);
        }
        return maxlen;
    }
};
