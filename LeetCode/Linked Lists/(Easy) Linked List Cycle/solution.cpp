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
        unordered_map<ListNode*, bool> table;
        while(head!=NULL){
            if(table.find(head) != table.end()) return true;
            table[head] = true;
            head = head -> next;
        }
        return false;
    }
};