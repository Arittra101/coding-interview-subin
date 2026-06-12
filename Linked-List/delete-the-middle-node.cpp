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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        int md = n / 2;
        if (md == 0)return nullptr;

        ListNode* prv = head;
        temp = head;
        n = 0;
        while (temp != nullptr) {
            if (n == md) {
                prv->next = temp->next;
                break;
            }
            prv = temp;
            temp = temp->next;
            n++;
        }

        return head;
    }
};