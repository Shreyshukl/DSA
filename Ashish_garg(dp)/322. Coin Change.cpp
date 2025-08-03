class Solution {
public:
    int dp[13][100001];
    int solve(int i , int n , int  amount ,vector<int>&coins)
    {
        if(amount==0) //  amount bn gya , mujhe aur coins ki zarurat nhi h to 0 coins lgenge ab  
        {
            return 0;
        }
         // amount 0 se km hogya mtlb koi galat coin add kiya jisne amount ko surpass kr diya
         // index greater than eqaul to n hogya mtlb coins khtm hogye aur maine amount bhi nhi bnaya
        if(amount < 0 || i>=n)
        {
            return 1e9;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }

        int take = 1+ solve(i , n , amount-coins[i] ,  coins);
        int skip = solve(i+1 , n , amount ,  coins);

        return dp[i][amount]=min(take , skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp , -1 , sizeof(dp));
        int count = 0;
        int ans =  solve(0 , n , amount , coins);
        return ans>=1e9 ? -1 : ans;
    }
};
