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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        int temp=k;
        ListNode*dummy=NULL;
        ListNode *cur=head;
        ListNode *cur2=head;
        
        int temp2=k;
        while(temp2--){
            if(!cur2) return head;
            cur2=cur2->next;
        }
        
        while(temp>0&&cur){
            ListNode* nnew=cur->next;
            temp--;
            cur->next=dummy;
            dummy=cur;
            cur=nnew;
        }
        // if(temp>0) return head;
        head->next=reverseKGroup(cur,k);
        return dummy;
    }
    

};