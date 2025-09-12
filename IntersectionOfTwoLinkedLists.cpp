#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode* head)
{
    // Get length of linked list
    int len{ 0 };
    ListNode* node{ head };
    while (node)
    {
        ++len;
        node = node->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    const int len_a{ getLength(headA) };
    const int len_b{ getLength(headB) };
    ListNode* node_a{ headA };
    ListNode* node_b{ headB };
    // Start both iterators at same distance from list end
    const int advance{ len_a - len_b };
    if (advance > 0) // Start A closer to the end
        for (int i = 0; i < advance; ++i)
            node_a = node_a->next;
    else if (advance < 0)// Start B closer to the end
        for (int i = 0; i < -advance; ++i)
            node_b = node_b->next;
    // Run through the remainder of the lists until they are equal or run out
    while (node_a && node_b)
    {
        if (node_a == node_b) return node_a;
        node_a = node_a->next;
        node_b = node_b->next;
    }
    return nullptr;
}

