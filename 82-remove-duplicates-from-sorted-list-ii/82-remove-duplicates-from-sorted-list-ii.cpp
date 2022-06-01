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
   ListNode* deleteDuplicates(ListNode* head) {
        if(head ==NULL || head->next==NULL ) 
            return head;
        ListNode* curr= head;
        ListNode* prev = head;
        while( curr!= NULL && curr->next != NULL)
        {
            if( curr== head && curr->next->val==curr->val)
            {
                while( curr!=NULL &&curr->val == head->val)
                {
                    curr = curr->next;
                }
                if( curr== NULL){
                    return NULL;
                }
                head = curr;
            }
            else if( curr->next!=NULL && curr->next->val==curr->val)
            {
                while( curr!=NULL && prev->next->val == curr->val)
                {
                    curr= curr->next;
                }
                if( curr == NULL)
                {
                    prev->next== NULL;
                }
                prev->next = curr;
            }
            else
            {
                prev= curr;
                curr= curr->next;
            }
        }
        return head;
    }
};