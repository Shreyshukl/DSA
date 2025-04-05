class Solution {
public:
  
    int eachpointSum(int num)
    {
        int powerSum = 0; 
        for(int i=2 ; i*i<=num ; i++)
        {
           
            while(num%i==0)
            {
                num = num/i;
               powerSum++;
            }
        }
        if(num!=1)
        {
           powerSum++; 
        }
        return powerSum;
    }
	int sumOfPowers(int a, int b){
	    int result = 0;
	    for(int i=a ; i<=b ; i++)
	    {
	        result+=eachpointSum(i);
	    }
	    return result;
	}
};
