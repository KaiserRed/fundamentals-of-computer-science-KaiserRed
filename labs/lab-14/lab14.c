#include <stdio.h>

enum { maxn = 100 };

int main(){
    int m[maxn][maxn];
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &m[i][j]);
    int l = n;
    int p = 0;
    int i = l - 1, j = l - 1;
    while (i != 0 & j != 0){
        j = i - 1;
        i = l;
        if (i != n)
            printf("%d\n", m[i][j]);
        while (j != l & j < n){
            i-=1;
            j+=1;
            if (j == n)
                break;
            printf("%d\n", m[i][j]);
        }
        if (i == 0){
            l-=1;
            i+=1;
        }
    
    }
    putchar('\n');
    return 0;
}  
