#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a, b,j1=b;
    scanf("%d",&a);
    scanf("%d",&b);
    while (a!=b){
        j1=b;
        if ((abs(a-b))>=b){
            a=abs(a-b);
        }
        else {
            b=abs(b-a);
            a=j1;
        }
        printf("%d\t%d\t%d\n",a,b,abs(a-b));     
    }        
    printf ("%d\n",a);
    return 0;        
}
