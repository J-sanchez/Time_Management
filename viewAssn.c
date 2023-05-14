#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "calls.h"


void viewAssignment( )

{

    FILE *fpte ;

    system("clear");

    struct record assignment ;

    char time[15],choice,filename[50];

    int home;

    printf("\n\n\t\t***********************\n");

    printf("\t\t* VIEWING ASSIGNMENTS *");

    printf("\n\t\t***********************\n\n");

    do

    {

        printf("\n\t ENTER ASSIGNMENT NAME(no spaces):");

        fflush(stdin);

       scanf("%s",filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\nTHE ASSIGNMENT DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            getchar();

            return ;

        }

        system("clear");

        printf("\n\tWOULD YOU LIKE TO VIEW:\n");

        printf("\n\t  1.WHOLE ASSIGNMENT OF THE DAY?");

        printf("\n\t\tENTER YOUR CHOICE:");
        printf("\n\tENTER 1 TO CONTINUE, OR ANY KEY TO EXIT: ");

        scanf("%d",&home);

        switch(home)

        {

        case 1:

            printf("\nTHE WHOLE ASSIGNMENT FOR %s IS:",filename);

            while ( fread ( &assignment, sizeof ( assignment ), 1, fpte ) == 1 )

            {

                printf("\n");
                printf("\nDUE DATE: %s",assignment.time);

                printf("\nCLASS NAME: %s",assignment.name);

                printf("\nCHAPTERS: %s",assignment.chp);

                printf("\nSTUDY TIME: %s",assignment.duration);

                printf("\nNOTE: %s",assignment.note);

            }

            break;

        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

}