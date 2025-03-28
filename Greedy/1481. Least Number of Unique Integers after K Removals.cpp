class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
       
        priority_queue<int,vector<int> , greater<int>>pq; //minheap
        for(pair<int,int> it :mp)
        {
            pq.push(it.second);   
        }
        
        while(!pq.empty())
        {
            k-=pq.top();
            if(k<0)
            {
                return pq.size();
            }
            pq.pop();
        }
        return 0;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
       
        vector<int>vec;
        for(pair<int,int> it :mp)
        {
            vec.push_back(it.second);
            
        }
        sort(vec.begin(),vec.end());
        for(int i = 0 ; i<vec.size() ; i++)
        {
            k-=vec[i];
            if(k<0)
            {
                return vec.size()-i;
            }
        }
        return 0;
    }
};








class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        if(n==1&&k==1)
        {
            return 0;
        }
        if(n==1&&k==0)
        {
            return 1;
        }
        unordered_map<int,int>mp;
        for(int i = 0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
        int uniq = mp.size();
        for(pair<int,int> it : mp)
        {
            if(it.second==1)
            {
                uniq--;
                k--;
                if(k==0)
                {
                    return uniq;
                }
            }
        }
        vector<int>vec;
        for(pair<int,int> it :mp)
        {
            if(it.second>1)
            {
                vec.push_back(it.second);
            }
        }
        sort(vec.begin(),vec.end());
        for(int f : vec)
        {
            if(k>=f)
            {
                k-=f;
                uniq--;
            }
            else
            {
                break;
            }
        }
       
        return uniq;
    }
};
