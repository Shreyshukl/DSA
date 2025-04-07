class Solution {
public:
  bool isPrime(int num) {
    if (num < 2) return false; // 0 and 1 are not primes
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // found a divisor → not prime
    }
    return true; // no divisors → it's prime
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>result = {-1,-1};
        vector<int>arr;
        for(int i = left ; i<=right ; i++)
        {
            if(isPrime(i))
            {
                arr.push_back(i);
            }
        }
       
        if(arr.size()==1)
        {
            return result;
        }
        
        int min_diff = INT_MAX;
        for(int i = 0 ; i<arr.size() ; i++)
        {
            for(int j = 0 ;j<arr.size() ; j++)
            {
                if(i==j)
                {
                    continue;
                }
                int diff = abs(arr[j]-arr[i]);
                if(diff<min_diff)
                {
                    min_diff = diff;
                    result[0] = arr[i];
                    result[1] = arr[j];
                }
            }
        }
      
        return result;
    }
};
