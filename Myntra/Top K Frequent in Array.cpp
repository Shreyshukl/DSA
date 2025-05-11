class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
          int n = arr.size();
          
          unordered_map<int,int>mp;
          
          for(int num : arr)
          {
              mp[num]++;
          }
          
          priority_queue<pair<int,int>>pq; //maxheap
            
          for(pair<int,int>it:mp)
          {
              pq.push({it.second,it.first});
          }
          
          vector<int>result;
          
          while(k--&&!pq.empty())
          {
              pair<int,int>it = pq.top();
              pq.pop();
              result.push_back({it.second});
          }
          
          return result;
    }
};

