class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>CumulativeSum(n , 0);
        deque<int>deq;
        int result = INT_MAX;
        int i = 0 , j = 0;
        while(j<n)
        {
            if(j==0)
            {
                CumulativeSum[j] = nums[j];
            }
            else
            {
                CumulativeSum[j] = CumulativeSum[j-1]+nums[j];
            }

            if(CumulativeSum[j]>=k)
            {
                result = min(result  , j-i+1);
            }
            //shrink
            while(!deq.empty() && CumulativeSum[j] - CumulativeSum[deq.front()]>=k)
            {
                result = min(result,j-deq.front());
                deq.pop_front();
            }
            //maintain increasing order of deque
            while(!deq.empty() &&  CumulativeSum[j]<=CumulativeSum[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
       return result == INT_MAX ? -1 : result;

    }
};
