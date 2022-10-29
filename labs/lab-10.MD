# **Отчёт по лабораторной работе № 10** по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «28» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой 5:</b> <ins></ins>

<b>Отчет сдан</b> «29» <ins>октября<ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Отладчик системы программирования OC Unix.

## 2. Цель работы
Научиться отлаживать простейшие программы, написанные на языке Си.
## 3. Задание (Вариант №)
  
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
1. Скомпиилируем исходную программу с помощью ключа компилятора -g   
2. Проверим команды gdb.  
  
| Команда gdb | Описание |
| ------------- | ----------- |
| <b>help</b> [<раздел>]| подсказка по разделу помощи отладчика. <b>help</b> без параметров выводит список разделов |
| <b>list</b> [<имя функции/процедуры/файла>:] [номер строки] | распечатка текста функции/файла или всей программы, начиная с указанной строки.  По умолчанию распечатываются следующие 10 строк программы. Распечатываемый файл становится текущим файлом исходного текста отлаживаемой программы.|
| <b>break</b> <номер строки/имя функции>|задание точки остановка на указанной строке/функции текущего исходного файла прогрммы|
| <b>run</b> /<параметры>/| запуск программы на выполнение. Могут указываться необязательные параметры командной строки и операции перенаправления ввода-ввывода.<b>gdb</b> запоминает параметры и подставляет их при дальнейших вызовах <b>run</b>|
| <b>set args</b> /<параметры>/| предваритлеьная установка параметров командной строки|
| <b>print</b> <выражение>| печать значения выражения, которое может включать и переменные, и вызовы функций программы|
| <b>next</b> /< n >/| выполнение очередной строки программы при пошаговой трассировке (процедуры и функции не трассируются, а выполняются за один такст). Необязательный параметр n указывает число строк программы для выполнения (по умолчанию — 1)|
| <b>step</b> /< n >/ |выполнение очередной строки программмы( с трассировкой вызовов функций/процедур). Перед выполнением next/step программа должна быть запущена командой <b>run</b>|
| <b>set var</b> <имя> — <выражение> | присваивание значения переменной|
| <b>ptype</b> <имя-переменной>|распечатка определения типа переменной (на языке программирования)|
| <b>backtrace</b> или <b>bt</b>|распечатка содержимого стека вызовов|
| <b>continue</b> |продолжение выполнения программы после остановки|
| <b>quit</b> |выход из отладчика|

## 7. Сценарий выполнения работы
1. Скомпилируем при помощи команды gcc и ключа -g прогрмму lab9.c (gcc -g lab9.c)   
2. Запустим отладку с помощью команды gdb (gdb a.out)   
3. Проделаем все действия по отладке прогрммы.

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-VirtualBox:~$ gcc -g -std=c18 lab9.c
alexey@alexey-VirtualBox:~$ gdb ./a.out
GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./a.out...
(gdb) help
List of classes of commands:

aliases -- User-defined aliases of other commands.
breakpoints -- Making program stop at certain points.
data -- Examining data.
files -- Specifying and examining files.
internals -- Maintenance commands.
obscure -- Obscure features.
running -- Running the program.
stack -- Examining the stack.
status -- Status inquiries.
support -- Support facilities.
text-user-interface -- TUI is the GDB text based interface.
tracepoints -- Tracing of program execution without stopping the program.
user-defined -- User-defined commands.

Type "help" followed by a class name for a list of commands in that class.
Type "help all" for the list of all commands.
Type "help" followed by command name for full documentation.
Type "apropos word" to search for commands related to "word".
Type "apropos -v word" for full documentation of commands related to "word".
Command name abbreviations are allowed if unambiguous.
(gdb) help data
Examining data.

List of commands:

agent-printf -- Target agent only formatted printing, like the C "printf" function.
append -- Append target code/data to a local file.
append binary -- Append target code/data to a raw binary file.
append binary memory -- Append contents of memory to a raw binary file.
append binary value -- Append the value of an expression to a raw binary file.
append memory -- Append contents of memory to a raw binary file.
append value -- Append the value of an expression to a raw binary file.
call -- Call a function in the program.
disassemble -- Disassemble a specified section of memory.
display -- Print value of expression EXP each time the program stops.
dump -- Dump target code/data to a local file.
dump binary -- Write target code/data to a raw binary file.
dump binary memory -- Write contents of memory to a raw binary file.
dump binary value -- Write the value of an expression to a raw binary file.
dump ihex -- Write target code/data to an intel hex file.
dump ihex memory -- Write contents of memory to an ihex file.
dump ihex value -- Write the value of an expression to an ihex file.
dump memory -- Write contents of memory to a raw binary file.
dump srec -- Write target code/data to an srec file.
dump srec memory -- Write contents of memory to an srec file.
dump srec value -- Write the value of an expression to an srec file.
dump tekhex -- Write target code/data to a tekhex file.
dump tekhex memory -- Write contents of memory to a tekhex file.
dump tekhex value -- Write the value of an expression to a tekhex file.
dump value -- Write the value of an expression to a raw binary file.
dump verilog -- Write target code/data to a verilog hex file.
dump verilog memory -- Write contents of memory to a verilog hex file.
dump verilog value -- Write the value of an expression to a verilog hex file.
explore -- Explore a value or a type valid in the current context.
explore type -- Explore a type or the type of an expression.
explore value -- Explore value of an expression valid in the current context.
find -- Search memory for a sequence of bytes.
init-if-undefined -- Initialize a convenience variable if necessary.
mem -- Define attributes for memory region or reset memory region handling to target-based.
memory-tag -- Generic command for printing and manipulating memory tag properties.
memory-tag check -- Validate a pointer's logical tag against the allocation tag.
memory-tag print-allocation-tag -- Print the allocation tag for ADDRESS.
memory-tag print-logical-tag -- Print the logical tag from POINTER.
memory-tag set-allocation-tag -- Set the allocation tag(s) for a memory range.
memory-tag with-logical-tag -- Print a POINTER with a specific logical TAG.
output -- Like "print" but don't put in value history and don't print newline.
print, inspect, p -- Print value of expression EXP.
print-object, po -- Ask an Objective-C object to print itself.
printf -- Formatted printing, like the C "printf" function.
ptype -- Print definition of type TYPE.
restore -- Restore the contents of FILE to target memory.
set -- Evaluate expression EXP and assign result to variable VAR.
set ada -- Prefix command for changing Ada-specific settings.
set ada print-signatures -- Enable or disable the output of formal and return types for functions in the overloads selection menu.
set ada source-charset -- Set the Ada source character set.
set ada trust-PAD-over-XVS -- Enable or disable an optimization trusting PAD types over XVS types.
set agent -- Set debugger's willingness to use agent as a helper.
set annotate -- Set annotation_level.
set architecture, set processor -- Set architecture of target.
set args -- Set argument list to give program being debugged when it is started.
set auto-connect-native-target -- Set whether GDB may automatically connect to the native target.
set auto-load -- Auto-loading specific settings.
set auto-load gdb-scripts -- Enable or disable auto-loading of canned sequences of commands scripts.
set auto-load libthread-db -- Enable or disable auto-loading of inferior specific libthread_db.
set auto-load local-gdbinit -- Enable or disable auto-loading of .gdbinit script in current directory.
set auto-load python-scripts -- Set the debugger's behaviour regarding auto-loaded Python scripts.
set auto-load safe-path -- Set the list of files and directories that are safe for auto-loading.
set auto-load scripts-directory -- Set the list of directories from which to load auto-loaded scripts.
set auto-solib-add -- Set autoloading of shared library symbols.
set backtrace -- Set backtrace specific variables.
set backtrace limit -- Set an upper bound on the number of backtrace levels.
set backtrace past-entry -- Set whether backtraces should continue past the entry point of a program.--Type <RET> for more, q to quit, c to continue without paging--q
Quit
(gdb) list
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) list 1
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) list 10
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
11	        ik=i;
12	        jk=j;
13	        lk=l;
14	        i=(max(min(ik+jk-lk-k,ik-jk+lk-k), min(k+ik-jk-lk, k-ik-jk+lk)));
(gdb) list 4
1	#include <stdio.h>
2	#include <stdlib.h>
3	
4	int max(int a, int b);
5	int min(int a, int b);
6	int sign(int a);
7	
8	int main(void){
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
10	    for (int k=0;k<50;k++){
(gdb) breaak 5
Undefined command: "breaak".  Try "help".
(gdb) break 5
Breakpoint 1 at 0x1156: file lab9.c, line 9.
(gdb) run
Starting program: /home/alexey/a.out 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at lab9.c:9
9	    int i=1, j=-30, l=1, ik=i, jk=j, lk=l;
(gdb) next
10	    for (int k=0;k<50;k++){
(gdb) step
11	        ik=i;
(gdb) continue
Continuing.
Попадание в заданную область 3 8 6 -8
[Inferior 1 (process 28248) exited normally]
(gdb) break
Breakpoint 2 at 0x555555555189: file lab9.c, line 11.
(gdb) quit


```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 2809.22 | 13:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы

## 11. Выводы
Был изучен способ отладки программ, написанных на языке Си. 
  
