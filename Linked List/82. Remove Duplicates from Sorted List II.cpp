
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            if(curr->next!=NULL&&curr->val==curr->next->val)
            {
                int dupVal = curr->val;
                while(curr!=NULL && curr->val == dupVal)
                {
                    curr = curr->next;
                }
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};




class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        map<int,int>mp;
        while(temp!=NULL)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        for(auto it = mp.begin() ; it!=mp.end() ; it++)
        {
            int val = it->first;
            int count = it->second;
            if(count==1)
            {
                current->next = new ListNode(val);
                current = current->next;
                
            }
        }
      return dummy->next;
    }
};
