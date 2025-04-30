class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int  m = matrix.size();
        int  n = matrix[0].size();
        int result = 0;
        for(int sr = 0 ; sr<m ; sr++)
        {
            for(int sc = 0 ; sc<n ; sc++)
            {
                for(int er = sr ; er<m ; er++)
                {
                    for(int ec = sc; ec<n ; ec++)
                    {
                        int sum = 0;
                        for(int i = sr ;i<=er  ;i++)
                        {
                            for(int j = sc ; j<=ec ; j++)
                            {
                                sum+=matrix[i][j];
                                
                            }
                        }
                        if(sum == target)
                        {
                         result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};
