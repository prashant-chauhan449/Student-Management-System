#ifndef STUDENT_H
#define STUDENT_H
struct Contact{
    char mobile[16];
};
struct Academic{
    char course[30];
    int semester;
    float cgpa;
};
struct student{
    int id;
    char name[50];
    int age;
    char gender;
    struct Contact contact;
    struct Academic academic;
};
void addstudent(void);
void displaystudents(void);
void searchstudent(void);
void updatestudent(void);
void deletestudent(void);
void adminlogin(void);
void saveStudents(void);
void loadStudents(void);
void cleanupStudents(void);
#endif