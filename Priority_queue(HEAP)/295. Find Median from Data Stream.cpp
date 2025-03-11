class MedianFinder {
public:
    priority_queue<int>Left_max_heap;
    priority_queue<int , vector<int> , greater<int>>Right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(Left_max_heap.empty()||Left_max_heap.top()>num)
       {
        Left_max_heap.push(num);
       }
       else
       {
        Right_min_heap.push(num);
       }
       if(abs((int)Left_max_heap.size()-(int)Right_min_heap.size())>1)
       {
            Right_min_heap.push(Left_max_heap.top());
            Left_max_heap.pop();
       } //left max heap ko hmesha bda rkhna h
       else if(Right_min_heap.size()>Left_max_heap.size())
       {
           Left_max_heap.push(Right_min_heap.top());
           Right_min_heap.pop();
       }
    }
    
    double findMedian() {
        if(Left_max_heap.size()==Right_min_heap.size())
        {
            double result = (Left_max_heap.top()+Right_min_heap.top())/2.0;
            return result;
        }
        return Left_max_heap.top();
    }
};
// Brute force (TLE)
class MedianFinder {
public:
    vector<int>result;
    int n;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       result.push_back(num);
       sort(result.begin(),result.end());
    }
    
    double findMedian() {
        n = result.size();
        int l = 0;
        int r = n-1;
         int mid = l+(r-l)/2;
        if(result.size()%2==0)
        {
            double a = result[mid];
            double b = result[mid+1];
            double ans = (a+b)/2;
            return ans;
        }
        return result[mid];
    }
};

