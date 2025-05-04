class Solution {
  public:
    string findLargest(vector<int> &arr) {
        int n  = arr.size();
        
        auto lambda = [](int &a , int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);
            
            if(s1+s2>s2+s1)
            {
                return true;
            }
            return false;
        };
        
        sort(arr.begin() , arr.end() , lambda);
         if(arr[0]==0)
         {
             return "0";
         }
         
         string result = "";
         for(int it : arr )
         {
             result+=to_string(it);
         }
         return result;
         
    }
};
