class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
       for(int i=0 ; i<n ; i++)
       {
           mp[arr[i]]++;
       }
       
       int maxi = 0;
       int ans = arr[0];
       
      for(const pair<int,int>&it : mp)
      {
          if(it.second>=maxi)
          {
              maxi = it.second;
              ans = it.first;
          }
      }
       return ans;
        
    }
};
