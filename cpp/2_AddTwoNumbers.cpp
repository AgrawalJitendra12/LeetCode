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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tempHead = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *curr = tempHead;
        int carry = 0;
        int x = 0;
        int y = 0;
        int sum = 0;
        
        while (p != NULL || q != NULL) 
        {
            if(p != NULL)
            {
                x = p->val;
            }
            else
            {
                x = 0;    
            }
            if(q != NULL)
            {
                y =  q->val;
            }
            else
            {
                y = 0;
            }
            sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != NULL)
            {
                p = p->next;
            }
            if (q != NULL)
            {
                q = q->next;
            }
        }
        if (carry > 0) 
        {
            curr->next = new ListNode(carry);
        }
        return tempHead->next;
    }
};