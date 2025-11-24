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
        ListNode* n1 = headA;
        ListNode* n2 = headB;
        int sz1 = 1, sz2 = 1;
        while(n1 != NULL) {
            n1 = n1->next;
            sz1++;
        }
        while(n2 != NULL) {
            n2 = n2->next;
            sz2++;
        }
        n1 = headA;
        n2 = headB;
        while(sz1 > sz2) {
            n1 = n1->next;
            sz1--;
        }
        while(sz2 > sz1) {
            n2 = n2->next;
            sz2--;
        }
        while (n1 != NULL && n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }
};