class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
       string result;
       for(char ch : s)
       {
          mp[ch]++;
       }
       priority_queue<pair<int,char>>maxHeap;

       for(pair<char,int>it : mp)
       {
            char a = it.first;
            int b = it.second;
            maxHeap.push({b,a});
       }
       while(!maxHeap.empty())
       {
            pair<int,char> top = maxHeap.top();
            maxHeap.pop();
            result.append(top.first,top.second);
       }
       return result;
    }
};
