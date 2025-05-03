class Solution {
public:

    void operation(stack<int>&st , stack<char>&op)
    {
        int b = st.top(); st.pop();
        int a = st.top(); st.pop();
        
        char ope = op.top(); op.pop();
        
        if(ope=='+')
        {
            st.push(a+b);
        }
        else if(ope=='-')
        {
            st.push(a-b);
        }
        else if(ope=='*')
        {
            st.push(a*b);
        }
        else if(ope=='/')
        {
            st.push(a/b);
        }
    }
    int precedence(char oper)
    {
        if(oper=='+'||oper=='-')
        {
            return 1;
        }
        else if(oper=='*'||oper=='/')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
   

    int calculate(string s) {
      int n = s.length();
      stack<int>st; //num store
      stack<char>op; //operator store
      int num = 0;
      
      for(int i = 0 ; i<n ; i++)
      {
          char ch = s[i];
          
          if(isdigit(ch))
          {
            num = num*10+ch-'0';  
          }
          
          if(!isdigit(ch)||i==n-1)
          {
              st.push(num);
              num = 0;
              
              while(!op.empty() && precedence(op.top())>=precedence(ch))
              {
                  operation(st,op);
              }
              if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
              {
                  op.push(ch);
              }
          }
      }
      return st.top();
    }
};
