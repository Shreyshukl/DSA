//Approach 1 using deque
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        int n = q.size();
        deque<int>dq;
        while(k!=0)
        {
            int p = q.front();
            q.pop();
            dq.push_front(p);
            k--;
        }
        while(!q.empty())
        {
            int s = q.front();
            q.pop();
            dq.push_back(s);
        }
        while(!dq.empty())
        {
            int a = dq.front();
            dq.pop_front();
            q.push(a);
        }
        
        return q;
    }
};
//Approach 2 using Stack
class Solution
{
    public:
        queue<int> modifyQueue(queue<int> q, int k) {
        int n = q.size();
        stack<int>st;
        for(int i = 0 ; i<k ; i++)
        {
            int a = q.front();
            q.pop();
            st.push(a);
        }
        while(!st.empty())
        {
            int a = st.top();
            st.pop();
            q.push(a);
        }
        int remaining = n - k;
        while(remaining!=0)
        {
            int a = q.front();
            q.pop();
            q.push(a);
            remaining--;
        }
        return q;
    }
};

