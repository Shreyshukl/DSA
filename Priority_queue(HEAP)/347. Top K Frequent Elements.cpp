class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++)
        {
            mp[nums[i]]++;
        }
        vector<int>result;
        priority_queue<pair<int,int>>pq; //maxheap;
        for(pair<int,int> it : mp)
        {
            pq.push({it.second,it.first}); //sorting based on freq
        }
        while(!pq.empty()&&k--)
        {
            pair<int,int>it = pq.top();
            pq.pop();
            result.push_back(it.second);
        } 
        return result; 
    } 
};
