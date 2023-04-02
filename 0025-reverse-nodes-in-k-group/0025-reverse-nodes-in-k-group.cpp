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
        if(!head||k==1) return head;
        int c=0;
        ListNode* dummy=new ListNode(0);
        ListNode* cur=dummy;
        dummy->next=head;
        while(cur->next){
            cur=cur->next;
            c++;
        }
        ListNode* pre=dummy;
        ListNode* nex=dummy;
        
        while(c>=k){
            cur=pre->next;
            nex=cur->next;
            int temp=k-1;
            while(temp--){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
                
            }
            c-=k;
            pre=cur;
            
            
        }
        return dummy->next;
        
    }
    

};