#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int min(int a, int b);
int sign(int a);

int main(void){
    int i = 1, j = -30, l = 1, ik = i, jk = j, lk = l;
    for (int k = 0; k < 50; k++){
        ik = i;
        jk = j;
        lk = l;
        i = max(
            min(ik + jk - lk - k,ik - jk + lk - k),
            min(k + ik - jk - lk, k - ik - jk + lk)
        );
        j = jk + (lk * sign(jk) % 20) + k * sign(ik) % 10;
        l=abs(ik - jk + lk - k) * sign(ik) * sign(jk);
        printf("Step X Y Movement %d %d %d %d\n",k,i,j,l);
        if ((((i - 10) * (i - 10)) + ((j - 10) * (j - 10)) >= 25) & (((i - 10) * (i - 10)) + ((j - 10) * (j - 10)) <=100)){  
            printf("Point has reached destination %d %d %d %d\n", k,i,j,l);
            return 0;
        }
     
    }
    printf("Point has not reached destination%d %d %d\n",i,j,l);
    return 0;
    
}
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}
int sign(int a) {
    if (a > 0) {
        return 1;
    }
    if (a == 0){
        return 0;
    }
    else {
        return -1;
    }
}
