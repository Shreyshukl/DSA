class Solution {
public:
    int pivotInteger(int n) {
        vector<long long> Prefix1(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            Prefix1[i] = Prefix1[i - 1] + i;
        }

        vector<long long> Prefix2(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            Prefix2[i] = Prefix2[i + 1] + i;
        }

        for (int i = 1; i <= n; i++) {
            if (Prefix1[i] == Prefix2[i]) {
                return i;
            }
        }
        return -1;
    }
};
//o(n) with no extra space

class Solution {
public:
    int pivotInteger(int n) {
        int CompleteSum = n*(n+1)/2;
        for(int i = 1 ; i<=n ; i++)
        {
            int p = i;
            int leftSum = p*(p+1)/2;
            int rightSum = CompleteSum - leftSum+p;

            if(leftSum == rightSum)
            {
                return p;
            }
        }
        return -1;
    }
};

