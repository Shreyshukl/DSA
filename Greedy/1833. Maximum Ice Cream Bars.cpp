//using count sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxIceCreams = 0;

        map<int,int>mp;

        for(int i = 0 ; i<n ; i++)
        {  
            mp[costs[i]]++;   
        }
        
        int index = 0;
        for(pair<int,int>entry : mp)
        {
           int it = entry.second;
           while(it>0)
           {
            costs[index++] = entry.first;
            it--;
           }
        }

        for(int i = 0 ; i<n ; i++)
        {
            if(costs[i]<=coins)
            {
                maxIceCreams++;
                coins-=costs[i];
            }
        }
        return maxIceCreams;
    }
};
