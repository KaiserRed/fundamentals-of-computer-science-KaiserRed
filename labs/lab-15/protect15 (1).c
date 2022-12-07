#include <stdio.h>

enum { maxn = 100 };
int main(void){
    int m[maxn][maxn];
    int n, i, j;
    int two, repeat_1;
    scanf("%d", &n);
    for (int k = 0; k != n; ++k){
            scanf("%d", &i);
            scanf("%d", &j);
            two = 0;
            repeat_1 = 0;
            for (int x = 0; x != i; ++x){
                for (int y = 0; y != j; ++y){
                    if (two == 0){
                        m[x][y] = 0;
                        printf(" %d", m[x][y]);
                        two = 1;
                        continue;
                    }
                    else if (two == 1){
                        m[i][j] = 1;
                        printf(" %d", m[i][j]);
                        two = 2;
                        continue;
                    }
                    else if (two == 2){
                        m[x][y] = 1;
                        printf(" %d", m[x][y]);
                        two = 3;
                        continue;
                    }
                    else{
                        m[x][y] = 0;
                        printf(" %d", m[x][y]);
                        two = 0;
                        continue;
                    }                                          
                }
                printf("\n");
                if (repeat_1 < 2){
                    two = 2;
                    ++repeat_1;
                }
                else if (repeat_1 == 2){
                    two = 0;
                    ++repeat_1;
                }
                else if (repeat_1 == 3){
                    two = 0;
                    repeat_1 = 0;
                }
                     
            }
    }
        
    return 0;
}

