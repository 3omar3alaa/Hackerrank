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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* result = new ListNode();
        ListNode* temp = result;
        if(l1 -> val < l2 -> val)
        {
            result -> val = l1 -> val;
            l1 = l1 -> next;
        }
        else{
            result -> val = l2 -> val;
            l2 = l2 -> next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                temp -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            else{
                temp -> next = new ListNode(l2 -> val);
                l2 = l2 -> next;
            }
            temp = temp -> next;
                
        }
        if(l1 == NULL)
            temp -> next = l2;
        else
            temp -> next = l1;
        return result;        
    }
};