class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* slow = head;
       ListNode* fast = head;
       for(int i = 0 ; i<n ; i++)
       {
            if(fast==NULL)return NULL;
            fast = fast->next;
       }
         if(fast==NULL)
        {
             ListNode*node_to_be_deleted=head;
             head=head->next;
             delete(node_to_be_deleted);
             return head;
        }
       while(fast->next!=NULL)
       {
        slow = slow->next;
        fast = fast->next;
       }
        ListNode*node_to_be_deleted=slow->next;
        slow->next = slow->next->next;
        delete(node_to_be_deleted);
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == NULL)
      {
        return NULL;
      }  
      int length = 0;
      ListNode*temp = head;
      while(temp!=NULL)
      {
        length++;
        temp = temp->next;
      }
      int dele = length-n+1;
      if(dele == 1)
      {
        ListNode*nodetodel = head;
        head = head->next;
        delete(nodetodel);
        return head;
      }
       ListNode*curr = head;
      for(int i = 1 ; i<dele-1 ; i++)
      {
        curr = curr->next;
      }
      ListNode*nodetodel = curr->next;
      curr->next = curr->next->next;
      delete(nodetodel);
      return head;
    }
};
