class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<pair<int,pair<int,int>>>pq; //maxheap
        vector<vector<int>>result;

        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                int sum = nums1[i]+nums2[j];
                if(pq.size()<k)
                {
                    pq.push({sum,{i,j}});
                }
                else if(pq.top().first>sum)
                {
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else{
                    break; 
        //jo sum aya vo bda aya to aage bhi jo ayenge vo aur bhi bde he ayenge
        //j ko 0 se kro start i aage bdha ke
                }
            }
        }
        while(!pq.empty())
        {
            pair<int,pair<int,int>>it = pq.top();
            pq.pop();
            result.push_back({nums1[it.second.first] , nums2[it.second.second]});
        }
      return result;
    }
};
