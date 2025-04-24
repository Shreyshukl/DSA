//brute force
class Solution {
public:
    int m,n;
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
       
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                int up = (i>0) ? mat[i-1][j]:-1;
                int down = (i<m-1) ? mat[i+1][j]:-1;
                int left = (j>0) ? mat[i][j-1]:-1;
                int right = (j<n-1) ? mat[i][j+1]:-1;

                if(mat[i][j]>up&&
                   mat[i][j]>down&&
                   mat[i][j]>left&&
                   mat[i][j]>right)
                   {
                    return {i,j};
                   }
            }
        }
        return {};
    }
};
//O(m log(n))
class Solution {
public:
    int m,n;
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int l = 0 , r = n-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            //max val in mid col i.e maxrow
            int maxrow = 0;
            for(int i = 0 ; i<m ; i++)
            {
                if(mat[i][mid]>mat[maxrow][mid])
                {
                    maxrow=i;
                }
            }
            int left  = mid-1>=0 ? mat[maxrow][mid-1]:-1;
            int right = mid+1<n ? mat[maxrow][mid+1]:-1;

            if(mat[maxrow][mid]>left&&mat[maxrow][mid]>right)
            {
                return{maxrow,mid};
            }
            else if(mat[maxrow][mid]<left)
            {
                r = mid-1; 
            }
            else
            {
                l = mid+1;
            }
        }
        return {}; 
    }
};
