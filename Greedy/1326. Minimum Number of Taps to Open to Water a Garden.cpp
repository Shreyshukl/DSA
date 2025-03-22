class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> vec;

        // Create intervals for each tap
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            vec.push_back({left, right});
        }

        // Sort by starting point
        sort(vec.begin(), vec.end());

        int tap = 0;
        int target = 0;
        int i = 0;

        while (target < n) {
            int maxRight = -1;

            // Find the farthest reach from the current position
            while (i < vec.size() && vec[i].first <= target) {
                maxRight = max(maxRight, vec[i].second);
                i++;
            }

            if (maxRight == -1) {
                return -1;  // Impossible to cover the garden
            }

            tap++;
            target = maxRight;

            if (target >= n) {
                return tap;
            }
        }

        return tap;
    }
};









class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int>StartEnd(n+1, 0);

        for(int i = 0 ; i<ranges.size() ; i++)
        {
            int start = max(0 , i-ranges[i]);
            int end   = min(i+ranges[i] , n);
            StartEnd[start] = max(StartEnd[start] , end);
        }

        int tap = 0;
        int currend = 0;
        int maxend = 0;
        for(int i = 0 ; i<=n ;i++)
        {
            if(i>maxend)
            {
                return -1; //margya pura garden nhi water hua tha
            }
            if(i>currend)
            {
                tap++; //currend khtm hogya tum fir bhi aage chle aye iska mtlb tap khola hoga;
                currend = maxend;
            }
            maxend = max(maxend , StartEnd[i]);
        }
        return tap;
    }
};
