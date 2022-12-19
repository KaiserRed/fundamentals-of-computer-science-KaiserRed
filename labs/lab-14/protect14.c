#include <stdio.h>

enum { maxn = 100 };
void matrix_input(int n, int (*m)[n]);
void first_left_z(int Size,int dot, int dot_2, int square, int triangle, int n, int (*m)[n]);
void left_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]);
void right_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]);
void reversed_right_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]);
void reversed_left_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]);

int main(void){
    int m[maxn][maxn];
    int n, Size, dot, dot_2, square, triangle;
    scanf("%d", &n);
    matrix_input(n, (int (*)[n]) m);
    first_left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
    return 0;
} 

void matrix_input(int n, int (*m)[n]){
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &m[i][j]);
}

void first_left_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]){
    int i = 0, j;
    for (j = 0; j != n; ++j)
        printf("%d ", m[i][j]);
    --j;
    for (i = 1; i != (n - 1); ++i){
        --j;
        printf("%d ", m[i][j]);
    }
    for (j = 0; j != n; ++j)
        printf("%d ", m[i][j]);
    square = (n - 1) / 2;
    Size = n ;
    dot_2 = square - 1;
    dot = 1;
    
    if (square > 0){
        triangle = Size - square - 2;
        right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        dot = dot + square - 1;
        dot_2 = dot_2 - square + 1;
        dot = dot + square - (Size % 2);
        dot_2 = dot_2 + Size - square;
        reversed_right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
    } 
    putchar('\n');
}

void right_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]){
    int i = dot;
    int Const1, Const2, Const3, Const4, triangle_Const;
    int j = dot_2;
    dot_2 = j;
    dot = i;
    for (int k = 0; k != square; ++k){
        printf("%d ", m[i][j]);
        --j;
    }
    if (((square + 1) / 2) > 0) {
        ++j;
        for (int k = 0; k != (square - 1); ++k){
            ++j;
            ++i;
            printf("%d ", m[i][j]);
        }
        for (int k = 0; k != (square - 1); ++k){
            --j;
            printf("%d ", m[i][j]);
        }
        Const1 = dot;
        Const3 = dot_2;
        Const4 = Size;
        Size = square;
        square = ((square - 1) / 2);
        dot_2 = dot_2 - square + 1;
        dot = i - Size + 2;
        triangle_Const = triangle;
        triangle = Size - square - 2;
        if (square > 0){
            left_z(Size, dot, dot_2,square, triangle, n, (int (*)[n]) m);
            Const2 = square;
            dot = i - 1;
            dot_2 = j + square - 1;  
            reversed_left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        }
    }
    triangle = triangle_Const;
    if (triangle > 0){
        square = (triangle + 1) / 2;
        triangle = triangle - square;
        dot = Const1;
        dot_2 = Const3 + square; 
        right_z(Size, dot, dot_2,square, triangle, n, (int (*)[n]) m);
        dot = i + 1;
        dot_2 = j + square - 1;
        right_z(Size, dot, dot_2,square, triangle, n, (int (*)[n]) m);
    }
}
void reversed_right_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]){
    int Const1, Const2, Const3, Const4, triangle_Const;
    int i = dot, j = dot_2;
    for (int k = 0; k != square; ++k){
        printf("%d ", m[i][j]);
        ++j;
    }
    if (((square + 1) / 2) > 0) {
        --j;
        for (int k = 0; k != (square - 1); ++k){
            --j;
            --i;
            printf("%d ", m[i][j]); 
        }
        for (int k = 0; k != (square - 1); ++k){
            ++j;
            printf("%d ", m[i][j]);
        }    
        Const1 = dot;
        Const3 = dot_2;
        Const4 = Size;
        Size = square;
        square = ((square - 1) / 2);
        dot = dot - 1;
        dot_2 = dot_2 + square - 1;
        triangle_Const = triangle;
        triangle = Size - square - 2;
        if (square > 0){
            reversed_left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
            dot = i + 1;
            dot_2 = j - square + 1;
            left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        }
    }
    triangle = triangle_Const;
    if (triangle > 0){
        square = (triangle + 1) / 2;
        triangle = triangle - square;
        dot = Const1;
        dot_2 = Const3 - square;
        reversed_right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        dot = i - 1;
        dot_2 = j - square + 1;
        reversed_right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
    }
}
void left_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]){
    int Const1, Const2, Const3, Const4, triangle_Const;
    int i = dot, j = dot_2;
    for (int k = 0; k != square; ++k){
        printf("%d ", m[i][j]);
        ++j;
    }
    if (((square + 1) / 2) > 0) {
        --j;
        for (int k = 0 ; k != (square - 1); ++k){
            --j;
            ++i;
            printf("%d ", m[i][j]);    
        }
        for (int k = 0; k != (square - 1); ++k){
            ++j;
            printf("%d ", m[i][j]);
        }
        Const1 = dot;
        Const2 = dot_2;
        Const4 = Size;
        Size = square;
        square = ((square - 1) / 2);
        dot_2 = dot_2 + square - 1;
        dot = dot + 1 ;
        triangle_Const = triangle;
        triangle = Size - square - 2;
        if (square > 0){
            right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
            dot = i - 1;
            dot_2 = j - square + 1;
            reversed_right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        }
    }
    triangle = triangle_Const;
    if (triangle > 0){
        square = (triangle + 1) / 2;
        triangle = triangle - square;  
        dot = Const1;
        dot_2 = Const2 - square;
        left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        dot = i + 1;
        dot_2 = j - square + 1;
        left_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
    }
}
void reversed_left_z(int Size, int dot, int dot_2, int square, int triangle, int n, int (*m)[n]){
    int Const1, Const2, Const3, Const4, triangle_Const;
    int i = dot, j = dot_2;
    for (int k = 0; k != square; ++k){
        printf("%d ", m[i][j]);
        --j;
    }
    if (((square + 1) / 2) > 0) {
        ++j;
        for (int k = 0; k != (square - 1); ++k){
            ++j;
            --i;
            printf("%d ", m[i][j]); 
        }
        for (int k = 0; k != (square - 1); ++k){
            --j;
            printf("%d ", m[i][j]);
        }
        Const1 = dot;
        Const2 = dot_2;
        Const4 = Size;
        Size = square;
        square = ((square - 1) / 2);
        dot_2 = dot_2 - square + 1;
        dot = dot - 1;
        triangle_Const = triangle;
        triangle = Size - square - 2;
        if (square > 0){
            reversed_right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
            dot = i + 1;
            dot_2 = j + square - 1;
            right_z(Size, dot, dot_2, square, triangle, n, (int (*)[n]) m);
        }
    }
    triangle = triangle_Const;
    if (triangle > 0){
        square = (triangle + 1) / 2;
        triangle = triangle - square;
        dot = Const1;
        dot_2 = Const2 + square;
        reversed_left_z(Size, dot, dot_2,square, triangle, n, (int (*)[n]) m);
        dot = i - 1;
        dot_2 = j + square - 1;   
        reversed_left_z(Size, dot, dot_2,square, triangle, n, (int (*)[n]) m);  
    }
}
