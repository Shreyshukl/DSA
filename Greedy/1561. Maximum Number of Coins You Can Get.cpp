class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int result = 0;
        int b = 0;
        int m = n-2;
        int a = n-1;

        while(m>b)
        {
            result+=piles[m];
            a-=2;
            m-=2;
            b++;
        }
        return result;
    }
};
