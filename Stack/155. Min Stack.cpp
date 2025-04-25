class MinStack {
public:
    stack<int>st;
    stack<int>minSt; //stores the min val of the stack
    MinStack() {
        
    }
    void push(int val) {
        if(minSt.empty()||val<=minSt.top())
        {
            minSt.push(val);
        }
        st.push(val);
    }
    
    void pop() {
      if(minSt.top() == st.top())
      {  
        minSt.pop();
      }
      st.pop();   
    }
    
    int top() {
      return st.top();  
    }
    
    int getMin() {
        return minSt.top();
    }
};
