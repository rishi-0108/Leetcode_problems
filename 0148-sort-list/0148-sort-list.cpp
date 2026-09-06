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
    ListNode* midnode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergelist(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)temp->next=list1;
        else temp->next=list2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        //base case :
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* mid=midnode(head);
        ListNode* right=mid->next;
        mid->next=nullptr;
        ListNode* left=head;

        left=sortList(left);
        right=sortList(right);

        return mergelist(left,right);
    }
};