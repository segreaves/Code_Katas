#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* curr{ new ListNode() };
    curr->next = head;
    ListNode* tortoise{ curr };
    ListNode* hare{ curr->next };

    for (int i = 0; i < n; i++) hare = hare->next;

    while (hare)
    {
        tortoise = tortoise->next;
        hare = hare->next;
    }

    tortoise->next = tortoise->next->next;
    return curr->next;
}

void printList(ListNode* head)
{
    ListNode* curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode* list1_5{ new ListNode(5) };
    ListNode* list1_4{ new ListNode(4, list1_5) };
    ListNode* list1_3{ new ListNode(3, list1_4) };
    ListNode* list1_2{ new ListNode(2, list1_3) };
    ListNode* list1_1{ new ListNode(1, list1_2) };
    std::cout << "List 1: ";
    printList(list1_1);
    std::cout << "Removed n = 2: ";
    printList(removeNthFromEnd(list1_1, 2));

    ListNode* list2_2{ new ListNode(2) };
    ListNode* list2_1{ new ListNode(1, list2_2) };
    std::cout << "List 2: ";
    printList(list2_1);
    std::cout << "Removed n = 2: ";
    printList(removeNthFromEnd(list2_1, 2));
}