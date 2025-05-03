//for odd even
 vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = n-1;
        while(i<j)
        {
            while(i<j && nums[i]%2==0)
            {
                i++;
            }
            while(j>i && nums[j]%2!=0)
            {
                j--;
            }
            if(j>i)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }
};
// for -ve +ve
vector<int> move(vector<int> &arr) {
    int left = 0, right = arr.size()-1;
    while (left<right) {
        
        // increment left while arr[left]
        // is negative
        while (left<right && arr[left]<0) {
            left++;
        }
        
        // decrement right while arr[right]
        // is positive
        while (right>left && arr[right]>0) {
            right--;
        }
        
        // swap the two values.
        if (right>left) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    return arr;
}
