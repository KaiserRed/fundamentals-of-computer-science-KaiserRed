# **Отчёт по лабораторной работе № 1-2** по курсу "Фундаментальная информатика"

Студент группы: М8О-108Б-22 № по списку 3

Контакты: alexgalkin2004@mail.ru

Работа выполнена: "21" сентября 2022 г.

Преподаватель: Сахарин Никита Александрович каф.806

Входной контроль знаний с оценкой 

Отчёт сдан " " сентября 2022 г. итоговая оценка

**Тема** Операционная среда UNIX 

**Цель работы** Освоение программного обеспечения UNIX

**Задание**
Ознакомиться с сервисными функциями. Работа с директориямми. Создание, удаление файлов и директорий и перемещение по ним. 

**Сценарий выполнения работы**

Посмотреть содержимого каталога:
```
alexey@alexey-VirtualBox:~$ dir
snap  Видео  Документы  Загрузки  Изображения  Музыка  Общедоступные  Рабочий\ стол  Шаблоны
```
Создать пустой файл:
```
alexey@alexey-VirtualBox:~$ touch text.txt
```
Записать строку в пустой файл:
```
alexey@alexey-VirtualBox:~$ echo 1234567890 > text.txt
```
Вывести содержимое файла:
```
alexey@alexey-VirtualBox:~$ cat text.txt
1234567890
```
Скопировать файл text.txt в файл text2.txt:
```
alexey@alexey-VirtualBox:~$ cp text.txt text2.txt
```
Сконкатенировать файлы text.txt и text2.txt в файл text3.txt:
```
alexey@alexey-VirtualBox:~$ cat text.txt text2.txt > text3.txt
```
Вывести содержимое файла:
```
alexey@alexey-VirtualBox:~$ cat text3.txt
1234567890
1234567890
```
Удалить файлы text2.txt и text3.txt:
```
alexey@alexey-VirtualBox:~$ rm text2.txt text3.txt
```
Создать подкаталоги lab и course в домашней директории:
```
alexey@alexey-VirtualBox:~$ mkdir lab course
```
Скопировать файл text.txt в подкаталоги lab и course и удалить исходный файл:
```
alexey@alexey-VirtualBox:~$ cp text.txt ~/lab/
alexey@alexey-VirtualBox:~$ cp text.txt ~/course/
alexey@alexey-VirtualBox:~$ rm text.txt
```
Проверить наличие файла в одном из подкаталогов и удалить его:
```
alexey@alexey-VirtualBox:~$ cd lab
alexey@alexey-VirtualBox:~/lab$ ls
text.txt
alexey@alexey-VirtualBox:~/lab$ rm text.txt
```
Вернуться в домашнюю директорию и удалить подкаталоги:
```
alexey@alexey-VirtualBox:~$ rmdir ~/lab/ ~/course/
rmdir: не удалось удалить '/home/alexey/course/': Каталог не пуст
```
Нам не удалось удалить подкаталог course, так как в нём есть файл, то есть он не пуст. Для решения проблемы надо очистить подкаталог:
```
alexey@alexey-VirtualBox:~$ cd course
alexey@alexey-VirtualBox:~/course$ rm text.txt
alexey@alexey-VirtualBox:~/course$ cd
alexey@alexey-VirtualBox:~$ rmdir ~/course/
```
Попробовать сервисные команды who pwd, ps, mv:
```
alexey@alexey-VirtualBox:~$ who
alexey   tty2         2022-09-22 18:21 (tty2)
alexey   pts/1        2022-09-22 18:28 (10.0.2.2)
alexey@alexey-VirtualBox:~$ pwd
/home/alexey
alexey@alexey-VirtualBox:~$ ps
    PID TTY          TIME CMD
   2072 pts/1    00:00:00 bash
   2111 pts/1    00:00:00 ps
alexey@alexey-VirtualBox:~$ mv
mv: пропущен операнд, задающий файл
По команде «mv --help» можно получить дополнительную информацию.
```
Для команды mv нужен файл, создаём файл и переносим его в любой каталог:
```
alexey@alexey-VirtualBox:~$ touch f.txt
alexey@alexey-VirtualBox:~$ mv f.txt ~/Видео/
alexey@alexey-VirtualBox:~$ cd ~/Видео/
alexey@alexey-VirtualBox:~/Видео$ ls
f.txt
```
Запустить утилиту gnuplot и попробовть построить некоторые графики:
```
alexey@alexey-VirtualBox:~$ gnuplot

        G N U P L O T
        Version 5.4 patchlevel 2    last modified 2021-06-01

        Copyright (C) 1986-1993, 1998, 2004, 2007-2021
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'unknown'
gnuplot> set terminal dumb

Terminal type is now 'dumb'
Options are 'feed  size 79, 24 aspect 2, 1 mono'
gnuplot> plot sin(x)*cos(x)

  0.5 +--------------------------------------------------------------------+
      |   * *        * *        **       + **        * *  +      **        |
  0.4 |-+*  *        * *        **        * *        *i*(x)*cos(*)********-|
      |  *  *       *  *       *  *       * *        * *        * *       *|
  0.3 |-+*  *       *  *       *  *       *  *       * *       *   *     +*|
      |  *  *       *  *      *   *       *  *      *   *      *   *      *|
  0.2 |-+*   *      *  *      *    *      *  *      *   *      *   *     +*|
      |  *   *     *    *     *    *     *    *     *   *     *    *      *|
  0.1 |-*    *     *    *     *    *     *    *     *   *     *    *     +*|
      | *    *     *    *     *    *     *    *    *     *    *    *      *|
    0 |-*     *    *    *     *    *     *    *    *     *    *     *    *-|
      | *     *    *     *    *    *    *     *    *     *    *     *    * |
 -0.1 |*+     *    *     *    *    *    *     *    *     *    *     *    *-|
      |*      *    *     *   *      *   *     *    *      *   *     *   *  |
 -0.2 |*+     *   *      *   *      *   *     *    *      *   *      *  *+-|
      |*      *   *       *  *      *  *       *   *      *  *       *  *  |
 -0.3 |*+     *   *       * *       *  *       *  *       *  *       *  *+-|
      |*       * *        * *        * *       *  *       *  *       *  *  |
 -0.4 |*+      * *        * *        * *        * *       * *        *  *+-|
      |         **     +  * *        * * +      **        +**        *  *  |
 -0.5 +--------------------------------------------------------------------+
     -10              -5                 0                5                10
gnuplot> set parametric
gnuplot> set trange [0 to 2*pi]
gnuplot> set xrange [-1 to 1]
gnuplot> set yrange [-1 to 1]
gnuplot> plot sin(t),cos(t)

    1 +--------------------------------------------------------------------+
      |                ******            +          ******+                |
      |           *****                              sin(t******t) ******* |
      |        ***                                              ***        |
      |     ***                                                    ***     |
  0.5 |-+ **                                                          ** +-|
      | **                                                              ** |
      | *                                                                * |
      |*                                                                  *|
      |                                                                    |
    0 |-+                                                                +-|
      |                                                                    |
      |*                                                                  *|
      |**                                                                **|
      |  **                                                            **  |
 -0.5 |-+  *                                                          *  +-|
      |     **                                                      **     |
      |       *****                                             ****       |
      |            ****                                     ****           |
      |                ********          +          ********               |
   -1 +--------------------------------------------------------------------+
     -1              -0.5                0               0.5               1

```
**Вывод:**
Мы научились работать с директориями UNIX, создавать, изменять и перемещать файлы, использовать gnuplot
