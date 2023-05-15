class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode *itr = head, *ptr1 = NULL, *ptr2 = NULL;
    uint n = 0, count = 0;
    
    while(itr != NULL) {
        n++;
        itr = itr->next;
    }
    
    itr = head;
    while(itr != NULL) {
        count++;
        if(count == k) {
            ptr1 = itr;
        } else if(count == n - k + 1) {
            ptr2 = itr;
        }
        itr = itr->next;
    }
    
    if(ptr1 != NULL && ptr2 != NULL)
        swap(ptr1->val, ptr2->val);
    
    return head;
}

    void swap(int &a, int &b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};