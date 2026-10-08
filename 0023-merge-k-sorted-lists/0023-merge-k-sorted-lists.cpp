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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        ListNode* head = nullptr;
        int mini = INT_MAX;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr && lists[i]->val < mini) {
                head = lists[i];
                mini = lists[i]->val;
            }
        }
        if (head == nullptr)
            return nullptr;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == head)
                lists[i] = lists[i]->next;
        }
        if (head == nullptr)
            return nullptr;
        ListNode* temp = head;
        int cond = 0;
        while (cond != INT_MAX) {
            int nextmin = INT_MAX;
            int minind = 0;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < nextmin) {
                    nextmin = lists[i]->val;
                    minind = i;
                }
            }
            if (nextmin == INT_MAX)
                break;
            temp->next = lists[minind];
            lists[minind] = lists[minind]->next;
            temp = temp->next;

            cond = nextmin;
        }
        return head;
    }
};