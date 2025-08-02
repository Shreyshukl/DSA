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

    ListNode* merge(ListNode* left , ListNode* right)
    {
        ListNode*dummy = new ListNode(-1);
        ListNode*current = dummy;

        while(left!=NULL&&right!=NULL)
        {
            if(left->val<=right->val)
            {
                current->next = left;
                left = left->next;
            }
            else{
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        while(left!=NULL)
        {
            current->next = left;
            left = left->next;
            current = current->next; 
        }
         while(right!=NULL)
        {
            current->next = right;
            right = right->next;
            current = current->next; 
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return head;
        }

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL&&fast->next!=NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left,right);

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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        vector<int>result;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            result.push_back(temp->val);
            temp = temp->next;
        }
        sort(result.begin() , result.end());
        int n = result.size();
        ListNode*dummy = new ListNode(result[0]);
        ListNode* current = dummy;
        for(int i = 1 ; i<n ;i++)
        {
            current->next = new ListNode(result[i]);
            current = current->next;
        }
        return dummy;
    }
};
