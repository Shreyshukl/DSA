class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int solve(int curr, int clip, int n) {
        if (curr > n) return 1e9;     // too many A’s
        if (curr == n) return 0;      // goal reached

        int res = 1e9;

        // Option 1: Copy All (only if clip != curr to avoid useless copy)
        if (curr != clip)
            res = min(res, 1 + solve(curr, curr, n));

        // Option 2: Paste (only if clipboard has content)
        if (clip > 0)
            res = min(res, 1 + solve(curr + clip, clip, n));

        return res;
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        return solve(1, 0, n);  // start with 1 A on screen, clipboard empty
    }
};
