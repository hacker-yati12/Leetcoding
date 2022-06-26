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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;            
        }
        slow=slow->next;
        ListNode *nextptr,*curr=slow,*prev=NULL;
        while(curr!=NULL)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        //cout<<head->val<<" "<<slow->val;
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