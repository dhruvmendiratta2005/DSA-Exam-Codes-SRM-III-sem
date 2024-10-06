//matrix multiplication using dma
#include <stdio.h>
#include <stdlib.h>

//matrix multiplication using dma
#include <stdio.h>
#include <stdlib.h>

int main(){
    int **a,**b,**c;
    int r1,c1,r2,c2;

    printf("\nEnter the no of rows and column for Mat1: ");
    scanf("%d %d",&r1,&c1);
    printf("\nEnter the no of rows and column for Mat2: ");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){
        printf("\nMatrix multiplication is not possible");
        return 0;
    }
//dma
    a=(int **)malloc(r1*sizeof(int *));
    b=(int **)malloc(r2*sizeof(int *));
    c=(int **)malloc(r1*sizeof(int *));
    for(int i=0;i<r1;i++){
        a[i]=(int*)malloc(c1*sizeof(int));
    }
    for(int i=0;i<r2;i++){
        b[i]=(int*)malloc(c2*sizeof(int));
    }
    for(int i=0;i<r1;i++){
        a[i]=(int*)malloc(c2*sizeof(int));
    }

    //input values
    printf("\nEnter the elements of Mat1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter the elements of Mat2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            c[i][j]=0;
        }
    }
    
    //matrix multiplication
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++){
                c[i][j]=a[i][k]*b[k][j];
            }
        }
    }
    //print resultant matrix
    printf("\nResultant Matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",c[i][j]);
        }
            printf("\n");
    }
    for(int i=0;i<r1;i++){
        free(a[i]);
        free(c[i]);
    }
    for(int i=0;i<r2;i++){
        free(b[i]);
    }
    free(a);
    free(b);
    free(c);  
}    