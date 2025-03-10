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
