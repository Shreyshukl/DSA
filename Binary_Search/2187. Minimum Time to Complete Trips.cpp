//o(log n)
class Solution {
public:
    bool canComplete(vector<int>& time , long long t , int totalTrips)
    {
        long long Trip = 0;
        for(int i = 0 ; i<time.size() ; i++)
        {
            Trip+=t/time[i];
        }
        return Trip>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long l = 0;
       long long r = (long long)*min_element(time.begin() , time.end())*totalTrips;
       while(l<r)
       {
        long long mid = l+(r-l)/2;
        if(canComplete(time,mid,totalTrips))
        {
            r=mid;
        }
        else
        {
            l = mid+1;
        }
       }
       return l;
    }
};

// brute force(tle)
class Solution {
public:
    bool canComplete(vector<int>& time ,  long long t , int totalTrips)
    {
        int trips = 0;
        for(int i = 0 ; i<time.size() ; i++)
        {
            trips+=t/time[i];
        }
        return trips>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       int n = time.size();
       long long t = 1;
       while(true)
       {
        if(canComplete(time , t  , totalTrips))
        {
            return t;
        }
        t++;
       }
       return -1;
    }
};
