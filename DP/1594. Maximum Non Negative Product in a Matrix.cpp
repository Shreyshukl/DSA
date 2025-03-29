class Solution {
public:
    int MOD = 1e9+7;
    int m , n ;
    typedef long long ll;
    vector<vector<pair<ll ,ll>>>t;
    pair<ll ,ll> solve(int i , int j ,  vector<vector<int>>& grid)
    {
        if(i==m-1 && j==n-1)
        {
            return {grid[i][j] , grid[i][j]};
        }
        ll maxval = LLONG_MIN;
        ll minval = LLONG_MAX;
        if(t[i][j] != make_pair(LLONG_MIN , LLONG_MAX))
        {
            return t[i][j];
        }
        //down
        if(i+1<m)
        {
            auto [downMax,downMin] = solve(i+1 , j ,grid);
            maxval = max({maxval , grid[i][j]*downMax , grid[i][j]*downMin});
            minval = min({minval , grid[i][j]*downMax , grid[i][j]*downMin});
        }
        //right
        if(j+1<n)
        {
            auto [rightMax,rightMin] = solve(i , j+1 ,grid);
            maxval = max({maxval , grid[i][j]*rightMax , grid[i][j]*rightMin});
            minval = min({minval , grid[i][j]*rightMax , grid[i][j]*rightMin});
        }

        return t[i][j]={maxval , minval};

    }
    int maxProductPath(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
       t = vector<vector<pair<ll , ll>>>(m , vector<pair<ll ,ll>>(n, {LLONG_MIN,LLONG_MAX}));

        auto [maxProduct , minProduct] = solve(0 , 0 , grid);
        return maxProduct<0 ? -1 : maxProduct%MOD;
    }
};
