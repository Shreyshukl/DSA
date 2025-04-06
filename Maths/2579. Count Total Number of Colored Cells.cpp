class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1;
        for(int i = 2 ; i<=n ; i++)
        {
            result=result+4*(i-1);
        }
        return result;
    }
};
