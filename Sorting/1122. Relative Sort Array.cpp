//using custom lambda
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //using custom lambda

        unordered_map<int,int>mp;
        for(int i = 0 ; i<arr2.size() ; i++)
        {
            mp[arr2[i]]=i;
        }
       
       for(int i = 0 ; i<arr1.size() ; i++)
       {
          if(!mp.count(arr1[i]))
          {
            mp[arr1[i]] =1e9;
          }
       }
        auto lambda = [&](int num1 , int num2)
        {
            if(mp[num1] == mp[num2])
            {
                return num1<num2;
            }
            return  mp[num1]<mp[num2];
        };
       sort(arr1.begin() , arr1.end() , lambda);
       return arr1;
    }
};

// using counting sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //using count Sort
        int n = arr2.size();
        int m = arr1.size();
        vector<int>result;
        map<int,int>mp;
        for(int i = 0 ; i<m ; i++)
        {
            mp[arr1[i]]++;
        }
        int index = 0;
       for(int num : arr2)
       {
        if(mp.find(num)!=mp.end())
        {
            while(mp[num]>0)
            {
                result.push_back(num);
                mp[num]--;
            }
            mp.erase(num);
        }
       }
       for(pair<int,int>it : mp)
       {
        while(it.second>0)
        {
            result.push_back(it.first);
            it.second--;
        }
       }
        return result;
    }
};
