// Brute force
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long>result(n,0);
        for(int i = 0 ; i<n ;i++)
        {
            priority_queue<int , vector<int> , greater<int>>pq; //minhap
            for(int j = 0 ; j<n ;j++)
            {
                if(nums1[j]<nums1[i])
                {
                    //y mera candidate h
                    pq.push(nums2[j]);
                    if(pq.size()>k)
                    {
                        pq.pop();
                    }

                }
            }
            long long sum = 0;
            while(!pq.empty())
            {
                sum+=pq.top();
                pq.pop();
            }
            result[i]=sum;
        }
        return result;
    }
};
