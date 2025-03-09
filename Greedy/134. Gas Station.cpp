class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int kamai = accumulate(gas.begin(),gas.end() ,0);
        int kharch = accumulate(cost.begin() , cost.end(),0);
        if(kharch>kamai)
        {
            return -1;
        }
        int total = 0 , result = 0;

        for(int i = 0; i<n; i++) 
        {
            total = total + gas[i]-cost[i] ;
            if(total<0) //is station se start kiya agr to kharch zyada hojayega kamai se
            {
                total = 0 ;
                result = i+1; //y nhi h , aage vala hoskta h 
            }
        }
          return result;  
            
        }
};

