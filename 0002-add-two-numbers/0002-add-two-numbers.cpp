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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode();
        ListNode* head = node;
        int carry = 0;
        int sum = l1->val + l2->val + carry;
        head->val = sum % 10;
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != NULL && l2 != NULL) {
            ListNode* temp = new ListNode();
            int sum = l1->val + l2->val + carry;
            temp->val = sum % 10;
            head->next = temp;
            carry = sum / 10;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            ListNode* temp = new ListNode();
            int sum = l1->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            head->next = temp;
            head = head->next;
            l1 = l1->next;
        }

        while(l2 != NULL) {
            ListNode* temp = new ListNode();
            int sum = l2->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            head->next = temp;
            head = head->next;
            l2 = l2->next;
        }
        if(carry) {
            ListNode* temp = new ListNode();
            temp->val = carry;
            head->next = temp;
        }
        return node;
    }
};