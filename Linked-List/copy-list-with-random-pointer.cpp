#include <unordered_map>
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

//readble and optimal solution using unorderer_map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* temp = head;
        std::unordered_map<Node*, Node*> nodeMp;

        while (temp != nullptr) {
            nodeMp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            if(temp->next) nodeMp[temp]->next = nodeMp[temp->next];
            if(temp->random) nodeMp[temp]->random = nodeMp[temp->random];
            temp = temp->next;
        }

        return nodeMp[head];
    }
};

//solution using unordermap

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* temp = head;
        std::unordered_map<Node*, Node*> nodeMp;

        while (temp != nullptr) {
            nodeMp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            if(temp->next) nodeMp[temp]->next = nodeMp[temp->next];
            if(temp->random) nodeMp[temp]->random = nodeMp[temp->random];
            temp = temp->next;
        }

        return nodeMp[head];
    }
};