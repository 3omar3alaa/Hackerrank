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
    bool isPalindrome(ListNode* head) {
		/*
		Can be made another wise by making slow pointer and fast pointer
		then reversing the second half and check the first half and second (reversed) half
		*/
        vector<int> vals;
        while(head != NULL){
            vals.push_back(head->val);
            head = head -> next;
        }
        for(int i = 0; i < vals.size() / 2; i++){
            if(vals[i] != vals[vals.size() - 1 -i])
                return false;
        }
        return true;
    }
};