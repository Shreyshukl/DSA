class Solution {
public:
    /*
    fact 1 : operation  = parts-1
    fact 2 : no ko bde se bde part m todna h taki vo jldi khtm ho aur vo i+1 vala he hoga
    fact 3 : no ko tod to diya lekin best combination kaunsa hoga
    */
    long long minimumReplacement(vector<int>& nums) {
        //peeche se traverse krnege jo glt case mila vhi se operation chalu
        int n = nums.size();
        long long operations  = 0;
        for(int i = n-2 ; i>=0 ; i--)
        {
            if(nums[i]<=nums[i+1]) // yhi to condn banai h
            {
                continue;
            }
            int parts =nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0)
            {
                parts++;
            }
            operations+=parts-1;
            nums[i] = nums[i]/parts;
        }
        return operations;
    }
};
