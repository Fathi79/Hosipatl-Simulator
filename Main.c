#include<stdio.h>
#include"..\LEC8\STD_TYPES.h"
#include<stdlib.h>
#define pause() system("Pause");
#define clear() system("cls");
void admin();
void DeleteNodes();
void user();
u8 main()
{
    while (1)
    {
        clear()
        printf("Welcome To the HosPital\n\n");
        printf("To Enter Admin mode Enter 1\nTo Enter User Mode Enter 2\nTo Exit Press Any Other Key\n");
        u32 choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            admin();
            break;
        case 2:user();
            break;
        default:
            DeleteNodes();
            return 0;
            break;
        }           
    }
}