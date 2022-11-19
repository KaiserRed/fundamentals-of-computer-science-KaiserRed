#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
enum State {
    OUTSIDE,
    INSIDE,
    ASTERISK
};
int Word_count();

int main () {
    printf("Word count =  %d\n", Word_count());
    return 0;
}

int Word_count() {
enum State state = OUTSIDE;
    char c;
    int t = 0, q = 0, e = 1;
    /*while ((c = getchar()) != EOF){*/
    for (c = getchar(); c != EOF; c = getchar())
        switch (state) {            
            case INSIDE:
                if (c == '}'){
                    state = OUTSIDE;
                    e = 1;
                 }
                if (isalnum(c) != 0){
                    q = 1;
                }
                if (((isspace(c) != 0) | (c =='}')) & (q == 1)){
                    q = 0;
                    t++;
                }
                break;
            case ASTERISK: 
                if ((c == '\n') & (e != 0)){
                    state = OUTSIDE;
                }
                if (isalnum(c) != 0)
                    q = 1;
                if (((isspace(c) != 0) | (c =='*')) & (q == 1)){
                    q = 0;
                    t++;
                }
                if (c == '*')
                    state = OUTSIDE;
                break;
            case OUTSIDE:
                if (c == '{'){
                    state = INSIDE;
                    e = 0;
                }
                if ((c == '*'))
                    state = ASTERISK;
                break;
        }
    
    return t;
}
