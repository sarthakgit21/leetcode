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
    ListNode* fun(ListNode* head){
        if(!head) return head;
        ListNode* dum=NULL;
        while(head){
            ListNode* nnew=head->next;
            head->next=dum;
            dum=head;
            head=nnew;
        }
        return dum;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return 1;
        ListNode* f=head;
        ListNode* s=head;
        while( f->next!=NULL&&f->next->next!=NULL){
            f=f->next->next;
            s=s->next;
        }
        ListNode* nnew=head;
        s->next=fun(s->next);
        s=s->next;
        while(s){
            if(s->val!=nnew->val) return 0;
            s=s->next;
            nnew=nnew->next;
        }
        return 1;
    }
};