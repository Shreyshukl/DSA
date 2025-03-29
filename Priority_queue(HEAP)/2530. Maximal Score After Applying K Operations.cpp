class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq; //maxheap
        for(int i = 0 ; i<n ; i++)
        {
            pq.push(nums[i]);
        }
        long long score = 0;
        while(!pq.empty()&&k--)
        {
            int a = pq.top();
            pq.pop();
            score+=a;
            pq.push(ceil(a/3.0));
        }
        return score;
    }
};
