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
int main () {
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
                    q.i = c;
                    if ((b == 1)){
                        s.l = c;
                        b = 2;
                    }
                    if ((int) y.i < (int) c){
                        y.j = c;
                        m = 2;
                    }
                    state = ONE;
                }
                break;
           case ONE:
               s.i = c;
               q.j = c;
               state = TWO;
               if ((m == 2)){
                   m = 3;
                   y.l = c;
               }
               break;
          case TWO:
                y.i = c;
                m = 1;
                 q.l = c;
                 t = 1;
                 state = ZERO;
                  if ((int) s.i < (int) c){
                        s.j = c;
                        b = 1;
                   } 
                break;
            }

        if ((t == 1) & (q.i < q.j) & (q.j < q.l)){
            printf("= %c %c %c ", q.i, q.j, q.l);
            t = 0;
        }
        if ((b == 2) & (s.i < s.j) & (s.j < s.l)){
            printf("= %c %c %c ", s.i, s.j, s.l);
            b = 0;
        }
        if ((m == 3) & (isdigit(y.i) != 0) & (y.i < y.j) & (y.j < y.l)){
            printf("= %c %c %c ", y.i, y.j, y.l);
            m = 0;
        }
    }
    return 0;
}

