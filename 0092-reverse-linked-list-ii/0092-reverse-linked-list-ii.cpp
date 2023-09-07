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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt=0;
        ListNode* temp=head;
        while(temp) {cnt++;temp=temp->next;}
        if(cnt<0) return head;
        int val=right-left;
        temp=head;
        ListNode* prevvals=new ListNode(0);
        ListNode* ans=prevvals;
        left--;
        while(left--){
            prevvals->next=temp;
            prevvals=temp;
            temp=temp->next;
        }
        ListNode* prev=NULL;
        ListNode* vals=temp;
        val++;
        while(val&&temp){
            ListNode* nex=temp->next;
            val--;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
        if(prevvals->next) prevvals->next=prev;
        vals->next=temp;
        if(prevvals->next) return ans->next;
        return prev;
        
        
        
    }
};