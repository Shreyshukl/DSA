class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>arrivalTime;
        for(int i = 0 ; i<n ; i++)
        {
            arrivalTime.push_back(ceil((double)dist[i]/speed[i]));
        }
        sort(arrivalTime.begin() , arrivalTime.end());

        int MonstEliminated = 1;

        for(int i = 1 ; i<n ; i++)
        {
            if(i<arrivalTime[i])
            {
              MonstEliminated++;
            }
            else
            {
                break;
            }  
        }
        return MonstEliminated;
    }
};
