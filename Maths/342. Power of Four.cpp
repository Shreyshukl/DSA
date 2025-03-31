class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
       while(n%4==0)
       {
        n=n/4;
        if(n==1)
        {
            return true;
        }
       }
       return false;
    }
};



class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        {
            return false;
        }
        int x = (log(n)/log(4));
        
        if(n==pow(4,x))
        {
            return true;
        }
        return false;
    }
};
