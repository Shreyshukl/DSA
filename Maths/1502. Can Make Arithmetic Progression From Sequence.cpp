class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin() , arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 2 ; i<n ; i++)
        {
            
            if(arr[i]-diff!=arr[i-1])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>st(arr.begin() , arr.end());
        int mini = *min_element(arr.begin() , arr.end());
        int maxi = *max_element(arr.begin() , arr.end());

        if((maxi - mini)%(n-1)!=0)
        {
            return false;
        }
        int d = (maxi-mini)/(n-1);
        int i = 0;
       
        while(i<n)
        {
            int num = mini+i*d;
            if(st.find(num)==st.end())
            {
                return false;
            }
            i++;
        }
        return true;
    }
};
