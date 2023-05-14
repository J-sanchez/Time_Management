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

    printf("\n\n\t\t***************************\n");

    printf("\t\t* ADD ASSIGNMENT *");

    printf("\n\t\t***************************\n\n");

    printf("\n\n\tENTER ASSIGNMENT NAME:");

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

        printf ( "\n\tENTER DUE DATE:[yyyy-mm-dd]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.time,time)==0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.time,time);

            printf("\tENTER CLASS:");

            fflush(stdin);

           scanf("%s",e.name);

            fflush(stdin);

            printf("\tENTER CHAPTERS:");

           scanf("%s",e.name1);

            fflush(stdin);

            printf("\tENTER STUDY TIME:");

           scanf("%s",e.duration);

            fflush(stdin);

            printf("\tNOTE:");

           scanf("%s",e.note);

            fwrite ( &e, sizeof( e ), 1, fp ) ;

            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getchar();
};
