class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
    priority_queue<int , vector<int> , greater<int>>pq1;//minheap
    priority_queue<int,  vector<int> , greater<int>>pq2;//minheap

    int i = 0;
    int j = n-1;
    long long result = 0;
    while(k--)
    {
    while(pq1.size()<candidates && i<=j)
    {
        pq1.push(costs[i]);
        i++;
    }
    while(pq2.size()<candidates && j>=i)
    {
        pq2.push(costs[j]);
        j--;
    }

        int min_pq1 = pq1.size()>0?pq1.top() : INT_MAX;
        int min_pq2 = pq2.size()>0?pq2.top() : INT_MAX;

        if(min_pq1<=min_pq2)
        {
            result+=min_pq1;
            pq1.pop();
        }
        else
        {
            result+=min_pq2;
            pq2.pop();
        }
    }
    return result;
    }
};
