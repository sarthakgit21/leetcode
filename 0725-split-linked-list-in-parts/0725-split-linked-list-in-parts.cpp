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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        
        int cnt=0;
        ListNode*temp=head;
        while(temp){cnt++;temp=temp->next;};
        
        int vals=cnt/k;
        int rem=cnt%k;
        
        temp=head;
        int ind=0;
        while(temp){
            ListNode* val=temp;
            ans[ind++]=val;
            ListNode*prev;
            for(int i=0;i<vals;i++){
                prev=temp;
                temp=temp->next;
            }
            if(rem>0){
                prev=temp;
                temp=temp->next;
                rem--;
            }
            prev->next=NULL;
        }
        
        return ans;
        
    }
};