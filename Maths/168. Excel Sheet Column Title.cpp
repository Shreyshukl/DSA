class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int,char>mp;
        for(int i = 0 ; i<26 ; i++)
        {
            mp[i+1] = 'A'+i;
        }  
        string result;
        int a = columnNumber;
        while(a!=0)
        {
           int digit = a%26;
           if(digit==0)
           {
            result+='Z';
            a = (a/26 )- 1;
           }
           else
           {
            result+=mp[digit];
             a = a/26;
           } 
        }
        reverse(result.begin() , result.end());
        return result;
    }
};
