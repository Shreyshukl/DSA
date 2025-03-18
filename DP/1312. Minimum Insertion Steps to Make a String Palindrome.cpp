//top-dowm
class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , string &s)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            dp[i][j]=solve(i+1,j-1,s);
        }
        else
        {
            dp[i][j]=1+min(solve(i+1,j,s),solve(i,j-1,s));
        } 
        return dp[i][j];
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return solve(0,n-1,s);
    }
};







//bottom-up(blueprint)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
     vector<vector<int>> t(n, vector<int>(n, 0));
     //t[i][j] = means string i se leke j tk hme kitne insertion krne pde
     //agr i==j h mtlb same char h to kitna insertion 0 isiliye t[0][0]=0;
        
        for(int L=2 ; L<=n ; L++) //kyunki 1 length m kya insertion
        {
            for(int i = 0 ; i+L-1<n;i++)
            {
                int j = i+L-1;
                if(s[i]==s[j])
                {
                    t[i][j] = t[i+1][j-1]; //agr equal h to koi insertion nhi aage bdho 
                }
                else
                {
                    t[i][j] = 1+min(t[i+1][j] , t[i][j-1]);
                }
            }
        }
        return t[0][n-1]; //pure string jo thi 0 se n-1 unme kitne insertion kiye;
    }
};
