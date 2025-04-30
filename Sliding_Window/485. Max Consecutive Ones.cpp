class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxCount = 0;
        int count = 0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                count=0;
            }
            else
            {
                count++;
            }
            maxCount = max(maxCount,count);
            i++;
        }
        return maxCount;
    }
};
