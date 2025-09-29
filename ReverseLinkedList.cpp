#include <iostream>
#include <list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* prev{ nullptr };
    while (head)
    {
        ListNode* next{ head->next };
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void printList(ListNode* head)
{
    ListNode* curr{ head };
    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode* l1_5{ new ListNode(5) };
    ListNode* l1_4{ new ListNode(4, l1_5) };
    ListNode* l1_3{ new ListNode(3, l1_4) };
    ListNode* l1_2{ new ListNode(2, l1_3) };
    ListNode* l1_1{ new ListNode(1, l1_2) };
    std::cout << "l1: ";
    printList(l1_1);
    ListNode* l1_rev{ reverseList(l1_1) };
    std::cout << "Reversed l1: ";
    printList(l1_rev);

    ListNode* l2_2{ new ListNode(2) };
    ListNode* l2_1{ new ListNode(1, l2_2) };
    std::cout << "l2: ";
    printList(l2_1);
    ListNode* l2_rev{ reverseList(l2_1) };
    std::cout << "Reversed l2: ";
    printList(l2_rev);

    ListNode* l3;
    std::cout << "l3: ";
    printList(l3);
    ListNode* l3_rev{ reverseList(l3) };
    std::cout << "Reversed l3: ";
    printList(l3_rev);
}