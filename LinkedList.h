#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Patient.h" 
struct LinkedList
{
    patient* patient;
    struct LinkedList* NextPatient;
};
typedef struct LinkedList Node;
#endif 