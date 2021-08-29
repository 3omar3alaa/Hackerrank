/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
		/*
		Can be solved using O(1) space if we used two pointers (slow and fast) and they meet
		*/
        unordered_map<ListNode*, bool> table;
        while(head!=NULL){
            if(table.find(head) != table.end()) return true;
            table[head] = true;
            head = head -> next;
        }
        return false;
    }
};