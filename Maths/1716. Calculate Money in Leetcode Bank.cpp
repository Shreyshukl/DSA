class Solution {
public:
    int totalMoney(int n) {
        int result = 0 ;
        int monday_money = 1;
        while(n>0)
        {
          int money=monday_money;
         for(int i = 1 ; i<=min(n,7) ; i++)
        {
           result+=money;
           money++;
        }
        n-=7;
        monday_money++;
        }
        return result;
    }
};
