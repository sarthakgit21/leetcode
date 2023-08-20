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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*f=head;
        ListNode*s=head;
        ListNode*prev=NULL;
        while(f&&f->next)
        {
            prev=s;
            s=s->next;
            f=f->next->next;
        }
        if(!prev) return prev;
        cout<<prev->val;
        prev->next=prev->next->next;
        return head;
        
    }
};