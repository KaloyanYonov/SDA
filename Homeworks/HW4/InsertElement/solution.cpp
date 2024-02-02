/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
// 16 13 7
//16 13 1 7

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* current = llist;
    
    if(llist == nullptr){
        return newNode;
    }
    
    for(int i =0;i < position - 1;++i){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    
    
    return llist;
    

}