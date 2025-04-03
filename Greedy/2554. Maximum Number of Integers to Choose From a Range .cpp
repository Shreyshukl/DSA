class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       unordered_set<int>st(banned.begin() , banned.end());
       vector<int>temp;
       for(int i = 1 ; i<=n ; i++)
       {
         if(st.find(i)==st.end())
         {
            temp.push_back(i); //pura end tk chla gya pr use y element nhi mila
         }
       } 
       int count = 0;
       int sum=0;
       for(int i = 0 ; i<temp.size() ; i++)
       {
            sum+=temp[i];
         
            if(sum>maxSum)
            {
                return count;
            }
            count++;
       }
       return temp.size();
    }
};
