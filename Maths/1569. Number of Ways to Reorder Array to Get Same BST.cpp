class Solution {
public:
    long long MOD = 1e9+7;
    vector<vector<long long>>PT;
    int solve(vector<int>& nums)
    {
        int n = nums.size();
        if(n<3)
        {
            return 1; 
        }
        int root = nums[0];
        vector<int>leftArray , rightArray;
        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i]<root)
            {
                leftArray.push_back(nums[i]);
            }
            else
            {
                rightArray.push_back(nums[i]);
            }
        }
        long long x = solve(leftArray);
        long long y = solve(rightArray);

        long long z = PT[n-1][leftArray.size()]; //nCr

        return (((x*y)%MOD*z))%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        PT.resize(n+1); //n+1 row bnayi kyunki zero index

        for(int i = 0 ; i<n ; i++)
        {
            PT[i] = vector<long long>(i+1 , 1); //hr row m i+1 elements honge
            for(int j = 1 ; j<i ; j++)
            {
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%MOD;
            }
        }
        return (solve(nums)-1)%MOD; //kyunki og array ko nhi lena combination m
    }
};
