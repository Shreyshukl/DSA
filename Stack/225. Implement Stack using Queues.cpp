//using single queue
class MyStack {
public:
    queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
       for(int i = 0 ; i<q.size()-1 ; i++)
       {
         q.push(q.front());
         q.pop();
       }
    }
    
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
//using 2 queue
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q2,q1); 
    }
    
    int pop() {
        int a = q1.front();
        q1.pop();
        return a;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
