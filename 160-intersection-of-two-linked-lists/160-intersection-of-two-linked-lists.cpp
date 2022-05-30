/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int A_len=0,B_len=0;
        ListNode *tempA=headA;
        while(tempA!=NULL)
        {
            A_len++;
            tempA=tempA->next;
        }
        ListNode *tempB=headB;
        while(tempB!=NULL)
        {
            B_len++;
            tempB=tempB->next;
        }
        int diff=abs(A_len-B_len);
        tempA=headA;
        tempB=headB;
        if(A_len>B_len)
            while(diff-->0)
                tempA=tempA->next;
        else
            while(diff-->0)
                tempB=tempB->next;
        while(tempA!=tempB)
        {
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==NULL || tempB==NULL)
            {
                return NULL;
            }
        }
        return tempA;
    }
};