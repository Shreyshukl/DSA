
class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
       for(int i=1 ; i<=n ; i++)
       {
         if(i<=n/i)
         {
            count++;
         }
       }
       return count;
    }
};
class Solution {
public:
    int bulbSwitch(int n) {
        //perfect square he hmesha on rrhenge
        return sqrt(n);
    }
};

//tle(brute force)
class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> bulbs(n, 0);  // Initialize all bulbs with 0 (off)
        
        // Toggle bulbs in rounds
        for (int i = 1; i <= n; i++) {  // Round i
            for (int j = i - 1; j < n; j += i) {  // Toggle every i-th bulb
                bulbs[j]++;  // Increment toggle count
            }
        }
        
        // Count bulbs toggled an odd number of times
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bulbs[i] % 2 !=0) count++;  // Odd toggle count means it's ON
        }
        
        return count;
    }
};
