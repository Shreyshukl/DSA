class Solution {
public:
    int n;
    vector<vector<string>>result;
 
    //t[i][j] ka mtlb i aur j length ka string pallindrome h ya nhi

    void solve(int i , string s , vector<string>&temp , vector<vector<bool>>&t)
    {
        if(i==s.length())
        {
            result.push_back(temp);
            return;
        }

        for(int j = i ; j<n ; j++)
        {
            if(t[i][j]==true)
            {
                temp.push_back(s.substr(i , j-i+1));
                solve(j+1,s,temp,t);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       n = s.size();
       vector<vector<bool>>t(n,vector<bool>(n,false));
       for(int L= 1 ; L<=n ; L++)
       {
        for(int i = 0 ; i+L-1<n ; i++)
        {
            int j = i+L-1;
            if(i==j)
            {
                t[i][j] = true;
            }
            else if(i+1==j)
            {
                t[i][j] = s[i]==s[j];
            }
            else
            {
                t[i][j] = s[i]==s[j]&&t[i+1][j-1];
            }
        }
       }
       vector<string>temp;
       solve(0 , s , temp , t);
       return result;
    }
};
