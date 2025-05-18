class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int CurrUnsatisfied = 0;
        int maxUnsatisfied =  0;

        for(int i = 0; i<minutes ; i++)
        {
            CurrUnsatisfied+= customers[i]*grumpy[i];
        }
        maxUnsatisfied = CurrUnsatisfied;
        int i = 0 ; 
        int j = minutes;
        while(j<n)
        {
            CurrUnsatisfied+=customers[j]*grumpy[j];
            CurrUnsatisfied-=customers[i]*grumpy[i];
            maxUnsatisfied = max(maxUnsatisfied ,CurrUnsatisfied);
            i++;
            j++;
        }
        int totalSatisfied = maxUnsatisfied;
        for(int i = 0 ; i<n ; i++)
        {
            if(grumpy[i]==0)
            {
                totalSatisfied+=customers[i];
            }
        }
        return totalSatisfied;
    }
};
