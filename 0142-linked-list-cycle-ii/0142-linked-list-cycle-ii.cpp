/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        // ListNode* ans;
        // int c=0;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
                // ans=slow;
                // c=1;
            }
        }
        return nullptr;
        // if(c==0)
        // return nullptr;
        
        // int cnt=0;
        // fast=head;
        // while(fast!=nullptr){
        //     if(fast==slow)return cnt;

        //     cnt++;
        //     fast=fast->next;
        
    }
};