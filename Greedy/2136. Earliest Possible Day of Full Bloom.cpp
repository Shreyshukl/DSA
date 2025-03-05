class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>>v(n);

        for(int i = 0 ; i<n ; i++)
        {
            v[i] = {plantTime[i] , growTime[i]};
        }
        auto lambda = [](pair<int,int>&P1 , pair<int,int>&P2)
        {
            return  P1.second>P2.second;  //decreasing order m
        };

        sort(v.begin() , v.end() , lambda); //comparator kyunki growTime k hisab se sort krna h 

        int PrevPlantDay = 0;
        int maxBloomday = 0;
        for(int i = 0 ; i<n ; i++)
        {
            int currentPlantTime = v[i].first;
            int currGrowTime     = v[i].second;
            PrevPlantDay +=   currentPlantTime;

            int currmaxBloomday = PrevPlantDay+currGrowTime;
            
            maxBloomday = max(maxBloomday,currmaxBloomday);
        }
        return maxBloomday;
    }
};
