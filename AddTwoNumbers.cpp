#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head{ new ListNode() };
    ListNode* curr{ head };
    unsigned int carry{ 0 };

    // Add the value of the digits
    while (l1 || l2)
    {
        // Calculate value of current digit
        unsigned int val{ (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry };
        carry = (int)(val / 10);
        // Add current digit
        ListNode* digit{ new ListNode(val % 10) };
        curr->next = digit;
        curr = curr->next;
        // Iterate lists
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry) curr->next = new ListNode(1);
    return head->next;
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
    ListNode* l1_2{ new ListNode(2) };
    ListNode* l1_4{ new ListNode(4) };
    l1_2->next = l1_4;
    ListNode* l1_3{ new ListNode(3) };
    l1_4->next = l1_3;
    std::cout << "L1: ";
    printList(l1_2);

    ListNode* l2_5{ new ListNode(5) };
    ListNode* l2_6{ new ListNode(6) };
    l2_5->next = l2_6;
    ListNode* l2_4{ new ListNode(4) };
    l2_6->next = l2_4;
    std::cout << "L2: ";
    printList(l2_5);

    std::cout << "Sum: ";
    printList(addTwoNumbers(l1_2, l2_5));
}