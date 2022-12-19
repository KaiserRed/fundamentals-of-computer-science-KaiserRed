# **Отчёт по лабораторной работе № 14** по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «1» <ins>декабря</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «3» <ins>декабря<ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Вложенные циклы с параметрами. Обход и линеаризация матриц.
## 2. Цель работы
Составить программу на языке Си, выполняющую ввод квадратной матрицы и печати в строку всех её элементов в заданном порядке следования.
## 3. Задание (Вариант №3)
| 16 | 15 | 13 | 10 |
| -- | --- | --- | --- |
| 14 | 12 | 9 | 6 |
| 11 | 8 | 5 | 3 |
| 7 | 4 | 2 | 1 |

## 4. Оборудование
<b>Процессор:</b> 11th Gen Intel(R) Core (TM) i7-11370H 3.30GHz<br/>
<b>ОП: 16ГБ <br/>
<b>Монитор: 2880x1800 <br/>
## 5. Програмное обеспечение
<b>Опереционная система семейства: VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS<br/>
<b>Интерпретатор команд:</b> bash, версия 5.1.16<br/>
<b>Система программирования:</b> --, версия --<br/>  
<b>Редактор текстов:</b> emacs, версия **28.2**<br/>
<b>Утилиты операционной системы:</b> gcc,cat<br/>
<b>Прикладные системы и программы:</b>--<br/>
<b>Местанохождение и имена файлов программ и данных на домашнем компьютере:</b> home/alexey<br/>
## 6. Идея, метод, алгоритм
1. Будем считывать число n (размерность матрицы), пока не считаем конец файла. 
2. Заметим, что необходимо вывести элементы по диагоналям с правого нижнего угла до левого верхнего.
3. Во время перехода на новую диагональ уменьшается номер столбцы. В самой диагонали номер столбца увеличивается на 1, а номер строки уменьшается на 1. Когда номер столбца будет равен размеру матрицы, переходим на следующую диагональ.
4. После прохождения наибольшей диагонали (количество элементов на неё равно размеру матрицы) уменьшаем размер матрицы на 1 и увеличиваем номер строки на 1.
5. Повторяем 3-4 пункты, до конца.
## 7. Сценарий выполнения работы
Тесты:    
Ввод:   
5   
1 2 3 4 17   
5 6 7 8 18    
9 10 11 12 19   
13 14 15 16 20   
21 22 23 24 25   
Вывод: 25 24 20 23 16 19 22 15 12 18 21 14 11 8 17 13 10 7 4 9 6 3 5 2 1    
Ввод:   
4   
16 15 13 10   
14 12 9 6   
11 8 5 3   
7 4 2 1   
Вывод: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16   
Ввод:    
2   
1 2   
3 4   
Вывод 4 3 2 1      
Код:
```
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
                                
```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-VirtualBox:~$ cat h.txt
4
16 15 13 10
14 12 9 6
11 8 5 3
7 4 2 1
alexey@alexey-VirtualBox:~$ gcc -std=c18 lab14.c
alexey@alexey-VirtualBox:~$ ./a.out < h.txt
12345678910111213141516
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 03.12.22 | 14:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
Во время защиты было дано задание:
1) пусть есть квадратная матрица
2) рисуем в ней левую z.
3) остается две треугольные области
4) выделяем в каждой настолько большой квадрат, насколько можно.
5) запускаемся рекурсивно два раза (т.е. от каждого), но если была левая z, то будет правая. Т.е. идем в пункт 1.
6) остается 4 треугольные области. Идем в пункт 4.
```
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

```
## 11. Выводы
Была изучена работа с квадратными матрицами на языке Си.
  
