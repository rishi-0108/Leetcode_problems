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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next == nullptr){
            return nullptr;
        }
        int c=0;
        ListNode* temp=head;
        while(temp != nullptr){
            c++;
            temp=temp->next;
        }
        
        if(n==c){
            ListNode* temp=head;
            head=temp->next;
            temp->next=nullptr;
            delete temp;
        }
        else{
            c=c-n;
            int k=1;
            temp=head;
            while(c!=k){
                k++;
                temp=temp->next;
            }
            ListNode* nextnode=temp->next;
            temp->next=temp->next->next;
            nextnode->next=nullptr;
            delete nextnode;
        }
        
        return head;
    }
};