class Solution {
public:
    int nextIndex(vector<int>&nums , int n , int index , bool forward)
    {
        bool direction = nums[index]>0;
        if(direction!=forward || nums[index]==0) // misdirection or visited
        {
            return -1;
        }

        int next = (index + nums[index]) % n ; //finds the next index
        if(next<0)
        {
            next += n;
        }

        if(index == next)
        {
            return -1;
        }
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i<n ; i++)
        {
            int slow = i , fast = i;
            bool forward = nums[i]>0;

            while(true)
            {
                slow = nextIndex(nums , n , slow , forward);
                fast = nextIndex(nums , n , fast, forward);
                if(fast!=-1)
                {
                  fast = nextIndex(nums , n , fast , forward);  
                }
                if(slow == fast || slow==-1 || fast==-1)
                {
                    break;
                }
            }
            if(slow!=-1 && slow==fast)
            {
                return true; //cycle exsist
            }

            //marking
            int index = i;
            while(true)
            {
                int next = nextIndex(nums , n , index , forward);
                if(next==-1)
                {
                    break;
                } 
                nums[index] = 0;
                index = next;
            }
        }
        return false;
    }
};
