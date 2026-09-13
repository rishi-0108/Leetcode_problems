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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next==nullptr)return head;
        

        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }

        k=k%n;

        if(k==0)return head;
        temp=head;
        int c=1;
        while(c != (n-k)){
            temp=temp->next;
            c++;
        }

        ListNode* nextnode=temp->next;
        ListNode* newhead=nextnode;
        temp->next=nullptr;
        while(nextnode->next != nullptr){
            nextnode=nextnode->next;
        }
        nextnode->next=head;
        return newhead;
    }
};