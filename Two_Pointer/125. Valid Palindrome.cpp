class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string k = "";
        for(char c : s)
        {
            if(isalnum(c))
            {
                k+=tolower(c);
            }
        }
        int i = 0 , j = k.size()-1;
        while(i<=j)
        {
            if(k[i]!=k[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
