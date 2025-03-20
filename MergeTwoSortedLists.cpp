#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* curr{ new ListNode() };
    ListNode* ans{ curr };
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;
    return ans->next;
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
    ListNode* list1_3{ new ListNode(4) };
    ListNode* list1_2{ new ListNode(2, list1_3) };
    ListNode* list1_1{ new ListNode(1, list1_2) };
    std::cout << "List 1" << std::endl;
    printList(list1_1);

    ListNode* list2_3{ new ListNode(4) };
    ListNode* list2_2{ new ListNode(3, list2_3) };
    ListNode* list2_1{ new ListNode(1, list2_2) };
    std::cout << "List 2" << std::endl;
    printList(list2_1);

    ListNode* ans{ mergeTwoLists(list1_1, list2_1) };
    printList(ans);
}