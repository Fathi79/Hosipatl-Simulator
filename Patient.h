#ifndef PATIENT_H
#define PATIENT_H
#include"..\LEC8\STD_TYPES.h"
struct Patient
{
   
    u8 name[30];
    u8 Gender;
    u16 age; 
    u64 id;  
};
typedef struct Patient patient;
#endif