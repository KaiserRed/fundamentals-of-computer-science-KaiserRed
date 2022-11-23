#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct{
    char i, j, l;
}three;
enum State {
    ZERO,
    ONE,
    TWO
};
int Digit_count ();

int main () {
    printf("%c\n", Digit_count());
    return 0;
    }
int Digit_count () {
    char c;
    enum State state = ZERO;
    int t = 0, a = 0, b = 0, g = 0, m = 0;
    three q = {0, 0, 0};
    three s = {0, 0, 0};
    three y = {0, 0, 0};
    for (c = getchar(); c != EOF; c = getchar()){
        switch (state) {
            case ZERO:
                if ((isdigit(c) != 0)){
                    t = 0;
                    q.i = c;
                    if ((b == 1)){
                        s.l = c;
                        b = 2;
                    }
                    if ((int) y.i < (int) c){
                        y.j = c;
                        m = 2;
                    }
                    if ((b == 2) & (isdigit(s.i) != 0) & (s.i < s.j) & (s.j < s.l)){
                        printf("%c%c%c\n", s.i, s.j, s.l);
                        b = 0;
                        s.i = 0;
                        s.j = 0;
                        s.l = 0;
                    }  
                    state = ONE;
                }
                break;
           case ONE:
               b = 0;
               s.i = c;
               q.j = c;
               state = TWO;
               if ((m == 2)){
                   m = 3;
                   y.l = c;
               }
               if ((m == 3) & (isdigit(y.i) != 0) & (y.i < y.j) & (y.j < y.l)){
                   printf("%c%c%c\n", y.i, y.j, y.l);
                   m = 0;
                   y.i = 0;
                   y.j = 0;
                   y.l = 0;
               }
               
               break;
          case TWO:
                y.i = c;
                m = 1;
                q.l = c;
                t = 1;
                if ((isdigit(q.i) != 0) & (q.i < q.j) & (q.j < q.l)){
                    printf("%c%c%c\n", q.i, q.j, q.l);
                    t = 0;
                    q.i = 0;
                    q.j = 0;
                    q.l = 0;
                }
                state = ZERO;
                if ((int) s.i < (int) c){
                    s.j = c;
                    b = 1;
                } 
                break;
            
        
        
        }
    }
    return 0;
}

