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
    ListNode* reverse(ListNode* list)
    {
        ListNode* prev=NULL,*curr=list,*nextp=NULL;
        while(curr!=NULL)
        {
            nextp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1),l2=reverse(l2);
        int sum=0,carry=0;
        ListNode* temp1=l1;
        ListNode* end;
        bool trig1=false,trig2=false;
        while(l1!=NULL && l2!=NULL)
        {
            int num1=l1->val,num2=l2->val;
            if(trig1==true)
                num1=0;
            if(trig2==true)
                num2=0;
            //cout<<l1->val<<" "<<l2->val<<endl;
            //cout<<carry<<endl;
            sum=num1+num2;
            sum+=carry;
            l1->val=sum%10;
            carry=sum/10; 
            if(l1->next==NULL)
            {
                l1->next=l2->next;
                trig1=true;
            }
            if(l2->next==NULL)
            {
                l2->next=l1->next;
                trig2=true;
            }
            if(l1->next==NULL)
                end=l1;
            //cout<<l1->val<<" "<<l2->val<<" "<<end->val<<endl;
            l1=l1->next;
            l2=l2->next;
        }
        //cout<<carry;
        if(carry>0)
        {
            ListNode* new_node=new ListNode();
            new_node->val=carry;
            end->next=new_node;
            new_node->next=NULL;
        }
        return reverse(temp1);
    }
};