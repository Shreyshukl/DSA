class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
       
        vector< long long>PrefixSum(n);
        PrefixSum[0] = nums[0];
        for(int i = 1 ; i<n ; i++)
        {
            PrefixSum[i] = nums[i] + PrefixSum[i-1];
        }
        int i = 2;
        long long perimeter = 0;
        long long maxPerimeter = INT_MIN;
        while(i<n)
        {
            int j = i-1;
            if(PrefixSum[j] > nums[i])
            {
                perimeter = PrefixSum[j]+nums[i];
                maxPerimeter = max(maxPerimeter , perimeter);
            }
            i++;
        }
        return maxPerimeter==INT_MIN? -1 : maxPerimeter;

    }
};
