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
    ListNode* reverseList(ListNode* head) {
        /*

        brute force : tc - o(n) , sc - o(n)

        stack<int> st;
        ListNode* temp=head;
        while(temp != nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp != nullptr){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;

        */

        // optimal , sc - o(1) , changing the links

        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr != nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};