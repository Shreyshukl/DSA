class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        deque<int>mindq , maxdq; //stores indices in descending order
        int i = 0;
        for(int j = 0 ; j<n ; j++)
        {
            while(!maxdq.empty() && nums[maxdq.back()]<nums[j])//aya hua no ise bda h
            {
                maxdq.pop_back();
            }
            maxdq.push_back(j);

            while(!mindq.empty() && nums[mindq.back()]>nums[j])//aya hua no ise chota h
            {
                mindq.pop_back();
            }
            mindq.push_back(j);


            while(!maxdq.empty()&& !mindq.empty() && nums[maxdq.front()] - nums[mindq.front()] > 2)
            {
                i++;
                if(maxdq.front()<i)
                {
                    maxdq.pop_front();
                }
                if(mindq.front()<i)
                {
                    mindq.pop_front();
                }
            }
            count += (j-i+1);
        }
        return count;
    }
};

// approach 2
class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums) {
            int n = nums.size();
            long long count = 0;
            multiset<int>st; //sorted order m bhi rhenge aur duplicate bhi allowed h
            int i = 0;
            for(int j = 0 ; j<n ; j++)
            {
                st.insert(nums[j]);
                while((*st.rbegin() - *st.begin())>2)
                {
                    st.erase(st.find(nums[i]));
                    i++;
                }
                count+=j-i+1;//jitne bhi subarray h us range m
            }
            return count;
        }
    };

// approach 3 (TLE)
class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums) {
            int n = nums.size();
            long long count = 0;
            for(int i = 0 ; i<n ; i++)
            {
                int minVal = nums[i] , maxVal = nums[i];
                for(int j = i ; j<n ; j++)
                {
                    minVal = min(minVal , nums[j]);
                    maxVal = max(maxVal , nums[j]);
                    if((maxVal-minVal)>2)
                    {
                        break;
                    }
                    count++;
                }
            }
            return count;
        }
    };
