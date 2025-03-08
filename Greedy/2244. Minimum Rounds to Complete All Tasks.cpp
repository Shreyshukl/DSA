class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n =tasks.size();
        unordered_map<int,int>mp;
        int rounds = 0;
        for(int i = 0 ; i<n ; i++)
        {
            mp[tasks[i]]++;
        }
       for(pair<int,int>entry : mp)
       {
            int count = entry.second;
            if(count == 1)
            {
                return -1;
            }
            if(count%3==0)
            {
                rounds+=count/3;
            }
            else
            {
                //every no can be represented in form of 3k , 3k+1 , 3k+2.
                rounds+=count/3+1;
            }  
       }
       return rounds;
    }
};
