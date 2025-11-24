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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL || head->next == NULL)
            return head;
        
        int sz = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            sz++;
        }
        if (k % sz == 0)
            return head;
        int t = sz - (k % sz);
        ListNode* pt1 = head;
        ListNode* pt2;

        for(int i = 1; i < t; i++) {
            pt1 = pt1->next;
        }
        pt2 = pt1->next;
        pt1->next = NULL;

        temp = pt2;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = head;
        return pt2;
    }
};