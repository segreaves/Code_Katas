#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if (!head) return head;
    ListNode* odd{ head };
    ListNode* even{ head->next };
    ListNode* even_head{ even };

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
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
    std::cout << "Should be 1, 3, 5, 2, 4: ";
    ListNode* ans1{ oddEvenList(list1_1) };
    printList(ans1);

    ListNode* list2_7{ new ListNode(7) };
    ListNode* list2_6{ new ListNode(4, list2_7) };
    ListNode* list2_5{ new ListNode(6, list2_6) };
    ListNode* list2_4{ new ListNode(5, list2_5) };
    ListNode* list2_3{ new ListNode(3, list2_4) };
    ListNode* list2_2{ new ListNode(1, list2_3) };
    ListNode* list2_1{ new ListNode(2, list2_2) };
    std::cout << "List 2: ";
    printList(list2_1);
    std::cout << "Should be 2, 3, 6, 7, 1, 5, 4: ";
    ListNode* ans2{ oddEvenList(list2_1) };
    printList(ans2);
}