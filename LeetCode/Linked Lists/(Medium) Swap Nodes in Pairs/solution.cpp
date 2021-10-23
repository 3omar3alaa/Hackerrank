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
    ListNode* swapPairs(ListNode* head) {
        return swapPairsRecursive(head);
    }
    
    ListNode* swapPairsRecursive(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        else{
            ListNode* tmp = head -> next;
            head -> next = head -> next -> next;
            tmp -> next = head;
            tmp -> next -> next = swapPairsRecursive(tmp -> next -> next);
            return tmp;
        }
    }
};