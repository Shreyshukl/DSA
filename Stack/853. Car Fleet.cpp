class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars(n);
        // Calculate the time to reach the target for each car
        for(int i = 0 ; i<n ; i++)
        {
            cars[i]={position[i] , (double)(target-position[i])/speed[i]};
        }
        //Once a car catches up to someone in front, it inherits that car’s time to the finish line — even if it’s faster.
        sort(cars.rbegin(),cars.rend()); 
        int carFleet = 0;
        double prevTime = 0;
        for(int i = 0 ; i < n ; i++)
        {
            double currentTime = cars[i].second;
            //mtlb agr isko jyada time lgega to y purane vale se catchup nhi kr payegi 
            if(currentTime>prevTime)
            {
                carFleet++;
            //update prevTime so that the next car can compare against this new front-runner.
                prevTime=currentTime;
            }
        }
        return carFleet;
    }
};
