class Solution {
public:
    typedef pair<int,int> P;
    int MOD = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P , vector<P> , greater<P>>pq;
        for(int i = 0 ; i<n ; i++)
        {
           pq.push({nums[i],i});
        }
        int result = 0;
        for(int count =1 ; count<=right ; count++)
        {
            auto p = pq.top();
            pq.pop();
            int sum = p.first;
            int idx = p.second;

            if(count>=left)
            {
                result=(result+sum)%MOD;
            }
            int new_idx = idx+1;
            P new_pair;
            if(new_idx<n)
            {
                new_pair.first  = sum+nums[new_idx];
                new_pair.second = new_idx;
                pq.push(new_pair);
            }   
        }
        return result;
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>result;
        for(int i = 0 ; i<n ; i++)
        {
            int sum = 0;
            for(int j = i ; j<n ; j++)
            {
               sum+=nums[j];
               result.push_back(sum);
            }
        }
        sort(result.begin() , result.end());
        int ans = 0;
        for(int i = left-1 ; i<=right-1 ; i++)
        {
            ans=(ans+result[i])%MOD;
        }
        return ans;
    }
};
