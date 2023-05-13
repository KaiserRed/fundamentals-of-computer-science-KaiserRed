# **Отчёт по лабораторной работе № 25-26** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «13» <ins>апреля</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «15» <ins>апреля<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Автоматизация сборки программ модульной структуры на языке Си с использованием утилиты make. Абстрактные типы данных. Рекурсия. Модульное программирование на Си.
## 2. Цель работы
Составить и отладить модуль определений и модуль реализации по заданной схеме определений для стека.
## 3. Задание (Вариант №3)
Слияние двух стеков, упорядоченных по возрастанию, с сохранением порядка с помощью сортировки слиянием.

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
Метод сортировки слиянием состоит в:
1. Сортируемый массив разбивается на две части примерно одинакового размера;   
2. Каждая из получившихся частей сортируется отдельно, например — тем же самым алгоритмом;   
3. Два упорядоченных массива половинного размера соединяются в один.   
Функциональная спецификация стека:   
1. Создать   
2. Проверка на пустоту   
3. Размер   
4. В стек   
5. Из стека    
6. Верхний элемент    
7. Уничтожить стек    

## 7. Сценарий выполнения работы
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/Labs/lab 25-26$ ./main
5
8 12 67 3 1
1 3 8 12 67 
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/Labs/lab 25-26$ ./main
3 
8 4 7
4 7 8 
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/Labs/lab 25-26$ 

```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/Labs/lab 25-26$ make clean all
rm -fr *.o main
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c main.c -o main.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c stack.c -o stack.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c sort.c -o sort.o
gcc  main.o stack.o sort.o  -o main

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 13.04.23 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:     
Защита с Codeforces (div 2)     
https://codeforces.com/contest/1798/submission/199287338   
Дорешка     
https://codeforces.com/contest/1798/submission/202175530   

Защита с Codeforces (div 3)    
https://codeforces.com/contest/1812/submission/200190374    
https://codeforces.com/contest/1812/submission/200190374     
Дорешка   
https://codeforces.com/contest/1812/submission/202173772    

## 11. Выводы
Был изучен способ работы с абстрактным типом данным(стеком), метод сортировки слиянием. Были полчены навыки модульного программирования на языке Си.     
<b>Подпись студента:</b> ____________________