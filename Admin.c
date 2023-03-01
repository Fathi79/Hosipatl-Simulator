#include<stdio.h>
#include"LinkedList.h"
#include<stdlib.h>
#define pause() system("Pause");
#define clear() system("cls");
u64 ID=0;
patient* Times[5]={NULL,NULL,NULL,NULL,NULL};
Node* Head=NULL;
u8 checkForAdmin();
u8 addNewPatientRecord();
u8 EditPatient(u64 ID);
patient* searchID(u64 ID);
void cancelReservation();
void makeAppointnment(patient* patient);
void availableSlots();

void cancelReservation()
{
    u64 ID;
    clear()
    printf("Enter The ID Of The Patient You Want To cancel The Appointment for:\n"); 
    scanf("%ld",&ID);
    patient* patient= searchID(ID);
    if(!patient)
    {
        printf("There IS no Patient With Such ID\n");  
        pause();  
    }
    else
    {
        for (u8 i = 0; i < 5; i++)
        {
            if(Times[i]==patient)
            {
                Times[i]=NULL;
            }
        }
        printf("Patient With ID %d Canceled his Appointments");
        pause()
    }
}
void makeAppointnment(patient* patient)
{
    clear()
    printf("You Are Reserving An Appointment For Patient With ID %ld\nPlease Make Sure To Choose Only From Available slots\n\n",patient->id);
    printf("To Reserve Appointement from 2:00 pm to 3:00 pm Enter 1\n");
    printf("To Reserve Appointement from 3:00 pm to 4:00 pm Enter 2\n");
    printf("To Reserve Appointement from 4:00 pm to 5:00 pm Enter 3\n");
    printf("To Reserve Appointement from 5:00 pm to 6:00 pm Enter 4\n");
    printf("To Reserve Appointement from 6:00 pm to 7:00 pm Enter 5\n");
    u8 choice;
    fflush(stdin);
    scanf("%c",&choice);
    switch (choice)
    {
    case '1':
        if (!Times[0])
        {
            Times[0]=patient;
            printf("Patient With ID %ld Has Reserved Appointment From 2:00pm to 3:00pm\n",patient->id);
            pause()
            return ;
        }
        
        break;
    case '2':
        if (!Times[1])
        {
            Times[1]=patient;
            printf("Patient With ID %ld Has Reserved Appointment From 3:00pm to 4:00pm\n",patient->id);
            pause()
            return ;
        }
        break;
    case '3':
        if (!Times[2])
        {
            Times[2]=patient;
            printf("Patient With ID %ld Has Reserved Appointment From 4:00pm to 5:00pm\n",patient->id);
            pause()
            return ;
        }
        break;
    case '4':
        if (!Times[3])
        {
            Times[3]=patient;
            printf("Patient With ID %ld Has Reserved Appointment From 5:00pm to 6:00pm\n",patient->id);
            pause()
            return ;
        }
        break;
    case '5':
        if (!Times[4])
        {
            Times[4]=patient;
            printf("Patient With ID %ld Has Reserved Appointment From 6:00pm to 7:00pm\n",patient->id);
            pause()
            return ;
        }
        break;
    
    default:
        break;
    }    
    printf("You have Choosen an Unavailable slot\n");
    pause()
}
void availableSlots()      
{
    u8 count=0;
    while(1)
    {
        clear()
        for (u8 i = 0; i < 5; i++)
        {
            if(!Times[i])    
            {
                printf("Available apointment From 0%d:00 pm to 0%d:00 pm\n",i+2,i+3);
                count++;
            }
        }
        if(!count)
        {
            printf("There is No Avaiabe Slots");
            pause()
            return;
        }
        u8 choice;
        printf("\nTo Reserve Any Available Slot Enter 1 To Exit Enter Any Other Key\n");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='1')
        {
            u64 ID;
            clear()
            printf("Enter The ID Of The Patient You Want To Reserve The Appointment for:\n"); 
            scanf("%ld",&ID);
            patient* patient= searchID(ID);
            if(!patient)
            {
                printf("There IS no Patient With Such ID\n");  
                pause();  
            }
            else
            {
                makeAppointnment(patient); 
            }
        }
        else
        {
            return ;
        }
    }
    pause()
}
void DeleteNodes()
{
    Node* ptr;
    
    while (Head)
    {
        ptr=Head;
        Head=Head->NextPatient;
        free(ptr->NextPatient);
        free(ptr);
       
    }
    
}
void printInfo(patient* Npatient)
{
    printf("Patient ID:%ld\nPatient name:%s\nPatient age:%d\nPatient Gender:%c\n",Npatient->id,Npatient->name,Npatient->age,Npatient->Gender);
    pause()
}
void admin()
{
    clear()
    if(!checkForAdmin())
    {
        
        printf("Wrong Password for 3 Times no more tries\n");
        return;
    }
   
    printf("Welcome To Admin View\n");
    while(1)
    {
        clear()
        printf("To Add New Patient Record Enter 1\nto Edit Info of some existing patient Enter 2\nTo See The available appointment or reserve once Enter 3\n");
        printf("To cancel An Appointments Enter 4\n");
        printf("To Exit Admin Mode Enter Any Other Key\n");
        u8 choice;
        fflush(stdin);
        scanf("%d",&choice);
        u64 ID;
        switch (choice)
        {
        case 1:
            if(!addNewPatientRecord())
            {
                printf("Cant Add New Patient For Some Reason\nPlease Try Again Later\n");   
                pause()
            }
            break;
        case 2:
            printf("Please Enter the Patient ID That You Want To Edit His InfOs\n");
            scanf("%Ld",&ID);
            if(!EditPatient(ID))
            {
                printf("There is no Patient with this ID\n");
                pause()
            }
            break;
        case 3:
            availableSlots();
            break;
        case 4:
            cancelReservation();
            break;
        default:
            return;
            break;
        }
        
    }
}
u8 insertAtBegining(patient* p)
{
    Node* Nptr=(Node*)malloc(sizeof(Node));
    if(!Nptr)
    {
        return 0;
    }
    Nptr->NextPatient=Head;
    Nptr->patient=p;
    Head=Nptr;
    return 1;

}
patient* searchID(u64 ID)
{
    Node* SearchPtr=Head;
    while (SearchPtr)
    {
        if(ID==SearchPtr->patient->id)
        {
            return SearchPtr->patient;
        }
        SearchPtr=SearchPtr->NextPatient;
    }
    return NULL;
    
}
u8 checkForAdmin()
{
    clear()
    u32 password;
    printf("Please Enter The Admin Passwrod\n");
    
    u8 i=3;
    while(i)
    {
        scanf("%d",&password);
        if(password==1234)
        {
            return 1;
        }
        printf("Wrong Password Please try again\n");
        i--;
    }
    return 0;
}
u8 addNewPatientRecord()
{
    clear()
    patient* Npatient=(patient*)malloc(sizeof(patient));
    Npatient->id=++ID;
   
    printf("Please Enter Patient name:\n");
    scanf("%s",&Npatient->name);
   
    printf("Please Enter Patient age:\n");
    scanf("%d",&Npatient->age);
    if (Npatient->age>120)
    {
        printf("age more than 120!\npatient age is set to 120\n");
        Npatient->age=120;
    }
    


    while (1)
    {
        printf("Please Enter Patient Gneder\nFor male Enter M or m\nFor female Enter F or f \n");
        fflush(stdin);
        u8 f;
        scanf("%c",&Npatient->Gender);      
        if(Npatient->Gender=='M'||Npatient->Gender=='m'||Npatient->Gender=='F'||Npatient->Gender=='f')
        { 
            break;
        }   
        else
        {
            printf("Worng Character Please Try Again\n");
        }  
    }
    if(!insertAtBegining(Npatient)||!Npatient)
    {
        free(Npatient);
        return 0;
    }
    clear()
    printf("New Patient Has been Added\n\n");

    printInfo(Npatient);
    return 1;
}
u8 EditPatient(u64 ID)
{
    clear()
    patient* patient=searchID(ID);
    if (!patient)
    {
        return 0;
    }
    u32 Choice;
    while(8888)
    {   
        printf("Patient with ID %d\nPatient name:%s\nPatient age:%d\nPatient Gender:%c\n",patient->id,patient->name,patient->age,patient->Gender);
        printf("\nto Edit Name Enter 1\nto Edit age Enter 2\nto Edit gender Enter 3\nto Exit Enter any other key\n");
        fflush(stdin);
        scanf("%d",&Choice);
        switch (Choice)
        {
            case 1:
                printf("Please Enter Patient New name:\n");
                scanf("%s",&patient->name);
                break;
            case 2:
                printf("Please Enter Patient New age:\n");
                scanf("%d",&patient->age);
                if (patient->age>120)
                {
                    printf("age more than 120!\npatient age is set to 120\n");
                    patient->age=120;
                }
                break;
            case 3:
                while (1)
                {
                    printf("Please Enter Patient New Gneder\nFor male Enter M or m\nFor female Enter F or f\n");
                    fflush(stdin);
                    scanf("%c",&patient->Gender);
                    if(patient->Gender=='M'||patient->Gender=='f'||patient->Gender=='F'||patient->Gender=='f')
                    {
                        break;
                    }   
                    printf("Worng Character Please Try Again\n");
                }  
                break;            
            default: 
            printInfo(patient);
            return 1;
        }
    }
}