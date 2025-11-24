/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        Node* newHead = NULL;
        Node* curr = NULL;
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            if (newHead == NULL) {
                newHead = newNode;
                curr = newHead;
            } else {
                curr->next = newNode;
                curr = curr->next;
            }
            temp = temp->next;
        }
        
        temp = head;
        while(temp) {
            if(temp->random == NULL)
                mp[temp]->random = NULL;
            else
                mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return newHead;
    }
};