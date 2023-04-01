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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         //first see if any of the two given list is null  or not
 if(list1 == NULL)return list2;
 if(list2 == NULL)return list1;
 
 //find the pointer having least value
 if(list1->val > list2->val)swap(list1,list2);
 //initialize new pointer to the smallest pointer val
 ListNode* res=list1;
 //now iterate over l1 and l2;
 while(list1 != NULL && list2 != NULL){
     //node for connecting
     ListNode* temp=NULL;
     //iterate over l1 till l1<=l2
     while(list1 !=NULL and list1 ->val <= list2->val){
         temp=list1;
         list1=list1->next;
     }
     //when l2<l1
     temp->next=list2;
     swap(list1, list2);
 }
 return res;
    }
};