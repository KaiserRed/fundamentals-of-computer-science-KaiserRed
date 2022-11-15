#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char c;
    int a = 0, k = 1, i, t = 0, q = 0, e = 1;
    while ((c = getchar()) != EOF){
        if ((c == '{') & (k == 1) & (e == 1)) {
            k = 2;
            a = t;
        }
        if ((k == 2) & (c == '}')){
            k = 1;
        }
        if ((isalpha(c) != 0) & (k == 2)) { 
            q = 1;
        }
        if ((isspace(c) != 0) & (q == 1)){
            q = 0;
            t++;
        }
        if ((c == '*') & (k == 1) & (e == 1))
            e = 2;
        else if ((e == 2) & (c == '\n')){
            e = 1;   
        }
        if ((isalpha(c) != 0) & (e == 2)) { 
            q = 1;
        }
    }
    
    if (k == 2){
        printf("Comment is still open\n");
        return 0;
    }
    printf("Word count  = %d\n", t);
    return 0;
}

