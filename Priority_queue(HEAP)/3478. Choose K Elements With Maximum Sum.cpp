class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<vector<long long>>vec(n);

        for(int i = 0 ; i<n ;i++)
        {
           vec[i]={nums1[i],i,nums2[i]};
        }

        vector<long long>result(n,0);
        sort(vec.begin() ,vec.end());
        long long sum = 0;
        priority_queue<int , vector<int> , greater<int>>pq; //minheap
        for(int i = 0 ; i< n ; i++)
        {
            if(i > 0 && vec[i-1][0] == vec[i][0])
            {
                long long ans = result[vec[i-1][1]];
                result[vec[i][1]]=ans;
            }
            else
            {
                result[vec[i][1]] = sum;
            }

            sum+=vec[i][2];
            pq.push(vec[i][2]);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
           
        }
        return result;
    }
};




// Brute force
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long>result(n,0);
        for(int i = 0 ; i<n ;i++)
        {
            priority_queue<int , vector<int> , greater<int>>pq; //minhap
            for(int j = 0 ; j<n ;j++)
            {
                if(nums1[j]<nums1[i])
                {
                    //y mera candidate h
                    pq.push(nums2[j]);
                    if(pq.size()>k)
                    {
                        pq.pop();
                    }

                }
            }
            long long sum = 0;
            while(!pq.empty())
            {
                sum+=pq.top();
                pq.pop();
            }
            result[i]=sum;
        }
        return result;
    }
};
