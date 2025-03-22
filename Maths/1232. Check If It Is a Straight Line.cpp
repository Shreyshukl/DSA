class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int dy = coordinates[1][1] - coordinates[0][1];
        int dx = coordinates[1][0] - coordinates[0][0];

        for(int i = 2 ; i<n ; i++)
        {
            int dy1 = coordinates[i][1]-coordinates[0][1];
            int dx2 = coordinates[i][0]-coordinates[0][0];

            if(dy*dx2 != dy1*dx)
            {
                return false;
            }
        }
        return true;
    }
};
