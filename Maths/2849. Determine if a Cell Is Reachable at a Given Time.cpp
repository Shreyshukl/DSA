class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       int HD = abs(fy-sy); //horizontalDistance
       int VD = abs(fx-sx); //verticalDistance

       if(HD==0&&VD==0&&t==1)
       {
        return false; //same grid m ho 
       }

       int minTime = max(HD,VD);

       return  t < minTime ? false : true; 


    }
};
