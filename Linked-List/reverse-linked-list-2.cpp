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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)   return head;

        int index = 1;
        std::stack<ListNode*> st;
        ListNode* forTheFirstIndex = nullptr;
        ListNode* lastBound = nullptr;
        ListNode* leftBound = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (index >= left && index <= right)  st.push(temp);
            else if (index == right + 1)  lastBound = temp;
            else if (index == left - 1) leftBound = temp;
            temp = temp->next;
            index++;
        }
        temp = head;
        ListNode* prv = nullptr;
        index = 1;
        if(leftBound!=nullptr)   prv = leftBound;
        while (!st.empty()) {
            ListNode* st_top = st.top();
            st.pop();
            if (prv != nullptr) prv->next = st_top;
            if (index == 1) forTheFirstIndex = st_top;
        
            st_top->next = nullptr;
            prv = st_top;
            index++;
        }

        if(lastBound!=nullptr) prv->next = lastBound;
        if(leftBound==nullptr) head = forTheFirstIndex;
        return head;
    }
};