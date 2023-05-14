#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "calls.h"

int main()

{

    int home;

    printf("\n\n\t***********************************\n");

    printf("\t*TIME MANAGEMENT TOOL*\n");

    printf("\t***********************************");

    while(1)

    {

        printf("\n\n\t\tMAIN MENU:");

        printf("\n\n\tADD ASSIGNMENT\t        [1]");

        printf("\n\tVIEW ASSIGNMENT\t        [2]");

        printf("\n\tEDIT ASSIGNMENT\t        [3]");

        printf("\n\tDELETE ASSIGNMENT\t[4]");

        printf("\n\tEXIT\t\t        [5]");

        printf("\n\n\tENTER YOUR CHOICE:");

        break;
        system("clear");
    }
        scanf("%d",&home);

        switch(home)

        {

        case 1:

            addAssignment();

            break;

        }
    return 0;

}
