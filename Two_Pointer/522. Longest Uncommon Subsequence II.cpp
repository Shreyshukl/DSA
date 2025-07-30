class Solution {
public:

    bool isSubsequence(string&a , string&b)
    {
        int s = a.size();
        int t = b.size(); 

        int i = 0 , j = 0;
        while(i<s&&j<t)
        {
            if(a[i]==b[j])
            {
                i++;
            }
            j++;
        }
        return i==s;
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin() , strs.end() , [](const string&a , string&b)
        {
            return a.size()>b.size();
        });

        for(int i = 0 ; i<n ; i++)
        {
            bool Uncommon = true;
            for(int j = 0 ; j<n ; j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(isSubsequence(strs[i] , strs[j]))
                {
                    Uncommon = false;
                    break;
                }
            }
            if(Uncommon)
            {
                return strs[i].size();
            }
        }
        return -1;  
    }
};
