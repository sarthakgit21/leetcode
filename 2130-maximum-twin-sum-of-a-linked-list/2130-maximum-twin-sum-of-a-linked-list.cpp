class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *forward;
        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList(slow);
        int maxi = 0;
        while(rev)
        {
            maxi = max(maxi,head->val+rev->val);
            rev = rev->next;
            head = head->next;
        }
        return maxi;
    }
};