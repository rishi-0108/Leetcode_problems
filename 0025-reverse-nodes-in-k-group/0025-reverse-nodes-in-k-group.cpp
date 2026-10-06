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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            ListNode* currentNode = temp;

            temp->next = prevNode;

            temp = nextNode;

            prevNode = currentNode;
        }
        return prevNode;
    }
    ListNode* getKthNode(ListNode* head, int k) {
        int c = 1;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (c == k)
                break;
            c++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* KthNode = getKthNode(temp, k);
            if (KthNode == nullptr) {
                if (prev)
                    prev->next = temp;
                break;
            }
            ListNode* next=KthNode->next;
            KthNode->next=nullptr;
            reverseLinkedList(temp);
            if(temp==head)
            head=KthNode;
            else
            prev->next=KthNode;

            prev=temp;
            temp=next;
        }
        return head;
    }
};