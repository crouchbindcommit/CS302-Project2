/*Mak Mckinney
  CS302 Project 2
  Last Updated 2/17/2023
  Recieved Help from Maria Auxiliadora Hernandez
  
  CPP Program to implement STL's Sort function*/
#include <algorithm>
#include "volsort.h"


void stl_sort(List &l, bool numeric) {
    /*transfer to vector*/
    std::vector<Node*> nodes;
    if (l.empty() == false){
        Node *p = l.head;
        while (p != NULL){
            nodes.push_back(p);
            p  = p -> next;
        }
    }

    if (numeric == true) std::sort(nodes.begin(), nodes.end(), node_number_compare);
    else std::sort(nodes.begin(), nodes.end(), node_string_compare);
    
    /*for loop for adding nodes back*/
    Node *p = l.head;
    l.head = nodes[0];
    for (size_t i = 1; i < l.size; i ++){
        l.head->next = nodes[i];
        l.head = l.head->next;
    }
    l.head->next = NULL; 
    l.head = p; 

}
