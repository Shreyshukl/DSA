class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0 , j = 0;
        int maxVowel = 0;
        int vowel = 0;
        while(j<n)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                vowel++;
            }
            while(j-i+1>k)
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                   vowel--; 
                }
                i++;
            }
            maxVowel = max(maxVowel , vowel);
            j++;
        }
        return maxVowel;
    }
};
