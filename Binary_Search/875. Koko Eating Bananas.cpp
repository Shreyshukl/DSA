class Solution {
public:
//sort isliye nhi kiya kyunki agr manlo 6 banana 1 ghnte m kha skta h to use zyada bhi kha he lega 
    bool canEat(vector<int>& piles, int mid , int h)
    {
        int n = piles.size();
        int actualHours = 0;
        for(int i = 0 ; i<n ; i++)
        {
            actualHours+=piles[i]/mid;
            if(piles[i]%mid!=0)
            {
                actualHours++;
            }
        }
        return actualHours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1; //minimum 1 banana to khayegi hr ghante
        int r = *max_element(piles.begin() , piles.end());
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(canEat(piles,mid,h))
            {
                r = mid; // r is a possible answer
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};
