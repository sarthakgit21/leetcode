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

class cmp{
    public:
        bool operator()(const ListNode* a,const ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) q.push(lists[i]);
        }
        cout<<q.size()<<endl;
        if(q.empty()) return NULL;
        while(!q.empty()){
            auto xt=q.top();
            q.pop();
            if(xt->next!=NULL) q.push(xt->next);
            temp->next=xt;
            temp=temp->next;
            
        }
        return head->next;
        
    }
};