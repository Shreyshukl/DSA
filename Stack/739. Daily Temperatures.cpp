class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n);
        stack<int>st;
        //next greater element
       for(int i = 0 ; i<n ; i++)
       {
        while(!st.empty()&&temperatures[i]>temperatures[st.top()])
        {
            int previdx = st.top();
            st.pop();
            result[previdx] = i - previdx;
        }
        st.push(i);
       }
       return result; 
    }
};
