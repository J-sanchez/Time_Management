#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "calls.h"

void deleteAssignment( )

{

    system("clear");

    FILE *fp,*fptr ;

    struct record assignment ;

    char filename[15],another = 'Y' ,time[10];;

    int choice,check;

    printf("\n\n\t\t**********************\n");

    printf("\t\t* DELETE ASSIGNMENTS *");

    printf("\n\t\t**********************\n\n");

    {

        return ;

    }

    while ( another == 'Y' )

    {

        printf("\n\n\tDELETE OPTIONS.");

        printf("\n\n\t#DELETE WHOLE ASSIGNMENT\t\t\t[1]");

        printf("\n\t#DELETE A PARTICULAR ASSIGNMENT BY TIME\t[2]");

        do

        {

            printf("\n\t\tENTER YOU CHOICE:");

            scanf("%d",&choice);

            switch(choice)

            {

            case 1:

                printf("\n\tENTER NAME OF ASSIGNMENT TO DELETE: ");

                fflush(stdin);

               scanf("%s",filename);

                fp = fopen (filename, "wb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    getchar();

                    return ;

                }

                fclose(fp);

                remove(filename);

                printf("\nDELETED SUCCESFULLY...");

                break;

            case 2:

                printf("\n\tENTER NAME OF ASSIGNMENT TO DELETE: ");

                fflush(stdin);

               scanf("%s",filename);

                fp = fopen (filename, "rb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    getchar();

                    return ;

                }

                fptr=fopen("temp","wb");

                if(fptr==NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    getchar();

                    return ;

                }

                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                fflush(stdin);

               scanf("%s",time);

                while(fread(&assignment,sizeof(assignment),1,fp)==1)

                {

                    if(strcmp(assignment.time,time)!=0)

                        fwrite(&assignment,sizeof(assignment),1,fptr);

                }

                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp",filename);

                printf("\nDELETED SUCCESFULLY...");

                break;

            default:

                printf("\n\tYOU ENTERED WRONG CHOICE");

                break;

            }

        }
        while(choice<1||choice>2);

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

        fflush(stdin);

        scanf("%c",&another);

    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getchar();

}