class KthLargest {
public:
    int K;
    priority_queue<int , vector<int> , greater<int>> pq; //minHeap
    int result;
    KthLargest(int k, vector<int>& nums) {
       K=k;
       int i = 0;
       int n = nums.size();
       for(int i = 0 ; i<n ; i++)
       {
            pq.push(nums[i]);
            if(pq.size()>K)
            {
                pq.pop();
            } 
       }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)
        {
            pq.pop();
        }
        return pq.top();
    }
};

