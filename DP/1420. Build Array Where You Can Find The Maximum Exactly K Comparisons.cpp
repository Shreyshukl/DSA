class Solution {
public:
    int dp[51][101][51];
    const int MOD = 1e9+7;
    int solve(int idx , int maxsofar , int searchCost , int n , int m , int k)
   {
        if(idx==n)
        {
            if(searchCost==k)
            {
                return 1;
            }
            else
            {
                return 0;
            }       
        }
        if(dp[idx][maxsofar][searchCost]!=-1)
        {
            return dp[idx][maxsofar][searchCost];
        }
        int result = 0;
        for(int i = 1 ; i<=m ; i++)
        {
            if(i>maxsofar)
            {
                result=(result+solve(idx+1 , i , searchCost+1 , n , m , k))%MOD;
            }
            else
            {
                result=(result+solve(idx+1, maxsofar , searchCost , n , m , k))%MOD;
            }
        }
        return dp[idx][maxsofar][searchCost] = result;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , 0 , n , m , k); //index , maxsofar , searchCost
    }
};
