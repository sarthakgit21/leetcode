/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*ff=head;
        ListNode*ss=head;
        ListNode*ee=head;
        if(!head||!head->next) return NULL;
        while(ff->next&&ff->next->next){
            ff=ff->next->next;
            ss=ss->next;
            if(ss==ff){
                while(ee!=ss){
                    ss=ss->next;
                    ee=ee->next;
                }
                return ee;
            }
        }
        return NULL;
    }
};