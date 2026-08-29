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
    ListNode* middleNode(ListNode* head) {
        int c=0;
        ListNode* temp=head;
        while(temp != nullptr){
            c++;
            temp=temp->next;
        }
        c=c/2 + 1;
        int k=1;
        ListNode* mid=head;
        while(k!=c){
            mid=mid->next;
            k++;
        }
        return mid;
    }
};