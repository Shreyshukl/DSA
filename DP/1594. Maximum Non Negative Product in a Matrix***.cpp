class Solution {
public:
    int MOD = 1e9+7;
    int m , n ;
    typedef long long ll;
   
    int maxProductPath(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
      vector<vector<pair<ll ,ll>>>t(m , vector<pair<ll,ll>>(n));
      t[0][0] = {grid[0][0] , grid[0][0]}; //maxval ,minval
      //t[i][j] = {maxval,  minval} from 0,0 to i,j;
     //filling first col
     for(int j = 1 ; j<n ; j++)
     {
        t[0][j].first = t[0][j-1].first * grid[0][j];
        t[0][j].second = t[0][j-1].second * grid[0][j];
     }
      //filling first row
     for(int i = 1 ; i<m ; i++)
     {
        t[i][0].first = t[i-1][0].first * grid[i][0];
        t[i][0].second = t[i-1][0].second * grid[i][0];
     }

     for(int  i = 1 ; i<m ; i++)
     {
        for(int j = 1 ; j<n ; j++)
        {
            ll uppermax = t[i-1][j].first;
            ll uppermin = t[i-1][j].second;

            ll leftmax = t[i][j-1].first;
            ll leftmin = t[i][j-1].second;

       t[i][j].first = max({uppermax*grid[i][j] ,uppermin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});
       t[i][j].second = min({uppermax*grid[i][j] ,uppermin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});
        }
     }
     auto [maxproduct , minprod] = t[m-1][n-1];
     if(maxproduct<0)
     {
        return -1;
     }
     return maxproduct%MOD;

    }
};


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
