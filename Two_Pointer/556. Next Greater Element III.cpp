class Solution {
public:
    int nextGreaterElement(int n) {
       string result = to_string(n);
       string to_check = result;
       int N = result.size();
       int dip = -1;
       //find dip
       for(int i = N-2 ; i>=0 ; i--)
       {
            if(result[i]<result[i+1])
            {
                dip = i;
                break;
            }
       }
       if(dip!=-1)
       {
            for(int i = N-1 ; i>dip ; i--)
            {
                if(result[i]>result[dip])
                {
                   swap(result[i], result[dip]);
                   reverse(result.begin()+dip+1 , result.end());
                   break;
                }
            }
       }
       else
       {
        reverse(result.begin() , result.end());
        if(result <= to_check)
        {
            return -1;
        }
       }

       long long ans = stoll(result);
       return(ans>INT_MAX)?-1 : int(ans);
       
    }
};
