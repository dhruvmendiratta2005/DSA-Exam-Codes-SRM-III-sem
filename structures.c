#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student{
    int reg;
    char name[20];
    double marks;
};
int main(){
    int i,n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid input");
        exit(0);
    }

    struct Student student[n];
    for(i=0;i<n;i++){
        printf("Enter the registration number of student %d: ",i+1);
        scanf("%d",&student[i].reg);
        printf("Enter the name of student %d: ",i+1);
        scanf("%s",student[i].name);
        printf("Enter the marks of student %d: ",i+1);
        scanf("%lf",&student[i].marks);
    }
    printf("\nStudent details are:\n");
    for(i=0;i<n;i++){
        printf("\nRegistration number: %d",student[i].reg);
        printf("\nName: %s",student[i].name);
        printf("\nMarks: %lf\n",student[i].marks);
    }
}