# **Отчёт по лабораторной работе № 24** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «13» <ins>апреля</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «23» <ins>июня<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Обратная польская нотация
## 2. Цель работы
Составить программу выполнения заданных преобразований арифметических выражений с применением деревьев
## 3. Задание (Вариант №4)
Упростить выражения, выполнив деление:
4*a/2->2*b    

## 4. Оборудование
<b>Процессор:</b> 11th Gen Intel(R) Core (TM) i7-11370H 3.30GHz<br/>
<b>ОП: 16ГБ <br/>
<b>Монитор: 2880x1800 <br/>
## 5. Програмное обеспечение
<b>Опереционная система семейства: Linux Mint 21.1 Vera<br/>
<b>Интерпретатор команд:</b> bash, версия 5.1.16<br/>
<b>Система программирования:</b> --, версия --<br/>  
<b>Редактор текстов:</b> Vim, Visual Studio Code<br/>
<b>Утилиты операционной системы:</b> gcc,cat<br/>
<b>Прикладные системы и программы:</b>--<br/>
<b>Местанохождение и имена файлов программ и данных на домашнем компьютере:</b> home/alexey<br/>

## 6. Идея, метод, алгоритм   
1. Вводим выражения
2. Переводим его в обратную польскую нотацию   

## 7. Сценарий выполнения работы
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 24$ valgrind --leak-check=full ./main
==16072== Memcheck, a memory error detector
==16072== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==16072== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==16072== Command: ./main
==16072== 
 Input math expression: x+a*b*c/(a*b)/c/d+y+x^2
x+a*b*c/(a*b)/c/d+y+x^2
Postfix:xab*c*ab*/c/d/+y+x2^+
    2
  ^
    x
+
    y
  +
        d
      /
          c
        /
              b
            *
              a
          /
              c
            *
                b
              *
                a
    +
      x
Math expression after: (((x+(1/d))+y)+(x^2))
Tree: 
    2
  ^
    x
+
    y
  +
        d
      /
        1
    +
      x
==16072== 
==16072== HEAP SUMMARY:
==16072==     in use at exit: 0 bytes in 0 blocks
==16072==   total heap usage: 46 allocs, 46 frees, 4,820 bytes allocated
==16072== 
==16072== All heap blocks were freed -- no leaks are possible
==16072== 
==16072== For lists of detected and suppressed errors, rerun with: -s
==16072== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 24$ valgrind --leak-check=full ./main
==16085== Memcheck, a memory error detector
==16085== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==16085== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==16085== Command: ./main
==16085== 
 Input math expression: a*b/b
a*b/b
Postfix:ab*b/
  b
/
    b
  *
    a
Math expression after: a
Tree: 
a
==16085== 
==16085== HEAP SUMMARY:
==16085==     in use at exit: 0 bytes in 0 blocks
==16085==   total heap usage: 28 allocs, 28 frees, 4,388 bytes allocated
==16085== 
==16085== All heap blocks were freed -- no leaks are possible
==16085== 
==16085== For lists of detected and suppressed errors, rerun with: -s
==16085== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/Labs/lab 24$ 

```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 24$ make clean all
rm -fr *.o main
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c main.c -o main.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c extree.c -o extree.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c charstack.c -o charstack.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c node.c -o node.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c nodestack.c -o nodestack.o
gcc  main.o extree.o charstack.o node.o nodestack.o  -o main
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 13.04.23 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:     
Защита с Codeforces (div 2)     
[1797A](https://codeforces.com/contest/1797/submission/201328955) 
[1820A](https://codeforces.com/contest/1820/submission/202229298)
## 11. Выводы
Был изучен способ превращения арифметического выражения в обратную польскую нотацию.  
<b>Подпись студента:</b> ____________________
