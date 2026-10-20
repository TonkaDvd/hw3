#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif


struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**

 *
 * @pre:
 *
 * @param[inout] head
 * @param[out] smaller
 * @param[out] larger
 * @param[in] pivot
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**

 *
 * @param[in] head
 * @param[in] pred
 * @return 

 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);


template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    if(head == nullptr){
        return head;
    }

    if(pred(head->val)){
        Node* temp = head;
        head = head->next;
        delete temp;
        head = llfilter(head, pred);
    } else{
        head->next = llfilter(head->next, pred);
    }

    return head;
}

#endif
