#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "calls.h"

void addAssignment( )

{

    system("clear");

    FILE *fp ;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];

    int choice;

    printf("\n\n\t\t******************\n");

    printf("\t\t* ADD ASSIGNMENT *");

    printf("\n\t\t******************\n\n");

    printf("\n\n\tENTER ASSIGNMENT NAME(no spaces):");

    fflush(stdin);

   scanf("%s",filename);

    fp = fopen (filename, "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"wb+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getchar();

            return ;

        }

    }

    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER ENTER DUE DATE:[yyyy-mm-dd]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.time,time)==0)

            {

                printf("\n\tTHE ASSIGNMENT ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.time,time);

            printf("\tENTER CLASS NAME:");

            fflush(stdin);

           scanf("%s",e.name);

            fflush(stdin);

            printf("\tENTER CHAPTERS:");

           scanf("%s",e.chp);

            fflush(stdin);

            printf("\tENTER STUDY TIME:");

           scanf("%d",e.duration);

            fflush(stdin);

            printf("\tNOTE:");

           scanf("%s",e.note);

            fwrite ( &e, sizeof( e ), 1, fp ) ;

            printf("\nYOUR ASSIGNMENT IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER ASSIGNMENT...(Y/N) " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getchar();
};
