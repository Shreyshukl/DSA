class Solution {
public:
    int n;
    void deletefromRight(string &senate , char ch  , vector<bool>&removed ,int idx)
    {
        while(true)
        {
            if(senate[idx]==ch && removed[idx]==false)
            {
               removed[idx]=true;
               break;
            }
            idx = (idx+1)%n;
        }
    }
    string predictPartyVictory(string senate) {
        n =senate.length();
        vector<bool>removed(n,false);

        int countR = count(senate.begin() , senate.end() , 'R');
        int countD = n - countR;

        int idx = 0;
        while(countR>0 && countD>0)
        {
            if(removed[idx]==false)
          {
            if(senate[idx]=='R')
            {
                deletefromRight(senate , 'D' , removed ,  (idx+1) % n);
                countD--;
            }
            else
            {
                deletefromRight(senate , 'R' , removed , (idx+1) % n);
                countR--;
            }
          }
            idx = (idx+1) % n ;
        }
        return (countR==0)? "Dire" : "Radiant";  
    }
};
