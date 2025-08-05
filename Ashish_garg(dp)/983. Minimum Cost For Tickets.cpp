class Solution {
public:
    int dp[366];
    int solve(int i , int n , vector<int>&days , vector<int>&cost)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int cost1 = cost[0]+solve(i+1 , n , days , cost);

        int j = i;

        while(j<n && days[j] < days[i]+7)
        {
            j++;
        }
        int cost7 = cost[1] + solve(j , n , days , cost);
        
        j = i;

        while(j<n && days[j] < days[i]+30)
        {
            j++;
        }
        int cost30 = cost[2] + solve(j , n , days , cost);


        return dp[i]=min({cost1 ,cost7 , cost30});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ans = 1e9;
        memset(dp , -1,  sizeof(dp));
        ans = min(ans,solve(0,n,days,costs));
        return ans;
    }
};
