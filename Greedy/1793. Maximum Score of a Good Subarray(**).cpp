class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k;
        int j = k;
        int maxScore = nums[k];
        int curMin = nums[k];
        while(i>0 || j<n-1)
        {
            int leftVal  = (i>0)?nums[i-1]:0;
            int rightVal = (j<n-1)?nums[j+1]:0;

            if(leftVal>rightVal
            )
            {
                i--;
                curMin = min(curMin , nums[i]);
            }
            else
            {
                j++;
                curMin = min(curMin , nums[j]);
            }
            maxScore=max(maxScore,curMin*(j-i+1));
        }
        return maxScore;
    }
};
