class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<long>PrefixSum(n);

        PrefixSum[0] = nums[0];
        int freq = 0;
        int result = 0;
        for(int i = 1  ; i<n ; i++)
        {
            PrefixSum[i]+=PrefixSum[i-1]+nums[i];
        }
        for(int i = 0 ; i<n ; i++)
        {
            freq = binarySearch(i , k , PrefixSum , nums);
            result = max(result , freq);
        }
        return result;
    }
        int binarySearch(int target_idx , int k , vector<long>&PrefixSum , vector<int>&nums)
        {
            int l = 0;
            int r = target_idx;
            long count = 0;
            long windowSum = 0;
            long originalSum = 0;
            int temp = 0;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                count = target_idx - mid+1;
                 windowSum = count*nums[target_idx];
                 originalSum = PrefixSum[target_idx] - PrefixSum[mid] + nums[mid];

                int operation = windowSum-originalSum;
                if(operation>k)
                {
                    l = mid+1;
                }
                else
                {
                    temp = mid;
                    r = mid-1;
                }
            }
                return target_idx - temp+1;
        }
};
