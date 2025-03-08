class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ;i++)
        {
            mp[nums[i]]++;
        }
        int operation=0;
        for(pair<int,int>entry : mp)
        {
            int count = entry.second;
            if(count==1)
            {
                return -1;
            }
            if(count%3==0)
            {
                operation+=count/3; 
            }
            else
            {
                operation+=count/3+1;
            }
        }
        return operation;
    }
};
//2244
