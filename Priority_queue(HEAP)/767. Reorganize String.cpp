class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        string result="";
        for(char ch : s)
        {
            mp[ch]++;
        }
        for(pair<char,int>it:mp)
        {
           if(it.second>(n+1)/2)
           {
            return "";
           }
        }
       priority_queue<pair<int,char>>pq; //maxheap
       for(pair<char ,int>it : mp)
       {
        pq.push({it.second , it.first});
       }
       while(pq.size()>=2)
       {
        pair<int,char> a = pq.top();
        pq.pop();
        pair<int,char> b = pq.top();
        pq.pop();

        result+=a.second;
        result+=b.second;

        a.first--;

        if(a.first>0)
        {
            pq.push(a);
        }

        b.first--;

        if(b.first>0)
        {
            pq.push(b);
        }
       }
       if(!pq.empty())
       {
        pair<int,char>a = pq.top();
        pq.pop();
        result+=a.second;
       }
       return result;
    }
};
