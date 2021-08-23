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
    ListNode* removeNthFromEnd(ListNode* head, int key) {        
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 0; i < key; i++)
        {
            if (second->next == NULL)
            {
                if (i == key - 1){
                    head = head->next;
                }
                return head;
            }
            second = second->next;
        }
        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
 
        first->next = first->next->next;
        return head;
            
    }
};