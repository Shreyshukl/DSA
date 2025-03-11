class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int result = 0;
        priority_queue<int>maxHeap;
        for(int i = 0 ; i<n ; i++)
        {
            maxHeap.push(piles[i]);
        }
        while(!maxHeap.empty()&&k!=0)
        {
            int a = maxHeap.top();
            maxHeap.pop();
            a = a - floor(a/2);
            maxHeap.push(a);
            k--;
        }
        while(!maxHeap.empty())
        {
            result+=maxHeap.top();
            maxHeap.pop();
        }
        return result;
    }
};
