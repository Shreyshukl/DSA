//approach 1 (TLE)
class Solution {
public:
    void solve(string&s ,int k , int i , int j , int minutes , vector<int>freq ,int &result)
    {
        if(freq[0]>=k&&freq[1]>=k&&freq[2]>=k)
        {
            result = min(result , minutes);
            return;
        }
        if(i>j)
        {
            return;
        }
        vector<int>tempLeftFreq = freq;
        tempLeftFreq[s[i]-'a']+=1;
        solve(s, k , i+1 , j , minutes+1 , tempLeftFreq , result);

        vector<int>temprightFreq = freq;
        temprightFreq[s[j]-'a']+=1;
        solve(s, k , i , j-1 , minutes+1 , temprightFreq , result);
    }
    int takeCharacters(string s, int k) {
        int n = s.length();
        int i = 0 , j = n-1;
        vector<int>freq(3,0);
        int minutes = 0;
        int result = INT_MAX;
        solve(s , k , i , j , minutes , freq , result);
        return (result==INT_MAX)?-1:result;
       
    }
};


//approach 2

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(int i = 0 ; i<n ;i++)
        {
            mp[s[i]]++;
        }
        int maxLength = 0;
        int i = 0 , j = 0 ;
        if(mp['a']<k ||mp['b']<k ||mp['c']<k)
        {
            return -1;
        }
        while(j<n)
        {
            mp[s[j]]-=1;
            while(mp[s[j]]<k &&i<=j)
            {
                mp[s[i]]+=1;
                i++;
            }
            maxLength = max(maxLength , j-i+1);
            j++;
        }
        return n-maxLength;
    }
};
