/*Mak Mckinney
  CS302 Project 2
  Last Updated 2/17/2023
  
  CPP Program to implement a Merge Sort*/

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    if (numeric) l.head = msort(l.head, true);
    else l.head = msort(l.head, false); 

}

Node *msort(Node *head, bool numeric) {
    /*Sort a side*/
    if (head == NULL || head->next == NULL) return head;
    
    /*split*/
    Node *left = NULL;
    Node *right = NULL;
    split (head, left, right);
    left = msort (left,numeric);
    right = msort (right, numeric);

    return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {
    /*Break into Halfs*/
    if (head == NULL || head->next == NULL) {
        right = NULL;
        left = head; 
    }

    Node *p = head;
    Node *n = head->next;
    while (n != NULL){
        n = n->next;
        if (n != NULL){
            p = p->next;
            n = n->next;
        }
    } 
    left = head;
    right = p->next;
    p->next = NULL;
}

Node *merge(Node *left, Node *right, bool numeric) {
    /*Put back together*/
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    if (numeric){
        if (node_number_compare(left,right)){
            left->next = merge(left->next, right, numeric);
            return left;
        }
        else {
            right->next = merge (left, right->next, numeric);
            return right;
        }
    }

    else{
        if (node_string_compare(left,right)){
            left->next = merge(left->next, right, numeric);
            return left;
        }
        else {
            right->next = merge(left,right->next, numeric);
            return right; 
        }
    }
}

