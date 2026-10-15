/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;

            temp = temp->next->next;
        }
        temp = head;
        while (temp != nullptr) {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* ans = dummy;
        temp=head;
        while(temp!=nullptr){
            dummy->next = temp->next;
            temp->next = temp->next->next;

            dummy=dummy->next;
            temp=temp->next;
        }
        return ans->next;
    }
};