#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int i, j;
}Aff;
typedef struct{
    int x, y;
}XOY;
/* bool IsinPar(A.x, A.y, S.x, S.y, a.x, a.y, b.x, b.y) */
int main(void){
    float q, w, e, r, t, y;
    XOY S = {0, 0};
    Aff T = {0, 0};
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
    q = a.x;
    w = a.y;
    e = b.x;
    r = b.y;
    t = T.i;
    y = T.j;
    
    S.x = S.x - A.x;
    S.y = S.y - A.y;
    if (((q != 0) & (w != 0) & (e != 0) & (r != 0))
     | ((q == 0) & (w == 0))
     | (e == 0) & (r == 0)){
        printf("This is not a parallelogram \n");
        return 0;
    }
    
    if (r == 0){
        y = S.y / w;
        t = (S.x - y * q) / e;
    }
    
    if (w == 0){
        y = S.y / r;
        t = (S.x - y * e) / q;
    }
    if (e == 0){
        t = S.x / q;
        y = (S.y - t * w) / r;
    }
    
    if (q == 0){
        t = S.x / e;
        y = (S.y - t * r) / w;
    }   
    if ((t <= 1) & (y <= 1) & (t >= 0) & y >= 0){
        printf("Dot in the parallelogram\n");
        return 0;
    }
    printf("Dot not in the parallelogram\n");
    return 0;
}
