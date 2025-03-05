class Solution {
    public:
        void solve(int startValue , int target , int&operation)
        {
            if(startValue == target)
            {
                return ;
            }
            if(target < startValue)
            {
                operation+= startValue-target;
                return;
            }
            if(target%2==0)
            {
                operation++;
                solve(startValue,target/2,operation);
            }
            else
            {
                operation++;
                solve(startValue,target+1,operation);
            } 
        }
        int brokenCalc(int startValue, int target) {
            int operation = 0;
            solve(startValue , target ,operation);
            return operation;
        }
    };
