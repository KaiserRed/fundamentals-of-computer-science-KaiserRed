# **Отчёт по лабораторной работе №23** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «4» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «5» <ins>мая<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу на языке Си для построения и обработки дерева общего вида или упорядочного двоичного дерева с float узлами 
## 3. Задание (Вариант №3)
Определить значение листа дерева, имеющего минимальную глубину.
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
1. Создадим дерево общего вида, содержащее ссылку на сына, брата и родителя.     
2. Создадим функции, позволяющие работать с деревом: создание корня, добавление узла, удаление узла, вывод дерева прямым обходом, вывод дерева концевым обходом.    
3. Создаём функцию, которая находит прямым обходом минимальный лист. Если проверка на наличие сына даёт NULL, то значение и глубину узла переносим в функцию, которая по глубине выбирает нужный лист. В итоге нужный лист будет тем листом, у которого минимальная глубина и который последний встретился.
## 7. Сценарий выполнения работы
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 23$ ./main
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
1
Write tree's root
1
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
2 
Write tree node value
2
Write parent value
1
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
2
Write tree node value
3.1
Write parent value
1
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
2
Write tree node value
4
Write parent value
1
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
2
Write tree node value
5
Write parent value
2
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
2
Write tree node value
6.12
Write parent value
2
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
5
1.00
	2.00
		5.00
		6.12
	3.10
	4.00
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
6
5.00
6.12
2.00
3.10
4.00
1.00
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
4
4.00
1. Create tree	 2. Add node to tree	 3. Delete node from tree	 4. Task 5. Pre_Order	6. Post_Order	 7. Exit 
7
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 23$ 

```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 23$ make clean all
rm -fr *.o main
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c main.c -o main.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c tree.c -o tree.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c minleaf.c -o minleaf.o
gcc  main.o tree.o minleaf.o  -o main
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/labs/lab 23$ ./main

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 13.04.23 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:    
Защита с Codeforces (div 2)     
https://codeforces.com/contest/1802/submission/196638278    
Дорешка     
https://codeforces.com/contest/1802/submission/197831976
## 11. Выводы
Была изучена работа с деревом общего вида и изучены базовые понятия у дерева: глубина дерева, лист, ширина, степень Были отработаны прямой и концевой обходы для дерева общего вида.    
<b>Подпись студента:</b> ____________________
