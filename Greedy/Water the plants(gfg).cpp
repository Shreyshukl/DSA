class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i = 0 ; i<n ; i++)
        {
            if(gallery[i]=='-1')
            {
                continue;
            }
            int left  = max(0 , i-gallery[i]);
            int right = min(i+gallery[i] , n);
            vec.push_back({left , right});
        }
        sort(vec.begin() , vec.end());
        int tap = 0;
        int target = 0;
        int i=0;
        while(target<n)
        {
            int maxright = -1;
            while(i<vec.size())
            {
            if(vec[i].first<=target)
            {
                maxright = max(maxright,vec[i].second);
                i++;
            }
            else
            {
                break;
            }
            }
           if(maxright<target)
           {
               return -1;
           }
           tap+=1;
           target=maxright+1;
        }
        return tap;
    }
};
