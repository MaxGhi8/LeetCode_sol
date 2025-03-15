/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // Iterative Method
struct ListNode* reverseList(struct ListNode* head) {
    // Base case
    if(head == NULL) {
        return NULL;
    }

    // Create a new ListNode
    struct ListNode* reversed_list = NULL;

    while(head != NULL){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof( struct ListNode));
        // get the value
        newNode->val = head->val; 
        // put the newNode at the beginning of reversed list
        newNode->next = reversed_list;
        reversed_list = newNode;
        // update head
        head = head->next;
    }

    return reversed_list;
}

// Recursive Method
/* 
struct ListNode* reverseList(struct ListNode* head){

    struct ListNode* helper(struct ListNode* reversed, struct ListNode* head){
        if(head == NULL){
            return reversed;
        } else {
            struct ListNode* newHead = (struct ListNode*)malloc(sizeof( struct ListNode ));
            newHead->val = head->val;
            newHead->next = reversed;
            return helper(newHead, head->next);
        }
    }

    return helper(NULL, head); 
}
*/
