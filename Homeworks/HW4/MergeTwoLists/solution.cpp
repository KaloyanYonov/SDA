// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* llist = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* current = llist;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != nullptr) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    SinglyLinkedListNode* mergedList = llist->next;

    return mergedList;
}