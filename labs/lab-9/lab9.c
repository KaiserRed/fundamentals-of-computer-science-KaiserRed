#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i, j, l;
}ring;

int max(int a, int b);
int min(int a, int b);
int sign(int a);

int main(void){
    ring s = {1,-30,1};
    for (int k = 0; k < 50; k++){
        ring b = {s.i,s.j,s.l};
        s.i = max(
              min(b.i + b.j - b.l -k, b.i - b.j + b.l - k),
              min(k + b.i - b.j - b.l, k - b.i - b.j + b.l)
        );
        s.j = b.j + (b.l * sign(b.j) % 20) + k * sign(b.i) % 10;
        s.l=abs(b.i - b.j + b.l - k) * sign(b.i) * sign(b.j);
        printf("Step X Y Movement %d %d %d %d\n",k, s.i, s.j ,s.l);
        if ((((s.i - 10) * (s.i - 10)) + ((s.j - 10) * (s.j - 10)) >= 25)
         & (((s.i - 10) * (s.i - 10)) + ((s.j - 10) * (s.j - 10)) <=100)){  
            printf("Point has reached destination %d %d %d %d\n", k, s.i ,s.j ,s.l);
            return 0;
        }
     
    }
 
    printf("Point has not reached destination%d %d %d\n",s.i,s.j,s.l);
    return 0;
    
}
int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}
int sign(int a) {
    return a > 0 ? 1 : a < 0 ? -1 : 0;
}

