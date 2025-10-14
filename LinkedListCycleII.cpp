#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode *head)
{
    if (!head || !head->next) return nullptr;
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!slow) return nullptr;

    ListNode* start{ head };
    while (start && slow)
    {
        if (start == slow) return start;
        start = start->next;
        slow = slow->next;
    }
    return nullptr;
}
