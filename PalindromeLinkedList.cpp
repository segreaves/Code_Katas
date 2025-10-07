#include <iostream>

struct ListNode
{
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

bool isPalindrome(ListNode* head)
{
    // Get the size of the list
    unsigned int list_size{ 0 };
    ListNode* curr{ head };
    while (curr)
    {
        ++list_size;
        curr = curr->next;
    }
    if (list_size == 1) return true;
    // Save the middle of the list
    unsigned int middle{ list_size % 2 == 0 ? list_size / 2 : (list_size / 2) + 1 };
    // Set pointer to start of list
    ListNode* first{ head };
    // Set pointer to middle of list
    ListNode* second{ head };
    unsigned int count{ 0 };
    while (count++ < middle) second = second->next;
    // Save middle location for list reset
    ListNode* second_saved{ second };
    // Reverse list from middle onwards
    second = reverseList(second);
    // Traverse both lists (first and second) and check if values are equal
    while (first && second)
    {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }
    // If reached this point then the original list is a palindrome
    // Now must reset to the original list
    reverseList(second_saved);
    return true;
}

int main()
{
    ListNode* l1_4{ new ListNode(1) };
    ListNode* l1_3{ new ListNode(2, l1_4) };
    ListNode* l1_2{ new ListNode(2, l1_3) };
    ListNode* l1_1{ new ListNode(1, l1_2) };
    std::cout << "l1: ";
    printList(l1_1);
    std::cout << isPalindrome(l1_1) << "\n";
}