#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        std::stack<ListNode*> node;
        ListNode* tempNode  = head;
        
        while(tempNode!=nullptr){
            node.push(tempNode);
            tempNode = tempNode->next;
        }

        if(node.empty())
        {
            return nullptr;
        }

        head = node.top();
        node.pop();

        tempNode = head;

        while(!node.empty()){
         head -> next = node.top();
         node.pop();
         head = head->next;
        }
        head->next = nullptr;
        return tempNode;

    }
};