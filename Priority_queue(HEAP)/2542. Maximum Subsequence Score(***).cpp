//greedy + pq approach

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      priority_queue<int  , vector<int> , greater<int>>pq; //minheap
      vector<pair<int,int>>vec; //nums1 , nums2;
      for(int i = 0 ; i<n ; i++)
      {
        vec.push_back({nums1[i] , nums2[i]});
      }  
      
      auto lambda = [](pair<int,int>&a , pair<int,int>&b)
      {
        return a.second>b.second;
      };
      sort(vec.begin() , vec.end() , lambda);
      long long Ksum = 0;
      long long result = INT_MIN;
      for(int i = 0 ; i<=k-1 ; i++)
      {
        Ksum+=vec[i].first;
        pq.push(vec[i].first);
      }
        result = Ksum * vec[k-1].second;
        for(int  i = k ; i<n ; i++)
        {
            Ksum+= vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            result = max(result , Ksum*vec[i].second);
        }
        return result;

    }
};








//DP soln

class Solution {
public:
    int K;
    int n;
    priority_queue<int , vector<int> , greater<int>>pq; //minheap
    void removefrom_pq(int num)
    {
        vector<int>temp;
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if(x==num)
            {
                break;
            }
            temp.push_back(x);
        }
        for(int & y : temp)
        {
            pq.push(y);
        }
    }

    int solve(int i , vector<int>& nums1 , vector<int>& nums2 , int sum , int min , int count  )
    {
          if(count == K)
        {
            return sum*min;
        }

        if(i>=n)
        {
            return 0;
        }
        
        pq.push(nums2[i]);
        int take_i = solve(i+1, nums1 , nums2 , sum+nums1[i] , pq.top() , count+1 );
        removefrom_pq(nums2[i]);
        int not_take = solve(i+1 , nums1 , nums2 , sum , min , count );

        return max(take_i , not_take);

    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
         n = nums1.size();
         K=k;
        return solve(0 , nums1 , nums2 , 0 , 0 , 0 ); //sum , min , count , n
    }
};
