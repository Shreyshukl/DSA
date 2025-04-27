class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
        {
            return "";
        }
        int n = s.length();
        int reqCount = t.length();
        int window = INT_MAX;
        unordered_map<char,int>mp;
        for(char ch : t)
        {
            mp[ch]++;
        }
        int i = 0 , j = 0 , start_point = 0;
        while(j<n)
        {
            if(mp[s[j]]>0)
            {
                reqCount--;
            }
            mp[s[j]]--;
            while(reqCount==0)
            {
                int currWindowSize = j-i+1;
                if(currWindowSize<window)
                {
                    window = currWindowSize;
                    start_point = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    reqCount++;
                }
                i++; 
            }
            j++;
        }
        return window == INT_MAX?"":s.substr(start_point ,window);
    }
};
