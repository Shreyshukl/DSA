class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n =  happiness.size();
        sort(happiness.rbegin() , happiness.rend());
        long long result = 0;
        if(k>0)
        {
            result+= happiness[0];
            k--;
        }
        int i = 1;
        while(k!=0)
        {
            int val =  happiness[i]-i;
            if(val>=0)
            {
                result+=val;
            }
            k--;
            i++;
        }
        return result;
    }
};
