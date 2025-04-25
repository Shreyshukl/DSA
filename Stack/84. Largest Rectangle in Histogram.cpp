class Solution {
public:
    vector<int>nextSmallelement(vector<int>& heights)
    {
        int n = heights.size();
        stack<int>st;
        st.push(-1);
        vector<int>result(n);
        for(int i = n-1 ; i>=0 ; i--)
        {
           while(st.top()!=-1&& heights[st.top()]>=heights[i])
            {
                st.pop(); //upar small no rkhna h hmesha;
            }
            result[i] = (st.top() == -1) ? n : st.top();
            st.push(i);
        }
        return result;
    }
     vector<int>prevSmallelement(vector<int>& heights)
    {
        int n = heights.size();
        stack<int>st;
        vector<int>result(n);
        st.push(-1);
        for(int i = 0 ; i<n ; i++)
        {
            while(st.top()!=-1&& heights[st.top()]>=heights[i])
            {
                st.pop(); //upar small no rkhna h hmesha;
            }
            result[i] = st.top();
            st.push(i);
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next = nextSmallelement(heights);
        vector<int>prev = prevSmallelement(heights);

        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            maxi = max(maxi,heights[i]*(next[i]-prev[i]-1));
        }
        return maxi;
    }
};
