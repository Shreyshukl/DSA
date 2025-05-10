int m,n;
void dfs(vector<vector<char>>& grid , int i , int j)
{
    if(i<0||i>=m || j<0 ||j>=n || grid[i][j]=='W')
    {
        return;
    }
    
    if(grid[i][j]=='$')
    {
        return;
    }
    
    grid[i][j]='$';
    
    dfs(grid , i+1 , j);
    dfs(grid , i-1 , j);
    dfs(grid , i , j+1);
    dfs(grid , i , j-1);
    dfs(grid , i-1 , j-1);
    dfs(grid , i-1 , j+1);
    dfs(grid , i+1 , j-1);
    dfs(grid , i+1 , j+1);
}
class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        
        int count = 0;
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j]=='L')
                {
                    dfs(grid , i , j);
                    count++;
                }
            }
        }
        return count;
    }
};
