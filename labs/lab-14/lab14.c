#include <stdio.h>

enum { maxn = 10 };
void matrix_input(int n, int (*m)[n]);
void matrix_output(int n, int (*m)[n]);

int main(void){
    int m[maxn][maxn];
    int n;
    scanf("%d", &n);
    matrix_input(n, (int (*)[n]) m);
    matrix_output(n, (int (*)[n]) m);
    return 0;
} 

void matrix_input(int n, int (*m)[n]){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &m[i][j]);
}

void matrix_output(int n, int (*m)[n]){
    int l = n;
    int i = l - 1, j = l - 1;
    while (i != 0 & j != 0){
        j = i - 1;
        i = l;
        if (i != n)
            printf("%d ", m[i][j]);
        while (j != l & j < n){
            i-=1;
            j+=1;
            if (j == n)
                break;
            printf("%d ", m[i][j]);
        }
        if (i == 0){
            l-=1;
            i+=1;
        }
    
    }
    putchar('\n');
}
