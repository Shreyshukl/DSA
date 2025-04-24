class Solution {
public:
    bool canShip(vector<int>& weights , int capacity , int days)
    {
        int reqdays = 1;
        int currload = 0;
        for(int & weight : weights)
        {
            if(currload+weight>capacity)
            {
                reqdays++;
                currload = 0;
            }
            currload+=weight;
        }
        return reqdays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int l  = *max_element(weights.begin() , weights.end());
       int r  = accumulate(weights.begin() , weights.end() , 0);
       while(l<r)
       {
        int mid = l+(r-l)/2;
        if(canShip(weights , mid , days))
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
       }
       return l;
    }
};
