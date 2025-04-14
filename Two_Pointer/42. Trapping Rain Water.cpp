class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i = 0;
        int j = n-1;
        int leftMax = 0 , rightMax = 0;
        int water = 0;
        while(i<j)
        { 
            if(height[i]<height[j])
            {
                if(height[i]>=leftMax)
                {
                    leftMax = height[i];
                }
                else
                {
                    water+=leftMax-height[i];
                }
                i++;
            }
            else
            {
                if(height[j]>=rightMax)
                {
                    rightMax = height[j];
                }
                else
                {
                    water+=rightMax-height[j];
                }
                j--;
            }
        }
        return water;
    }
};
//approach 2
class Solution {
public:
vector<int>leftMaxArray(vector<int>&height,int n)
{
  vector<int>leftmax(n);
  leftmax[0]=height[0];
  for(int i=1;i<n;i++)
  {
  leftmax[i]=max(leftmax[i-1],height[i]);
  }
  return leftmax;
}
vector<int>rightMaxArray(vector<int>&height,int n)
{
  vector<int>rightMax(n);
  rightMax[n-1]=height[n-1];
  for(int i=n-2;i>=0;i--)
  {
  rightMax[i]=max(rightMax[i+1],height[i]);
  }
  return rightMax;
}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax=leftMaxArray(height,n);
        vector<int>rightMax=rightMaxArray(height,n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
          int h=min(leftMax[i],rightMax[i])-height[i];
          sum+=h;
        }
        return sum;
    }
};
