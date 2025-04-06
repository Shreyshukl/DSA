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
