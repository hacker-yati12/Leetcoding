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
    ListNode * reverse(ListNode* head,int left, int right)
    {
        ListNode* prev=NULL,*curr=head,*nextptr;
        while(curr!=NULL && left<=right)
        {
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            left++;
        }
    head->next=curr;
    return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL)
            return NULL;
        if(left==1){
            return reverse(head,left,right);
    }
    int c=1;
    ListNode* curr=head,*temp;    
    while(curr!=NULL && c<left)
    {
        if(c==left-1)
            temp=curr;
        curr=curr->next;
        c++;
    }
    temp->next=reverse(curr,left,right);
    return head;
    }
};