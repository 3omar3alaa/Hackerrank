

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* current = head;
    int count = 1;
    while(count != position){
        count++;
        current = current->next;
    }
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    node->next = current->next;
    current->next = node;
    return head;


}

