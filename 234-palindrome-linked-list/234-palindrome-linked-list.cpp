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
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head,*slow=head,*mid;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
            mid=slow->next;
        else
            mid=slow;
        ListNode *prev=NULL,*next;
        while(mid!=NULL)
        {
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }
        while(prev!=NULL)
        {
            if(head->val!=prev->val)
                return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};