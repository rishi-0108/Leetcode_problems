/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* head = list1->val <= list2->val ? list1 : list2;

        ListNode* first = list1;
        ListNode* second = list2;

        if (head == list1)
            first = first->next;
        else
            second = second->next;

        ListNode* tail=head;

        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                tail->next = first;
                first = first->next;
                tail=tail->next;
            } else {
                tail->next = second;
                second = second->next;
                tail=tail->next;
            }
        }

        while (first != nullptr) {
            tail->next = first;
            first = first->next;
            tail=tail->next;
        }
        while (second != nullptr) {
            tail->next = second;
            second = second->next;
            tail=tail->next;
        }
        return head;
    }
};