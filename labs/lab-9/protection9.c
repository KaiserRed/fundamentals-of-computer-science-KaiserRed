#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float i, j;
}aff;
typedef struct{
    int x, y;
}XOY;

int main(void){
    XOY S = {0, 0};
    aff T = {0, 0};
    XOY A = {0, 0};
    XOY a = {0, 0};
    XOY b = {0, 0};
    printf("Coordinate of A\n");
    scanf("%d %d", &A.x, &A.y);
    printf("Coordinate of 1 vector\n");
    scanf("%d %d", &a.x, &a.y);
    printf("Coordinate of 2 vector\n");
    scanf("%d %d", &b.x, &b.y);
    printf("Coordinate of dot\n");
    scanf("%d %d", &S.x, &S.y);
    S.x = S.x - A.x;
    S.y = S.y - A.y;
    if (((a.x != 0) & (a.y != 0) & (b.x != 0) & (b.y != 0))
     | ((a.x == 0) & (a.y == 0))
     | (b.x ==0) & (b.y ==0)){
        printf("This is not a parallelogram \n");
        return 0;
    }
    
    if (b.y == 0){
        T.j = (float) S.y / a.y;
        T.i = (float) (S.x - T.j * a.x) / b.x;
    }
    
    if (a.y == 0){
        T.j = (float) S.y / b.y;
        T.i = (float) (S.x - T.j * b.x) / a.x;
    }
    if (b.x == 0){
        T.i = S.x / a.x;
        T.j = (S.y - T.i * a.y) / b.y;
    }
    
    if (a.x == 0){
        T.i = (float) S.x / b.x;
        T.j = (float) (S.y - T.i * b.y) / a.y;
    }   
    if ((T.i <= 1) & (T.j <= 1) & (T.i >= 0) & T.j >= 0){
        printf("Dot in the parallelogram\n%f, %f\n",T.i, T.j);
        return 0;
    }
    printf("Dot not in the parallelogram\n");
    return 0;
}

