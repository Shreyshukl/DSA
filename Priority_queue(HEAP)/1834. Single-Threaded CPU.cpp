class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>>arr;
        for(int i = 0 ; i<n ; i++)
        {
            int start_time = tasks[i][0];
            int process_time = tasks[i][1];
            arr.push_back({start_time , process_time , i});
        }

        sort(arr.begin() , arr.end());
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;//minHeap

        long long currTime = 0;
        int idx = 0;
        vector<int>result;
        while(!pq.empty() || idx<n)
        {
            if(pq.empty()&& currTime < arr[idx][0])
            {
                currTime = arr[idx][0]; //pehle ke liye
            }
            while(idx<n && arr[idx][0] <=currTime )
            {
                pq.push({arr[idx][1] , arr[idx][2]});
                idx++;
            }
            pair<int,int>it = pq.top();
            pq.pop();
            int processTime = it.first;
            int index = it.second;
            currTime+=processTime;
            result.push_back(index);
        }
        return result;
    }
};
