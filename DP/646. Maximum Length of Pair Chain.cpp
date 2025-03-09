class Solution {
public:
    int dp[1001][1001]; // Memoization table (assuming n ≤ 1000)

    int solve(int i, int prev_idx, int n, vector<vector<int>>& pairs) {
        if (i >= n) {
            return 0;
        }
        
        if (dp[i][prev_idx + 1] != -1) {
            return dp[i][prev_idx + 1];  // Return cached result
        }
        
        int take = 0;
        if (prev_idx == -1 || pairs[i][0] > pairs[prev_idx][1]) {
            take = 1 + solve(i + 1, i, n, pairs);
        }
        
        int skip = solve(i + 1, prev_idx, n, pairs);
        
        return dp[i][prev_idx + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        // Sorting pairs by the second element
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, -1, n, pairs);
    }
};
