class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       priority_queue<pair<int,char>>pq; // maxheap
       if(a>0)
       {
        pq.push({a,'a'});
       }
       if(b>0)
       {
        pq.push({b,'b'});
       }
       if(c>0)
       {
        pq.push({c,'c'});
       }

       string result="";

     while(!pq.empty())
    {
        int  currCount = pq.top().first;
        char currChar = pq.top().second;
        pq.pop();

      if(result.size()>=2 && result[result.size()-1]==currChar && result[result.size()-2]==currChar)
      {
        if(pq.empty())
        {
            break;
        }
        int nextcount = pq.top().first;
        char nextchar = pq.top().second;
        pq.pop();
        result+=nextchar;
        nextcount--;
        if(nextcount>0)
        {
            pq.push({nextcount ,nextchar });
        }
      }
      else
      {
        result+=currChar;
        currCount--;
      }

     if(currCount>0)
     {
        pq.push({currCount,currChar});
     }
   }
       return result;
    }
};
