#include <stdio.h>
#include <limits.h>
enum { maxn = 10 };
void matrix_input(int n, int (*m)[n]);
void matrix_output(int n, int (*m)[n]);
void matrix_shuffle(int n, int(*m)[n]);

int main(){
    int m[maxn][maxn];
    int n;
    scanf("%d", &n);
    matrix_input(n, (int (*)[n]) m);         
    matrix_shuffle(n, (int (*)[n]) m);
    matrix_output(n, (int (*)[n]) m); 
    return 0;
}
void matrix_input(int n, int (*m)[n]){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &m[i][j]);
}
void matrix_output(int n, int (*m)[n]){
    for (int i = 0; i != n; ++i){
        for (int j = 0; j != n; ++j)
            printf("%d ", m[i][j]);
        printf("\n");
     }
}

void matrix_shuffle(int n, int(*m)[n]){
    int sum = 0,max = INT_MIN, min = INT_MAX, max_column = 0, min_column = 0;
    for (int j = 0; j != n; ++j){
        sum = 0;
        for (int i = 0; i != n; ++i){
             sum += m[i][j];
        }
        if (max < sum){
            max = sum;
            max_column = j;
        }
        if (min > sum){
            min = sum;
            min_column = j;
        }
    }
    for (int i = 0;  i != n; ++i){
        int temp = m[i][max_column];
        m[i][max_column] = m[i][min_column];
        m[i][min_column] = temp;
    }
}
