class Solution {
public:
    int longestSubarray(vector<int>& nums) {
          int n = nums.size();
          int i = 0 , j = 0;
          int maxlength = 0;
          int countZero = 0;
          while(j<n)
          {
            if(nums[j]==0)
            {
              countZero++;
            }
            while(countZero>1)
            {
                if(nums[i]==0)
                {
                  countZero--;  
                }
                i++;
            }
            maxlength = max(maxlength,j-i);
            j++;
          }
          return maxlength;
    }
};
