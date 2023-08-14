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
    ListNode* sortList(ListNode* head) {\
        if(!head) return head;
        vector<int> arr;
        ListNode*temp=head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        sort(begin(arr),end(arr));
        temp=head;
        
        for(auto x:arr)
        {
            temp->val=x;
            temp=temp->next;
        }
        
        return head;
        
        
    }
};