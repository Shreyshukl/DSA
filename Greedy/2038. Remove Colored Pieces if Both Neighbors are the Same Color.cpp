class Solution {
public:
    bool winnerOfGame(string colors) {
       int n = colors.length();
       if(n<=2)
       {
        return false;
       } 
       int countA=0;
       int countB=0;
       for(int i = 1 ; i<n-1 ; i++)
       {
            if(colors[i]=='A')
            {
                if(colors[i-1]=='A' && colors[i+1]=='A')
                {
                    countA++;
                }
            }
            else if(colors[i]=='B')
            {
                 if(colors[i-1]=='B' && colors[i+1]=='B')
                {
                    countB++;
                }
            }  
       }
       if(countA>countB)
       {
        return true;
       }
       return false;
    }
};
