
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>vec(26,0);
        int i = 0 ;
        int longestString = 0;
        int maxfreq = 0;
        for(int j = 0 ; j<n ; j++)
        {
            vec[s[j]-'A']++;
            maxfreq = max(maxfreq , vec[s[j]-'A']);

            int len = j-i+1;
            int changes = len - maxfreq;
            if(changes>k)
            {
                vec[s[i]-'A']--;
                i++;
            }
            longestString = max(longestString,j-i+1);
            //dubara j-i+1 liya kyunki ab i bdl gya h
        }
        return longestString;
    }
};



//brute force(tle)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int longestSubstring = 0;
        //sari substring generate krke check kro
        for(int i = 0 ; i<n ; i++)
        {
            vector<int>vec(26,0);
            int maxfreq = 0;
            for(int j = i ; j<n ; j++)
            {
                vec[s[j]-'A']++;
                maxfreq = max(maxfreq , vec[s[j]-'A']);

                int len = j-i+1;
                int changes = len-maxfreq;
                
                if(changes<=k)
                {
                    longestSubstring = max(longestSubstring , len);
                }
            } 
        }
        return longestSubstring;
    }
};
