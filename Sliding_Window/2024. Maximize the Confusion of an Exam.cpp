class Solution {
public:
    int helper(string &answerKey , int k , char ch)
    {
        int i = 0;
        int maxlength = 0;
        int count = 0;
        for(int j = 0 ; j<answerKey.size() ;j++)
        {
            if(answerKey[j] == ch)
            {
                count++;
            }
            while(count > k)
            {
                if(answerKey[i]==ch)
                {
                    count--;
                }
                i++;
            }
            maxlength = max(maxlength , j-i+1);
        }
        return maxlength;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey , k , 'T') , helper(answerKey , k , 'F'));
    }
};
