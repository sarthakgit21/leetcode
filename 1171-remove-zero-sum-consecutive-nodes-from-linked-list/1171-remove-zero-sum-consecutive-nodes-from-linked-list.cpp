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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        unordered_map<int,ListNode*> mp;
        mp[0]=dummy;
        int presum=0;
        while(head)
        {
            presum+=head->val;
            if(mp.find(presum)!=mp.end())
            {
                ListNode* temp=mp[presum];
                ListNode* str=temp;
                int pre=presum;
                
                while(str!=head)
                {
                    str=str->next;
                    pre+=str->val;
                    if(str!=head)
                    mp.erase(pre);
                }
                temp->next=head->next;
                
            }
            else{
                mp[presum]=head;
            }
            head=head->next;
        }
        
        return dummy->next;
    }
};