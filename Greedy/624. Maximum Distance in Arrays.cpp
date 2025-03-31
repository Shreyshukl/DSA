class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
       
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int final = 0;
        for(int i = 1 ; i<n ; i++)
        {
            final = max(final , abs(mini - arrays[i].back()));
            final = max(final , abs(maxi - arrays[i].front()));

            mini = min(mini , arrays[i].front());
            maxi = max(maxi , arrays[i].back());

        }

        return final;
    }
};
