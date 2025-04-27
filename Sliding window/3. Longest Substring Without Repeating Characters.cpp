class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();
      int maxlen = 0;
      int i = 0;
      unordered_set<int>st;
        for(int j=0 ; j<n ; j++)
        {
            while(st.find(s[j])!=st.end())
            {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxlen = max(maxlen,j-i+1);
        } 
        return maxlen;
    }
};
