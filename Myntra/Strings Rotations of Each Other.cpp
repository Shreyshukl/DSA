class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        if(m!=n)
        {
            return false;
        }
        string doubled = s1+s1;
        return doubled.find(s2)!=string::npos;
        
    }
};
