#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "calls.h"

void editrecord()

{

    system("clear");

    FILE *fpte ;

    struct record assignment ;

    char name[15],choice,filename[20];

    int num,count=0;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* EDITING MENU *");

    printf("\n\t\t*******************************\n\n");

    do

    {

        printf("\n\tENTER ASSIGNMENT NAME(no spaces):");

        fflush(stdin);

       scanf("%s",filename);

        printf("\n\tENTER CLASS NAME:");

       scanf("%s",name);

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\nRECORD DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getchar();

            return;

        }

        while ( fread ( &assignment, sizeof ( assignment ), 1, fpte ) == 1 )

        {

            if(strcmp(assignment.name,name)==0)

            {

                printf("\nYOUR ASSIGNMENT WAS:");

               printf("\nDUE DATE: %s",assignment.time);

                printf("\nCLASS NAME: %s",assignment.name);

                printf("\nCHAPTERS: %s",assignment.chp);

                printf("\nSTUDY TIME: %s",assignment.duration);

                printf("\nNOTE: %s",assignment.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.DUE DATE.");

                printf("\n2.CLASS NAME.");

                printf("\n3.CHAPTERS.");

                printf("\n4.STUDY TIME.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d",&num);

                    fflush(stdin);

                    switch(num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW DUE DATE:[yyyy-mm-dd]:");

                       scanf("%s",assignment.time);

                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW CLASS NAME:");

                       scanf("%s",assignment.name);

                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW CHAPTERS:");

                       scanf("%s",assignment.chp);

                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nUPDATE STUDY TIME:");

                       scanf("%s",assignment.duration);

                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                       scanf("%s",assignment.note);

                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW ENTER DUE DATE:[yyyy-mm-dd]:");

                       scanf("%s",assignment.time);

                        printf("\nNEW CLASS NAME:");

                       scanf("%s",assignment.name);

                        printf("\nNEW CHAPTERS:");

                       scanf("%s",assignment.chp);

                        printf("\nUPDATE STUDY TIME:");

                       scanf("%s",assignment.duration);

                        printf("\nNOTE:");

                       scanf("%s",assignment.note);

                        break;

                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        getchar();

                        return ;

                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }

                }
                while(num<1||num>8);

                fseek(fpte,-sizeof(assignment),SEEK_CUR);

                fwrite(&assignment,sizeof(assignment),1,fpte);

                fseek(fpte,-sizeof(assignment),SEEK_CUR);

                fread(&assignment,sizeof(assignment),1,fpte);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("clear");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW ASSIGNMENT IS:\n");

            printf("--------------------\n");

            printf("\nDUE DATE: %s",assignment.time);

            printf("\nCLASS NAME: %s",assignment.name);

            printf("\nCHAPTERS: %s",assignment.chp);

            printf("\nSTUDY TIME: %s",assignment.duration);

            printf("\nNOTE: %s",assignment.note);


            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE ASSIGNMENT DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getchar();

}
