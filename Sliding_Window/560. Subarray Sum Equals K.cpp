class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cummulativeSum = 0;
        int result = 0;
    //past m y cummulative sum dekha h kya cummulativesum->kitne baar dekha
        unordered_map<int,int>mp;
        mp[0] = 1; //sbse phle to cummulativeSum 0 he h aur use ek baar to dekha he h to daal do

        for(int i = 0 ; i<n ; i++)
        {
            cummulativeSum+= nums[i];
           int remaining =  cummulativeSum - k;
           if(mp.find(remaining)!=mp.end())
           {
              result+=mp[remaining];
           }
           mp[cummulativeSum]++;
        }
        return result;
    }
};

//brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0 ; i<n ;i++)
        {    
            int sum = 0;
            for(int j = i ; j<n ; j++)
            {
                sum+=nums[j];
                if(sum==k)
                {
                    count++;  
                }
            }
        }
        return count;
    }
};
