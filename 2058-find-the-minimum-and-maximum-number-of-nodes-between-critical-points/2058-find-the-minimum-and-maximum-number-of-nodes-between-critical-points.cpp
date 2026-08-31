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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* prev=head;
        int cp,i=1,c=0;
        int mini=-1,maxi=-1;
        while(temp->next != nullptr){
            if((temp->val < prev->val && temp->val<temp->next->val) || (temp->val > prev->val && temp->val>temp->next->val)){
                c++;
                if(c==2){
                    mini=i-cp;
                    maxi=i-cp;
                }
                else if(c>2){
                    maxi=maxi+(i-cp);
                    mini=min(mini,i-cp);
                }
                cp=i;
            }
            temp=temp->next;
            prev=prev->next;
            i++;
        }
        return {mini,maxi};
    }
};