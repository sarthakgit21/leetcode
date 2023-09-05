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
        if(!head) return head;
        Node* temp=head;
        Node* ans;
        int flag=1;
        while(temp){
            Node* nex=new Node(temp->val);
            if(flag) {
                ans=nex;
                flag=0;
            }
            Node *tempnex=temp->next;
            temp->next=nex;
            nex->next=tempnex;
            temp=tempnex;
        }
        
        temp=head;
        while(temp){
            if(temp->random) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            Node* val=temp->next;
            if(temp->next)temp->next=temp->next->next;
            temp=val;
        }
        return ans;
        
        
    }
};