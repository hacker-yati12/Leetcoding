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
    ListNode* reversed(ListNode* head, ListNode* prev, ListNode* curr) {
        if(curr->next == NULL) {
            curr->next = prev;
            return curr;
        }
        ListNode* forw = curr->next;
        curr->next = prev;
        return reversed(head, curr, forw);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reversed(head, prev, curr);
    }
};