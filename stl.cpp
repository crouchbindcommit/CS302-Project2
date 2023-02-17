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

    if (numeric) std::sort(nodes.begin(), nodes.end(), node_number_compare);
    else std::sort(nodes.begin(), nodes.end(), node_string_compare);
    
    /*for loop for adding nodes back*/
    l.head = nodes[0];
    for (size_t i = 0; i < nodes.size(); i++) nodes[i]->next = nodes[i+1];
    nodes[nodes.size()-1]->next = NULL; 
}
