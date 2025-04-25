class Solution {
public:
    int operate(int a , int b , string&op)
    {
        if(op=="+")
        {
            return a+b;
        }
        if(op=="-")
        {
            return a-b;
        }
        if(op=="*")
        {
            return a*b;
        }
        if(op=="/")
        {
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i = 0 ; i<n ; i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = operate(b , a ,tokens[i]);
                st.push(val);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
