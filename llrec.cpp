#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head == nullptr){
        larger = nullptr;
        smaller = nullptr;
        return;
    }

    if(head->val > pivot){
            larger = head;
            head = head->next;
            llpivot (head, smaller, larger->next, pivot);
    } else{
            smaller = head;
            head = head->next;
            llpivot (head, smaller->next, larger, pivot);
    }
}