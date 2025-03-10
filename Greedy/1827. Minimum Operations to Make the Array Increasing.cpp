class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i-1]>=nums[i])
            {
                int increment = nums[i-1]-nums[i]+1;
                nums[i] = nums[i]+increment;
                operations+=increment;
            }
        }
        return operations;
    }
};
// approach 2
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        for(int i = 1 ; i<n ; i++)
        {
            int newVal = max(nums[i-1]+1,nums[i]);
            operations+=newVal-nums[i];
            nums[i] = newVal;
        }
        return operations;
    }
};
