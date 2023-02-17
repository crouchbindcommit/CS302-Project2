/*Mak Mckinney
  CS302 Project 2
  Last Updated 2/17/2023
  Recieved help from Alec Merkle
  
  CPP Program to implement a Quick Sort*/

#include "volsort.h"

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {l.head = qsort(l.head, numeric);}

Node *qsort(Node *head, bool numeric) {
    Node *left;
    Node *right;

   if (head == NULL || head->next == NULL) return head; 
   
   Node *pivot = head;

    //split
    partition(head, pivot, left, right, numeric);
    //sort either side 
    left = qsort(left, numeric);
    right = qsort(right, numeric); 


    //put back together
    head = concatenate (left, right); 

    return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) { 
    Node *temp = head->next;

    bool test;
    left = NULL;
    right = pivot;
    right->next = NULL; 

    while (temp != NULL){
         if (numeric) test = node_number_compare(temp,pivot);
         else test = node_string_compare(temp,pivot);

        if (test){
            Node *temp_head = temp; 
            temp = temp->next;   
            temp_head->next = left; 
            left = temp_head; 
        }
        else {
            Node *temp_head = temp; 
            temp = temp->next;    
            temp_head->next = right;
            right = temp_head;
        }
    }  
}



Node *concatenate(Node *left, Node *right) {
    if (left != NULL && right != NULL){
        Node *start = left; 
        while (left->next != NULL) left = left->next; 
        left->next = right; 
        return start; 
    } 
   else if (left != NULL && right == NULL) return left;
   else return right; 
}

