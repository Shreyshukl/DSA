class Solution {
public:
  vector<vector<int>>result;
   void twoSums(vector<int>&nums,int target,int left,int right)
   {
    while(left<right)
    {
        if(nums[left]+nums[right]<target)
        {
          left++;
        }
        else if(nums[left]+nums[right]>target)
        {
          right--;
        }
        else
        {
            while(left<right&&nums[left]==nums[left+1])
            {
                left++;
            }
             while(left<right&&nums[right]==nums[right-1])
            {
                right--;
            }
            result.push_back({-target,nums[left],nums[right]});
        
        left++;
        right--;
        }
    }
   }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //fixing n1 and also check for duplicacy
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
        
        int n1=nums[i];
        int target=-n1;
        twoSums(nums,target,i+1,n-1);
    }
    return result;
    }
};


class Solution {
public:
    vector<vector<int>>result;
    void twoSum(int i , int j , vector<int>& nums , int target)
    {
        vector<int>ans;
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            if(sum < target)
            {
                i++;
            }
            else if(sum > target)
            {
                j--;
            }
           else{
              result.push_back({-target , nums[i] , nums[j]});  
               while(i<j && nums[i]==nums[i+1])
              {
                i++;
              }
              while(i<j && nums[j]==nums[j-1])
              {
                j--;
              }
              i++;
              j--;
         }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
      
        int n = nums.size();

        for(int i = 0 ; i<n ; i++)
        {

            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int target = nums[i];
            twoSum(i+1 , n-1 , nums , -target);
        }
        return result;
    }
};
