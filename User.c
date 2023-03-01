#include<stdio.h>
#include"LinkedList.h"
#include<stdlib.h>
#define pause() system("Pause");
#define clear() system("cls");
extern patient* Times[5];
extern Node* Head;
void printInfo(patient* Npatient);
patient* searchID(u64 ID);

void viewRecords()
{
    clear()
    if(!Head)
    {
        printf("There is No Patients...\n");
        pause()
        return;
    }
    while (Head)
    {
        printInfo(Head->patient);
        Head=Head->NextPatient;
    }
    
}
void viewReservations()
{
    clear()
    u8 count=0;
    for (u8 i = 0; i < 5; i++)
    {
        if(Times[i])
        {
            printf("Today There is An Appointment From 0%d:00 to 0%d:00\n\n",i+2,i+3);
            count++;
        }
    }
    if(!count)
    {
        printf("There Is NO Reservations Today\n");
        
    }
    pause()
}
u64 getsID()
{
    u64 ID;
    clear()
    printf("Enter The ID Of The Patient You Want To View His Record\n"); 
    scanf("%ld",&ID);
    return ID;
}
void viewRecord()
{
    patient* patient= searchID(getsID());
    if(!patient)
    {
        printf("There IS no Patient With Such ID\n");  
        pause();
    }
    else
    {
        printInfo(patient);
    }
}
void user()
{
    clear()
    while (1)
    {
        clear()
        printf("Welcome To User Mode\n\nTo View all patient records Enter 1\nTo View Specific Patient Record Enter 2\nTo View today's Reservations Enter 3\nPress Any Other Key To Exit\n\n");
        u8 choice;
        fflush(stdin);
        scanf("%c",&choice);
        switch (choice)
        {
        case '1':
            viewRecords();
            break;
        
        case '2':
            viewRecord();
            break;
        case '3':
            viewReservations();
            break;
        default:
            return;
            break;
        }
    }
}