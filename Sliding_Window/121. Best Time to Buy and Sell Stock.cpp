class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int mini = prices[0];
        for(int i = 1 ; i<n ; i++)
        {
            maxProfit = max(maxProfit , prices[i]-mini);
            mini = min(mini , prices[i]);
        }
        return maxProfit;
    }
};
//brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=  prices.size();
        int maxProfit = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if(prices[j]>prices[i])
                {
                    maxProfit = max(maxProfit , prices[j]-prices[i]);
                }
            }
        }
        return maxProfit;
    }
};
