#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode* slow{ head };
    ListNode* fast{ head };
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

int main()
{
    ListNode* list1_1{ new ListNode(3) };
    ListNode* list1_2{ new ListNode(2) };
    list1_1->next = list1_2;
    ListNode* list1_3{ new ListNode(0) };
    list1_2->next = list1_3;
    ListNode* list1_4{ new ListNode(-4) };
    list1_3->next = list1_4;
    list1_4->next = list1_2;
    std::cout << "Should be true: " << hasCycle(list1_1) << std::endl;

    ListNode* list2_1{ new ListNode(1) };
    ListNode* list2_2{ new ListNode(2) };
    list2_1->next = list2_2;
    list2_2->next = list2_1;
    std::cout << "Should be true: " << hasCycle(list2_1) << std::endl;

    ListNode* list3_1{ new ListNode(1) };
    std::cout << "Should be false: " << hasCycle(list3_1) << std::endl;
}