#include <stdio.h>
#include "student.h"
#include<string.h>
#include<stdlib.h>

struct student * students = NULL;
int countstudent = 0;


void adminlogin(void){
    char password[30];
    printf("Enter Password\n");
    scanf("%s",&password);
    if(strcmp(password,"admin12345")==0){
        printf("\nAdmin Login Successful!\n");
        while(1){
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    int choice;
    do{
    printf("Enter your choice\n");
    scanf("%d",&choice);
    if(choice<1 || choice>6){
        printf("Enter number between 1 to 6");
    }
    }while(choice<1 || choice>6);
    switch(choice){
        case 1:
        printf("Add Student Selected\n");
        addstudent();
        break;

        case 2:
        printf("Display all Students selected\n");
        displaystudents();
        break;

        case 3:
        printf("Search Student selected\n");
        searchstudent();
        break;

        case 4:
        printf("Update Student Selected\n");
        updatestudent();
        break;

        case 5:
        printf("Delte Student selected\n");
        deletestudent();
        break;

        case 6:
        printf("Thank you for using Student Management System!\n");
        return;

        default:
        printf("Invalid choice! Please try again.\n");
    }
}
    }
else{
    printf("Wrong Password\n");
}
}

void addstudent(void){
    struct student * temp;
    temp = realloc(students,(countstudent+1)*sizeof(struct student));
    if(temp == NULL){
        printf("\n Memory Allocation failed\n");
        return;
    }
    students = temp;

    printf("\n******** ADD STUDENT ********\n");

    // Personal Details
    printf("\n--- PERSONAL DETAILS ---\n");
    int duplicate,i;
    do{
        duplicate = 0;
    printf("Enter Student ID: \n");
    scanf("%d", &students[countstudent].id);
    for(i=0;i<countstudent;i++){
        if(students[i].id == students[countstudent].id){
            duplicate = 1;
            printf("This id already exist! Use another\n");
            break;
        }
    }
    }while(duplicate == 1);

    printf("Enter Student Name: \n");
    scanf(" %49[^\n]", students[countstudent].name);

    do{
    printf("Enter Age: ");
    scanf("%d", &students[countstudent].age);

    if(students[countstudent].age<0 || students[countstudent].age>100){
        printf("Invalid Age! Try Again\n");
    }

    }while(students[countstudent].age<0 || students[countstudent].age>100);

    do{
    printf("Enter Gender (M/F): \n");
    scanf(" %c", &students[countstudent].gender);

    if(students[countstudent].gender!='M' && students[countstudent].gender!='F'){
        printf("Invalid Gender! Try Again\n");
    }
    }while(students[countstudent].gender!='M' && students[countstudent].gender!='F');

    // Contact Details
    printf("\n--- CONTACT DETAILS ---\n");

    int valid = 1;
    do{
    valid =1;
    printf("Enter Mobile Number: \n");
    scanf("%15s", students[countstudent].contact.mobile);

    if(strlen(students[countstudent].contact.mobile)!=10){
        valid = 0;
    }

    for(i=0;i<strlen(students[countstudent].contact.mobile);i++){
        if(students[countstudent].contact.mobile[i]<'0' || students[countstudent].contact.mobile[i]>'9'){
            valid = 0;
            break;
        }
    }

    if(valid == 0){
        printf("Invalid Phone Number ! Enter 10 digit\n");
    }
    }while(valid == 0);

    // Academic Details
    printf("\n--- ACADEMIC DETAILS ---\n");

    printf("Enter Course: \n");
    scanf(" %29[^\n]", students[countstudent].academic.course);

    do{
    printf("Enter Semester: \n");
    scanf("%d", &students[countstudent].academic.semester);
    if(students[countstudent].academic.semester<0 || students[countstudent].academic.semester>8){
         printf("Invalid Semester! Try Again\n");
    }
    }while (students[countstudent].academic.semester<0 || students[countstudent].academic.semester>8);
    
    do{
    printf("Enter CGPA: \n");
    scanf("%f", &students[countstudent].academic.cgpa);

    if(students[countstudent].academic.cgpa<0 || students[countstudent].academic.cgpa>10){
        printf("Invalid Cgpa! Try Again\n");
    }
    }while(students[countstudent].academic.cgpa<0 || students[countstudent].academic.cgpa>10);

    countstudent++;
    saveStudents();

    printf("\nStudent data added successfully!\n");

}

void displaystudents(void){
    printf("\nThe list of students:\n");
    int i,j;
    struct student temp;
    for(i=0;i<countstudent-1;i++){
        for(j=0;j<countstudent-1-i;j++){
            if(students[j].id>students[j+1].id){
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    for(i=0;i<countstudent;i++){
        printf("\n***************************************************************\n");
        printf("Student: %d \n",i+1);
        printf("\n***************************************************************\n");

        printf("\n\n--------Personal Details-------------\n");
        printf("id : %d\n",students[i].id);
        printf("Name: %s\n",students[i].name);
        printf("Age : %d\n",students[i].age);
        printf("Gender : %c\n",students[i].gender);
        
        printf("\n----------Contact Details--------------\n");
        printf("Mobile : %s\n",students[i].contact.mobile);

        printf("\n----------Academic Details-------------\n");
        printf("Course : %s\n",students[i].academic.course);
        printf("Semester : %d\n",students[i].academic.semester);
        printf("cgpa : %f\n",students[i].academic.cgpa);
    }
}

void searchstudent(void){
    printf("\nSelect method of searching\n");
    int choice,i;
    printf("1. Using id\n");
    printf("2. Using Name\n");
    printf("3. Using Mobile\n");
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        int idd;
        printf("Enter id: \n");
        scanf("%d",&idd);
        for(i=0;i<countstudent;i++){
            if(students[i].id==idd){
                printf("\n\n--------Personal Details-------------\n");
                printf("id : %d\n",students[i].id);
                printf("Name: %s\n",students[i].name);
                printf("id : %d\n",students[i].age);
                printf("id : %c\n",students[i].gender);
        
                printf("\n----------Contact Details--------------\n");
                printf("Mobile : %s\n",students[i].contact.mobile);

                printf("\n----------Academic Details-------------\n");
                printf("Course : %s\n",students[i].academic.course);
                printf("Semester : %d\n",students[i].academic.semester);
                printf("cgpa : %f\n",students[i].academic.cgpa);
            }
        }
        break;
    
    case 2:
        char * p;
        p = malloc(sizeof(char)*50);
        if(p == NULL){
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter name:\n");
        scanf(" %[^\n]",p);

        for(i=0;i<countstudent;i++){
            if(strcmp(students[i].name,p)==0){
                printf("\n\n--------Personal Details-------------\n");
                printf("id : %d\n",students[i].id);
                printf("Name: %s\n",students[i].name);
                printf("id : %d\n",students[i].age);
                printf("id : %c\n",students[i].gender);
        
                printf("\n----------Contact Details--------------\n");
                printf("Mobile : %s\n",students[i].contact.mobile);

                printf("\n----------Academic Details-------------\n");
                printf("Course : %s\n",students[i].academic.course);
                printf("Semester : %d\n",students[i].academic.semester);
                printf("cgpa : %f\n",students[i].academic.cgpa);
            }
        }
        free(p);
        break;

    case 3:
        char * s;
        s = malloc(sizeof(char)*50);
        if(s == NULL){
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter Mobile no.:\n");
        scanf(" %[^\n]",s);

        for(i=0;i<countstudent;i++){
            if(strcmp(students[i].contact.mobile,s)==0){
                printf("\n\n--------Personal Details-------------\n");
                printf("id : %d\n",students[i].id);
                printf("Name: %s\n",students[i].name);
                printf("id : %d\n",students[i].age);
                printf("id : %c\n",students[i].gender);
        
                printf("\n----------Contact Details--------------\n");
                printf("Mobile : %s\n",students[i].contact.mobile);

                printf("\n----------Academic Details-------------\n");
                printf("Course : %s\n",students[i].academic.course);
                printf("Semester : %d\n",students[i].academic.semester);
                printf("cgpa : %f\n",students[i].academic.cgpa);
            }
        }
        free(s);
        break;
    
    default:
        printf("Enter valid value\n");
    }
}

void updatestudent(void){
    int idd,found=0,i;
    printf("enter your id\n");
    scanf("%d",&idd);
    for(i=0;i<countstudent;i++){
            if(students[i].id==idd){
                found =1;
                break;
            }
    }
    if(found == 0){
        printf("Student not found\n");
        return;
    }

    printf("\nStudent found! Enter updated deatails.\n");
    // Personal Details
    printf("\n--- PERSONAL DETAILS ---\n");

    printf("Enter Name: \n");
    scanf(" %49[^\n]", students[i].name);

    printf("Enter Age: \n");
    scanf("%d", &students[i].age);

    printf("Enter Gender: \n");
    scanf(" %c", &students[i].gender);

    // Contact Details
    printf("\n--- CONTACT DETAILS ---\n");

    printf("Enter Mobile Number: \n");
    scanf("%15s", students[i].contact.mobile);

    // Academic Details
    printf("\n--- ACADEMIC DETAILS ---\n");

    printf("Enter Course: \n");
    scanf(" %29[^\n]", students[i].academic.course);

    printf("Enter Semester: \n");
    scanf("%d", &students[i].academic.semester);

    printf("Enter CGPA: \n");
    scanf("%f", &students[i].academic.cgpa);

    saveStudents();

    printf("\nStudent details updated successfully!\n");

}

void deletestudent(void){
    int idd,i,j;
    char password[30],found = 0;
    printf("First Enter password to delete student data\n");
    scanf("%s",password);
    if(strcmp(password,"admin12345")==0){
        printf("Enter id to delte\n");
        scanf("%d",&idd);
        for(i=0;i<countstudent;i++){
            if(students[i].id==idd){
                found = 1;
                break;
            }
        }
        if(found==1){
            for(j=i;j<countstudent-1;j++){
                students[j] = students[j+1];
            }
            countstudent--;

            saveStudents();
        }
        else{
            printf("Student not found\n");
        }
    }
    else{
        printf("Incorrect Password\n");
    }

}

void saveStudents(void)
{
    FILE *fp;

    fp = fopen("students.dat", "wb");

    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    // Save total student count
    fwrite(&countstudent, sizeof(int), 1, fp);

    // Save all student records
    if (countstudent > 0)
    {
        fwrite(students, sizeof(struct student),
               countstudent, fp);
    }

    fclose(fp);

    printf("Student data saved successfully!\n");
}

void loadStudents(void)
{
    FILE *fp;
    int savedCount;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        countstudent = 0;
        students = NULL;

        printf("No previous student records found.\n");
        return;
    }

    // Read total student count
    if (fread(&savedCount, sizeof(int), 1, fp) != 1 ||
        savedCount < 0 || savedCount > 100000)
    {
        printf("Invalid student data file!\n");
        fclose(fp);
        return;
    }

    struct student *temp = NULL;

    if (savedCount > 0)
    {
        temp = malloc(savedCount * sizeof(struct student));

        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }

        // Read student records
        if (fread(temp, sizeof(struct student),
                  savedCount, fp) != (size_t)savedCount)
        {
            printf("Unable to read student records!\n");
            free(temp);
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    students = temp;
    countstudent = savedCount;

    printf("%d student records loaded successfully!\n",
           countstudent);
}

void cleanupStudents(void)
{
    free(students);
    students = NULL;
    countstudent = 0;
}