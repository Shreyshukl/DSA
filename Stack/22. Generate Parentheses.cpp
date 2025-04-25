//better
class Solution {
public:
 
    vector<string>result;
    void solve(string&k , int n ,int open , int close)
    {
        if(k.length()==2*n)
        {
            result.push_back(k);
            return;
        }
        if(open<n)
        {
        k.push_back('(');
        solve(k,n , open+1 , close);
        k.pop_back();
        }
       if(close<open)
       {
        k.push_back(')');
        solve(k,n ,open , close+1);
        k.pop_back();
       }
    }
    vector<string> generateParenthesis(int n) {
        string k = "";
        int open = 0 ;
        int close = 0;
        solve(k,n,open,close);
        return result; 

    }
};

//using stack  O(2^2n * 2n)

class Solution {
public:
    bool isValid(string &k , int n)
    {
        stack<char>st;
        for(char ch : k)
        {
            if(ch=='(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty())
                {
                    return false;
                    
                }
                st.pop();
            }
        }
        return st.empty();
    }
    vector<string>result;
    void solve(string&k , int n)
    {
        if(k.length()==2*n)
        {
            if(isValid(k,n))
            {
                result.push_back(k);
            }
            return;
        }
        k.push_back('(');
        solve(k,n);
        k.pop_back();

        k.push_back(')');
        solve(k,n);
        k.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string k = "";
        solve(k,n);
        return result; 

    }
};
