//binary search on answer
class Solution {
public:
    bool isPossible(int mid , vector<int>&nums , int k)
    {
        int house = 0;
        for(int i = 0; i<nums.size() ;i++)
        {
            if(nums[i]<=mid)
            {
                house++;
                i++; //taki adjacent house m na jau
            }
        }
        if(house>=k)
        {
            return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin() , nums.end());
        int r = *max_element(nums.begin() , nums.end());


        int result = r; //filhaal k liye maxValue he mere capability h
        while(l<=r)
        { 
            int mid = l+(r-l)/2; //capability
            if(isPossible(mid , nums , k)==true)
            {
                result = mid;
                r=mid-1; //to minimize the capability
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
    }
};
