class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid , int i , int j  , int&peri)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
        {
            peri++;
            return;
        }
        if(grid[i][j]==-1)
        {
            return;
        }
        grid[i][j]=-1;
        dfs(grid ,i+1 , j , peri);
        dfs(grid ,i-1 , j , peri);
        dfs(grid ,i , j+1 , peri);
        dfs(grid ,i , j-1 , peri);

        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int perimeter = 0;
       for(int i = 0 ; i<m ; i++)
       {
        for(int j = 0 ; j<n ; j++)
        {
            if(grid[i][j]==1)
            {
                dfs(grid,i,j , perimeter);
            }
        }
       }
        return perimeter;
    }
};
