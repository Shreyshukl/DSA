class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
            int n = arr.size();
            
           sort(arr.begin() , arr.end());
           sort(dep.begin() , dep.end());
           
           int i = 1; //arrival time
           int j = 0; //dep pichli ka
           int platform_needed = 1;
           int maxPlatform =1; //ayi gyi ka hisab lgane k baad dekho kitne max
           //platform lge vhi tumhara min platform honge
           
           while(i<n&&j<n)
           {
               if(arr[i]<=dep[j])
               {
                   platform_needed++;
                   i++;
               }
               else
               {
                   platform_needed--;
                   j++;
               }
               maxPlatform = max(maxPlatform , platform_needed);
           }
            return maxPlatform;
    }
};
