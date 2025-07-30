class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>result;
       unordered_map<int ,int>mp;
       for(int num : nums2)
       {
            mp[num]++; 
       }

       for(int num : nums1)
       {
           if(mp[num]>0)
           {
            result.push_back(num);
            mp[num]--;
           }
       }

       return result;
    }
};
