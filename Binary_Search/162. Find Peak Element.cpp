//o(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      for(int i = 0 ; i<n ; i++)
      {
        if((i==0||nums[i]>nums[i-1]) && (i==n-1||nums[i]>nums[i+1]))
        {
            return i;
        }
      }
      return -1;
    }
};
//o(log n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      if(n==1)
      {
        return 0;
      }
      if(nums[0]>nums[1]) //first element is the peak
      {
        return 0;
      }
        if(nums[n-1]>nums[n-2]) //last element is the peak
      {
        return n-1;
      }
      //binary search
      int l = 1;
      int r = n-2;
      while(l<=r)
      {
        int mid = l+(r-l)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            return mid;
        }
        else if(nums[mid]>nums[mid-1]) //increasing curve 
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
      }
     return -1;
    }
};
