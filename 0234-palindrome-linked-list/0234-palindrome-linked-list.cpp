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
    bool isPalindrome(ListNode* head) {
        /*

        brute force - o(n) sc
        
        stack<int> st;
        ListNode* temp=head;
        while(temp != nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp != nullptr){
            if(temp->val != st.top())return false;
            st.pop();
            temp=temp->next;
        }
        return true;
        
        */

        //optimal : o(1) sc : use slow fast to find mid then reverse from mid then compare 1st half and second half

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr != nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        // comparison begins
        ListNode* temp=head;
        while(prev != nullptr){
            if(prev->val != temp->val)return false;
            prev=prev->next;
            temp=temp->next;
        }
        return true;
    }
};