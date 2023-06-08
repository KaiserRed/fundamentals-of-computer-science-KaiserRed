# **Отчёт по курсовой работе № 6** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «4» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «8» <ins>июня<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Обработка последовательной файловой структуры на языке Си
## 2. Цель работы
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом.  
Действие по выборке данных из файла оформить в виде отдельной программы с параметрами запроса,
вводимыми из стандартного входного текстового файла, или получаемыми из командной строки UNIX.
Второй способ задания параметров обязателен для работ, оцениваемых на хорошо и отлично. Параметры
задаются с помощью ключей –f (распечатка файла) или –p <parameter> (параметры конкретного варианта
задания). Получение параметров из командной строки производится с помощью стандартных библиотечных
функций argс и argv.
Cтруктуры данных и константы, совместно используемые программами, следует вынести в отдельный
заголовочный файл.
В процессе отладки и тестирования рекомендуется использовать команды обработки текстовых файлов
ОС UNIX и переадресацию ввода-вывода. Сгенерированные и отформатированные тестовые данные
необходимо заранее поместить в текстовые файлы и распечатывать при протоколировании. Рекомендуется
подобрать реальные или правдоподобные тестовые данные. Число наборов тестовых данных должно быть не
менее трёх. Имя файла с бинарными данными является обязательным параметром второй программы.
Отчёт должен содержать оценку пространственной и временной сложности использованного
## 3. Задание (Вариант №6)
Распечатать сведения обо всех компьютерах-серверах и рабочих станциях.

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
Для работы с бинарным файлом требуется два исполняемых файла: `pdump` и `pselect`. Первый принимает имя файла, в который будет дописано бинарное представление структуры из Си, а далее запрашивается пользовательский ввод полей структуры. Если хотя бы одно поле введено некоректно, то программа завершается аварийно и ничего не сохраняет в файл. Вторая программа требует два ключа с параметрами: `-f [filename]` и `-p [parameter]` и соовершает запрос к бинарнорму файлу `filename` (созданного прошлой утилитой) c параметром `parameter`. Эти два бинарника делят между собой объектный файл, содержащий тип компьютер с функциями выборки компьютеров-серверов и рабочих станция, соответсвующий заголовок `computer.h` подключается к исходникам обеих утилит. У функций выборки и отображения параметризован ввод/вывод посредством того, что они принимают функции ввода и вывода, которые реализуются в `main.c`.

Для вывода серверов нужно ввести параметр с 1 (-p1), для вывода рабочих станций - с 0 (-p0). Для вывода и того, и другого нужен параметр с 2 (-p2).
Компьютер-сервера и рабочие станции различаются количеством процессоров и объёмом жёсткого диска. У серверов обычно больше 6 процессоров, и объём жёсткого диска превышает 2 ТБ.
## 7. Сценарий выполнения работы
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pdump dump.dat
Host's surname: Muradin
Num of CPU: 1
Type of CPU: 32
RAM: 3.123
Num of hdd: 1
Type of largest hdd: SATA
Size of largest hdd: 0.5
OS: Windows7
Computer successfully dumped!
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pdump dump.dat
Host's surname: Menethil
Num of CPU: 8
Type of CPU: 64
RAM: 9
Num of hdd: 3
Type of largest hdd: SSD
Size of largest hdd: 5
OS: Ubuntu_server
Computer successfully dumped!
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pdump dump.dat
Host's surname: Newell 
Num of CPU: 4
Type of CPU: 64
RAM: 16
Num of hdd: 2
Type of largest hdd: SSD
Size of largest hdd: 1.2
OS: Windows10
Computer successfully dumped!
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pdump dump.dat
Host's surname: Petrov
Num of CPU: 7
Type of CPU: 32
RAM: 8
Num of hdd: 4
Type of largest hdd: PATA
Size of largest hdd: 4
OS: Windows_server
Computer successfully dumped!
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pselect -f dump.dat -p0 -
Surname: Muradin
Num of CPU: 1
Type of CPU: 32
RAM: 3.123000
Num of hdd: 1
Type of largest hdd: SATA
Size of largest hdd (TB): 0.500000
OS: Windows7
----------------
Surname: Newell
Num of CPU: 4
Type of CPU: 64
RAM: 16.000000
Num of hdd: 2
Type of largest hdd: SSD
Size of largest hdd (TB): 1.200000
OS: Windows10
----------------
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pselect -f dump.dat -p1 -
Surname: Menethil
Num of CPU: 8
Type of CPU: 64
RAM: 9.000000
Num of hdd: 3
Type of largest hdd: SSD
Size of largest hdd (TB): 5.000000
OS: Ubuntu_server
----------------
Surname: Petrov
Num of CPU: 7
Type of CPU: 32
RAM: 8.000000
Num of hdd: 4
Type of largest hdd: PATA
Size of largest hdd (TB): 4.000000
OS: Windows_server
----------------
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ bin/pselect -f dump.dat -p2 -
Surname: Muradin
Num of CPU: 1
Type of CPU: 32
RAM: 3.123000
Num of hdd: 1
Type of largest hdd: SATA
Size of largest hdd (TB): 0.500000
OS: Windows7
----------------
Surname: Menethil
Num of CPU: 8
Type of CPU: 64
RAM: 9.000000
Num of hdd: 3
Type of largest hdd: SSD
Size of largest hdd (TB): 5.000000
OS: Ubuntu_server
----------------
Surname: Newell
Num of CPU: 4
Type of CPU: 64
RAM: 16.000000
Num of hdd: 2
Type of largest hdd: SSD
Size of largest hdd (TB): 1.200000
OS: Windows10
----------------
Surname: Petrov
Num of CPU: 7
Type of CPU: 32
RAM: 8.000000
Num of hdd: 4
Type of largest hdd: PATA
Size of largest hdd (TB): 4.000000
OS: Windows_server
----------------
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ 

```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp6$ make clean all
rm -rf bin/*.o bin/pdump bin/pselect
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c computer.c -o bin/computer.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c dump_computer.c -o bin/dump_computer.o
gcc  bin/computer.o bin/dump_computer.o  -o bin/pdump
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c main.c -o bin/main.o
gcc   bin/computer.o bin/main.o   -o bin/pselect

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 18.05.23 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:     
Защита с Codeforces (div 2)     
https://codeforces.com/contest/1837/submission/207162390     
https://codeforces.com/contest/1837/submission/207221924        

## 11. Выводы
Был изучен способ работы с бинарным файлом на языке Си и написания сложного Makefile-а.   
<b>Подпись студента:</b> ____________________
