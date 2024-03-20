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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempHead2=list2;
        ListNode*  templast;
        while(list2){
            templast=list2;
            list2=list2->next;
        }
        
        ListNode* temp=list1;
        ListNode* temp2=list1;
        while(a-->1){       temp=temp->next;
        }
        b++;
        while(b--){
            temp2=temp2->next;
        }
        temp->next=tempHead2;

        templast->next=temp2;
        return list1;
        
        
    }
};