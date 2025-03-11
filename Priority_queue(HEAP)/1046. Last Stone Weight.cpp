class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       int n = stones.size();
       priority_queue<int>maxHeap;
       for(int i = 0 ; i<n ; i++)
       {
            maxHeap.push(stones[i]);
       }
       while(maxHeap.size()>1)
       {
        int a = maxHeap.top();
        maxHeap.pop();
        int b = maxHeap.top();
        maxHeap.pop();
        if(a!=b)
        {
            a = a-b;
            maxHeap.push(a);
        }
       }
        
        return maxHeap.empty()? 0 : maxHeap.top();
    }
};
