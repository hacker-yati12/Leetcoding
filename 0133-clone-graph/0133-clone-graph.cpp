/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp;
    void dfs (Node* node) {
        Node* copy = new Node(node->val);
        mp[node] = copy;
        for (auto nb: node->neighbors) {
            if (mp.find(nb) != mp.end())
                copy->neighbors.push_back(mp[nb]);
            else {
                dfs(nb);
                copy->neighbors.push_back(mp[nb]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        dfs(node);
        return mp[node];
    }
};