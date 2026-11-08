#include<stdio.h>
#include"student.h"
#include<stdlib.h>
#include<string.h>
int main(){
int choice;
loadStudents();
while(1)
{
    printf("\n************************************************************************\n");
    printf("                           STUDENT MANAGEMENT SYSTEM                      \n");
    printf("\n************************************************************************\n");

    printf("1. Admin Login\n");
    printf("2. User Login\n");
    printf("3. Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            adminlogin();
            break;
        case 2:
            searchstudent();
            break;
        case 3:
            cleanupStudents();
            printf("Thank You\n");
            return 0;
        default:
            printf("Invalid Choice\n");
    }
}
return 0;
}
