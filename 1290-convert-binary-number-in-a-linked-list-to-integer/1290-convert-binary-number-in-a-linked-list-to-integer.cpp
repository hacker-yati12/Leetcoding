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
    ListNode* reverse(ListNode* node)
    {
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* nxt;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head=reverse(head);
        int exp=0;
        int ans=0;
        while(head!=NULL)
        {
            if(head->val==1)
                ans+=pow(2,exp);
            exp++;
            head=head->next;
        }
        return ans;
    }
};