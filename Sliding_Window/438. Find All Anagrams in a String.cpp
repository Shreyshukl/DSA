class Solution {
public:
    bool allZero(vector<int>&vec)
    {
        for(int &i:vec)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        if(n>n)
        {
            return {};
        }
        vector<int>vec(26,0);
        for(int i=0 ; i<n ; i++)
        {
            char ch = p[i];
            vec[ch-'a']++;
        }
        int i = 0 , j = 0;
        vector<int>result;
        while(j<m)
        {
            vec[s[j]-'a']--;
            if(j-i+1==n)
            {
                if(allZero(vec))
                {
                    result.push_back(i);
                }
                vec[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};
