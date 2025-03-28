class Solution {
public:
    long long findEqn(pair<int,int>&P1 , pair<int,int>&P2 , pair<int,int>P3)
    {
        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;

        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;

        return (y3 - y2)*(x2-x1)-(y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        sort(trees.begin() , trees.end()); //taki sbse chote/pehle cord se start kre
        deque<pair<int,int>>lower , upper;
        vector<vector<int>>result;
        for(auto&point : trees)
        {
            int l = lower.size();
            int u = upper.size();
            while(l>=2 && findEqn(lower[l-2] , lower[l-1] , {point[0],point[1]})<0)
            {
                l--;
                lower.pop_back();
            }

             while(u>=2 && findEqn(upper[u-2] , upper[u-1] , {point[0],point[1]})>0)
            {
                u--;
                upper.pop_back();
            }
            lower.push_back({point[0],point[1]});
            upper.push_back({point[0],point[1]});
        }
        //taki duplicate points na ajaye
        set<pair<int,int>>st;
        for(auto& it : upper)
        {
            st.insert(it);
        }
        for(auto& it : lower)
        {
            st.insert(it);
        }
        for(auto & it : st)
        {
            result.push_back({it.first,it.second});
        }

        return result;


    }
};
