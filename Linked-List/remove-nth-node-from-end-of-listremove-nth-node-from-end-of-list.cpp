struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int nth) {
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        nth = n - nth;
        ListNode* prv = head;
        temp = head;
        n = 0;

        while (temp != nullptr) {
            if (n == nth) {
                if (nth == 0) {
                    head = head->next;
                    return head;
                }
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