class Solution {
public:
    bool isPossible(int force , vector<int>& pos , int m )
    {
        int prev = pos[0];
        int balls = 1;

        for(int i = 1 ; i<pos.size() ; i++)
        {
            int curr = pos[i];
            if(curr-prev>=force)
            {
                //hm ball ko place krskte h
                balls++;
                prev = curr;
            }
            if(balls==m)
            {
                break;
            }
        }
        return balls==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin() , position.end());
        int minForce = 1;
        int maxForce = position[n-1]-position[0];
        int result = 0;
        while(minForce<=maxForce)
        {
            int midforce = minForce+(maxForce-minForce)/2; 
            if(isPossible(midforce , position , m))
            {
                result = midforce;
                minForce = midforce+1;
            }
            else
            {
                maxForce = midforce-1;
            }
        }
        return result;
    }
};
