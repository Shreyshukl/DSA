class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin() , people.end());
        int i = 0 , j = n-1;
      
        int boats = 0;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                boats+=1;
              
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit)
            {
                boats+=1;
                
                j--;
            }
            else
            {
                return boats;
            }
        }
        return boats;
    }
};
