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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        // ListNode* temp2=new ListNode(head);
        ListNode* ans=new ListNode(0);
        ListNode* ans2=new ListNode(0);
        
        ListNode* fans=ans;
        ListNode* fans2=ans2;
        
        while(temp)
        {
            if(temp->val<x)
            {
                // cout<<temp->val;
                ans->next=temp;
                ans=ans->next;
            }
            else{
                // cout<<temp->val;
                ans2->next=temp;
                ans2=ans2->next;
                // cout<<ans2->val;
            }
            temp=temp->next;
        }
        ans2->next=NULL;
        ans->next=NULL;
        ans->next=fans2->next;
        // cout<<ans->val;
        
        return fans->next;
        
    }
};