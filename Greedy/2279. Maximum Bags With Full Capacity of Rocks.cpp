class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        int maxBagfull = 0;
        vector<int>remainingCapacity(n);

        for(int i = 0 ; i<n ; i++)
        {
            remainingCapacity[i] = capacity[i]-rocks[i];
        }
        sort(remainingCapacity.begin() , remainingCapacity.end());
        int j = 0; 
        while(additionalRocks!=0&&j<n)
        {
            if(remainingCapacity[j]<=additionalRocks)
            {
                maxBagfull++;
                additionalRocks -= remainingCapacity[j];
            }
            j++;
        }
        return maxBagfull;
    }
};
