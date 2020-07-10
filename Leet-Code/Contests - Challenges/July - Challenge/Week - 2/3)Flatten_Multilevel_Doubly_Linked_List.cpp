/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        return rec(head,NULL);
    }
    Node *rec(Node * head, Node * tail){
        Node * last = head, *orig = head;
        while(head != NULL){
            if(head->child != NULL){
                head -> next = rec(head->child,head->next);
                head -> child = NULL;
            }
            if(head -> next != NULL)
                head -> next -> prev = head;
            last = head;
            head = head -> next;
        }
        if(last != NULL)
            last -> next = tail;
        return orig;
    }
};
