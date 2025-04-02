class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n =points.size();
        //min(dx,dy)+abs(dx-dy);
        int point = 0;

        for(int i = 0 ; i<n-1 ; i++)\
        {
            int x1 = points[i][0];
            int x2 = points[i+1][0];

            int y1 = points[i][1];
            int y2 = points[i+1][1];

            int dx = abs(x2-x1);
            int dy = abs(y2-y1);

            point+= (min(dx,dy)+abs(dy-dx));
        }
        return point;

    }
};
