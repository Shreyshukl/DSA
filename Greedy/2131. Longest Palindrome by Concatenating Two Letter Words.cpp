class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int>mp;

        for(int i=0 ; i<n ; i++)
        {
            mp[words[i]]++;
        }
            bool centerUsed = false;
            int result = 0;
        for(string&word : words)
        {
            string rev = word;
            reverse(rev.begin() , rev.end());

            if(word!=rev)  //ab..ba
            {
                if(mp[word]>0 && mp[rev]>0)
                {
                    mp[word]--;
                    mp[rev]--;
                    result+=4;
                }
            }
            else   //same h (aa...aa)
            {
                if(mp[word]>=2)
                {
                    mp[word]-=2; //word same h freq 2 se zyada hue to do baar use krskte h
                    result+=4;
                }
                else if(mp[word]==1 && centerUsed==false)
                {
                    mp[word]--;
                    result+=2;
                    centerUsed=true;
                }
            }
        }
        return result;
    }
};
