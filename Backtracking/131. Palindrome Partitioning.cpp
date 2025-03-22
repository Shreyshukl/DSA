class Solution {
public:
    int n;
    vector<vector<string>>result;
    bool ispallindrome(string&s , int i , int j)
    {
        if(i>=j)
        {
            return true;
        }
        if(s[i]!=s[j])
        {
            return false;
        }
        return ispallindrome(s,i+1,j-1);
    }
    void solve(vector<string>&temp , string s , int idx)
    {
        if(idx>=n)
        {
            result.push_back(temp);
            return;
        }
        for(int i = idx ; i<n ; i++)
        {
            if(ispallindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(temp , s , i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
       n = s.size();
       vector<string>temp;
       solve(temp , s , 0);
       return result;
    }
};
