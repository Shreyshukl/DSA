class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      vector<int>result;
      int i=0,j=n-1;
      while(i<j)
      {
        if(numbers[i]+numbers[j]<target)
        {
            i++;
        }
        else if(numbers[i]+numbers[j]>target)
        {
            j--;
        }
        else
        {
            result.push_back(i+1);
            result.push_back(j+1);
            break;
        }
      }
      return result;
    }
};
