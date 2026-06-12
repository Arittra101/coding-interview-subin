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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) return head;

        ListNode* temp = head;
        ListNode* prv = head;

        while (temp != nullptr) {

            if (prv->val != temp->val) {
                prv->next = temp;
                prv = temp;
            }

            if (temp->next == nullptr) {
                if (prv->val != temp->val) {
                    prv->next = temp;
                    temp = nullptr;
                } else {
                    prv->next = nullptr;
                }
            }


            temp = temp->next;
        }

        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return nullptr;
        ListNode* current = head;

        while (current->next != nullptr) {

            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};