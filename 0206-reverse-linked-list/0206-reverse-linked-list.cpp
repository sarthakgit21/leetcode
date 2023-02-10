/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
           	// ListNode* reverseList(ListNode *head)
           	// {
            ListNode *Newhead = NULL;
            while (head != NULL)
            {
                ListNode * next;
                next = head->next;
                head->next = Newhead;
                Newhead = head;
                head = next;
            }
            return Newhead;
           	// }
        }
};