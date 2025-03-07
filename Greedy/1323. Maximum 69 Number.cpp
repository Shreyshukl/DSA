class Solution {
public:
    int maximum69Number (int num) {
       // 6 ko 9 bnane k liye 3 chahiye
       int placevalue = 0;
       int placevalueofSix = -1;
       int temp = num;
       while(num!=0)
       {
        int rem  =num%10;
        if(rem == 6)
        {
            placevalueofSix = placevalue;
        }
        num = num/10;
        placevalue++;
       }
       if(placevalueofSix==-1)
       {
        return temp;
       }
       return temp+3*pow(10,placevalueofSix);
    }
};
//approach 2

class Solution {
public:
    int maximum69Number (int num) {
        string a = to_string(num);
        int n = a.length();
        for(int i = 0 ; i<n ; i++)
        {
            if(a[i]=='6')
            {
                a[i]='9';
                break;
            }
        }
        return stoi(a);
    }
};
