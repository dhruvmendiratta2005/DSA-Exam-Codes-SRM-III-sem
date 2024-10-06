#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp{
    int id;
    char name[20];
    double salary;
};
int main(){
    int n;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    struct emp *ptr;
    ptr=(struct emp *)malloc(n*sizeof(struct emp));
    for(int i=0;i<n;i++){
        printf("\nEnter the details for the employees");
        printf("\nId:");
        scanf("%d",&(ptr+i)->id);
        printf("\nName");
        scanf("%s",(ptr+i)->name);
        printf("\nSalary:");
        scanf("%lf",&(ptr+i)->salary);
    }
    printf("\nEmployee details are:");
    for(int i=0;i<n;i++){
        printf("\nId: %d",(ptr+i)->id);
        printf("\nName: %s",(ptr+i)->name);
        printf("\nSalary: %lf",(ptr+i)->salary);
    }
}