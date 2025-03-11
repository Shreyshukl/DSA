//simulation approach
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>result(n,0);
        sort(deck.begin() , deck.end());
        int i = 0;
        int j = 0;
        bool skip = false;

        while(i<n) //jaise he i bahar hua mtlb maine sare elements bhr diya h;
        {
            if(result[j]==0)
            {
                if(skip == false)
                {
                    result[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j+1)%n;
        }
        return result;
    }
};
// Using queue
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>result(n);

        sort(deck.begin() , deck.end());
        
        queue<int>q;
        for(int i = 0 ; i<n ; i++)
        {
            q.push(i); // q m indexes store hogye
        }
        int i = 0;
        while(!q.empty()&&i<n)
        {
            int a = q.front(); //front se index nikalo
            q.pop(); // pop kro
            result[a] = deck[i]; //result m deck ka vo particular element daalo
            i++; // i ko agle element p lejao
            q.push(q.front()); //next element ko peeche daalo
            q.pop(); //aur front se hta do
        }
        return result;
        
    }
};
