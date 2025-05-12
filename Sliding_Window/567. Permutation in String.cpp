class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<int>window1(26,0); 
        vector<int>window2(26,0);
        int i = 0;

        for(char ch : s1)
        {
            window1[ch-'a']++;
        }

        for(int j = 0 ; j<n ;j++)
        {
            window2[s2[j]-'a']++;
            if(j-i+1>m)
            {
                window2[s2[i]-'a']--;
                i++;
            }

            if(window1==window2)
            {
                return true;
            }
        }
        return false;
    }
};
