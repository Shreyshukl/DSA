class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector<int>result;
    int n = arr.size(); 
    //minheap
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
    for(int i = 0 ; i<n-1 ; i++)
    {
        int j = n-1;
        while(i<j)
        {
            pq.push({double(arr[i])/double(arr[j]) , {arr[i],arr[j]}});
            j--;
        }
    }
    while(--k)
    {
        pair<double,pair<int,int>> it = pq.top();
        pq.pop();
    }
    pair<double,pair<int,int>> it= pq.top();
    result.push_back(it.second.first);
    result.push_back(it.second.second);
    return result;
    }
};
