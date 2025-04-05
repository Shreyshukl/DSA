class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        vector<int>vec(26,0);
        for(int i = 0 ; i < n ; i++)
        {
            vec[word[i]-'a']++;
        }
        int minDeletion = n;
        for(int i = 0 ; i<26 ; i++)
        {
            int deletion = 0;
            for(int j = 0 ; j<26 ; j++)
            {
                if(i==j)
                {
                    continue;
                }
                else if(vec[j]<vec[i])
                {
                    deletion+=vec[j];
                }
                else if (abs(vec[j]-vec[i])>k)
                {
                    deletion+=abs(vec[j]-vec[i]-k);
                }
            }
            minDeletion = min(minDeletion,deletion);
        }
        return minDeletion;
    }
};
