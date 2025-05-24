class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0 , j = 0;
        int maxlength = 0;
        multiset<int>st;
        while(j<n)
        {
            st.insert(nums[j]);
            int maxA = *st.rbegin();
            int maxB = *st.begin();

            while(abs(maxA-maxB)>limit)
            {
                st.erase(st.find(nums[i]));
                i++;
                maxA = *st.rbegin();
                maxB = *st.begin();
            }
            maxlength = max(maxlength , j-i+1);
            j++;   
        }
        return maxlength;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int  n = nums.size();
        int  i = 0 ;
        int maxlength = 0;
        for(int j = 0 ; j<n ; j++)
        {
            //isliye + 1 kiya kyunki y fn last element exclude krdeta h 
            int maxA = *max_element(nums.begin()+i , nums.begin()+j+1);
            int minB = *min_element(nums.begin()+i , nums.begin()+j+1);

            while(abs(maxA - minB)>limit)
            {
                i++;
                 maxA = *max_element(nums.begin()+i , nums.begin()+j+1);
                 minB = *min_element(nums.begin()+i , nums.begin()+j+1);

            }
            maxlength = max(maxlength,j-i+1);
        }
        return maxlength;
    }
};
