class Solution {
    public:
      int minCost(vector<int>& height) {
          int n = height.size();
          if(n==1)
          {
              return 0;
          }
          int prevStep = 0;                    //cost to reach first stair
          int prevJump = abs(height[1]-height[0]); //cost to reach 2st stair
          
          for(int i=2 ; i<n ;i++)
          {
              int onestep = prevJump+abs(height[i] - height[i-1]);
              int twoStep = prevStep+abs(height[i] - height[i-2]);
              
              int currstep = min(onestep , twoStep);
              
              prevStep = prevJump;
              prevJump = currstep;
          }
          return prevJump; //cost to reach the n-1 stair
      }
  };
