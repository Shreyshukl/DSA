class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int n = arr.size();
      int l = 1;
      int r = n-2;
      while(l<=r)
      {
        int mid = l+(r-l)/2;
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else if(arr[mid]>arr[mid-1])//increasing curve
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
