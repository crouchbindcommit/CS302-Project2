/*Mak Mckinney
  CS302 Project 2
  Last Updated 2/17/2023
  Recieved Help from Maria Auxiliadora Hernandez
  
  CPP Program to implement STL's QSort function*/

#include <algorithm>
#include "volsort.h"
#include <stdio.h>

int number_compare(const void *a, const void *b){
    //double cast to pointer of nodes
    Node* node1 = *(Node**)a;   
    Node* node2 = *(Node**)b; 

    return (node1->number - node2->number); 
     
}

int string_compare(const void *a, const void *b){
    Node* node1 = *(Node**) a;   
    Node* node2 = *(Node**)b; 

    return (node1->string.compare(node2->string)); 

}

void qsort_sort(List &l, bool numeric) {
    /*transfer to vector*/
    Node* nodes [l.size];
    if (l.empty() == false){
        int i = 0;
        Node *p = l.head;
        while (p != NULL){
            nodes[i] = p;
            p  = p -> next;
            i++;
        }
        
    }

    if (numeric == true) std::qsort(nodes, l.size, sizeof(Node*), number_compare);
    else std::qsort(nodes, l.size, sizeof(Node*), string_compare);
 

 /*for loop for adding nodes back*/
    l.head = nodes[0];
    for (size_t i = 0; i < l.size; i++) nodes[i]->next = nodes[i+1];
    nodes[l.size-1]->next = NULL; 

}
