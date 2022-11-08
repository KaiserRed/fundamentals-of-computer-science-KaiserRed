#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b);
int lcm(int a, int b);
int main(void){
    int a, b,d;
    scanf("%d%d",&a, &b);
    printf("%d\n", gcd(a,b));
    printf("%d\n", lcm(a,b));
    return 0;        
}   
int gcd(int a, int b) {
    while (b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return abs(a); 
}
int lcm(int a,int b){
    return abs(a / gcd(a, b) * b);
}
