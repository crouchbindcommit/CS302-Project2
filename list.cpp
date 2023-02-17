/*Mak Mckinney
  CS302 Project 2
  Last Updated 2/17/2023
  Recieved Help from Maria Auxiliadora Hernandez and CS202 lab4
  
  CPP Program to create a linked-list container*/
#include "volsort.h"

List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    if (!empty()){
        Node *p = head;

        while (p != NULL){
            Node *next = p -> next;
            delete p;
            p = next;
        }
    }
}

int List::empty(){
    if (head != NULL) return false;
    else return true;
}


void List::push_front(const std::string &s){
    Node *node = new Node;
    node->string = s; 
    node->number = stoi(s);
    node->next = head;  
    head = node;
    size++; 
}

bool node_number_compare(const Node *a, const Node *b){return (a->number <= b->number);}

bool node_string_compare(const Node *a, const Node *b){return (a->string <= b->string);}

size_t List::get_size(){return size;}
