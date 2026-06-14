#include <unordered_map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//solution using unordermap, O(n) time complexity and O(n) space complexity
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        std::unordered_map<ListNode *, int> tra;

        while (temp != nullptr)
        {
            tra[temp] = 1;
            if (tra[temp->next] == 1) return true;
            temp = temp->next;
        }

        return false;
    }
};

//optimal solution using Floyd's cycle detection algorithm (tortoise and hare algorithm)
// time complexity: O(n) and space complexity: O(1) 
class Solution{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fastNode = head;
        ListNode *slowNode = head;

        while (fastNode != nullptr && fastNode->next != nullptr)
        {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;

            if (slowNode == fastNode)
                return true;
        }

        return false;
    }
};
