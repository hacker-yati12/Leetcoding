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
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
            slow=slow->next;
        ListNode* prev=NULL,*curr=slow,*nextp;
        while(curr!=NULL)
        {
            nextp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextp;
        }
        while(head!=NULL && prev!=NULL)
        {
            if(head->val==prev->val)
            {
                head=head->next;
                prev=prev->next;                    
            }
            else
                return false;
        }
        return true;
    }
};