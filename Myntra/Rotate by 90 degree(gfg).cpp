class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
          int n = mat.size();
          
          //transpose
          for(int i = 0 ; i<n ; i++)
          {
              for(int j=i+1 ; j<n ; j++)
              {
                  swap(mat[i][j] , mat[j][i]);
              }
          }
          
          
          for(int j = 0 ; j<n ; j++)
          {
              int top = 0 ; int bottom = n-1;
              while(top<bottom)
              {
                  swap(mat[top][j] , mat[bottom][j]);
                  top++;
                  bottom--;
              }
          }
    }
};
