# **Отчёт по лабораторной работе № 21** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «24» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «25» <ins>марта<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Программирование на интерпретируемых командных языках
## 2. Цель работы
Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков ОС
## 3. Задание (Вариант №3)
Удаление всех файлов с указанным суффиксом, к которым не было обращений указанное число дней 

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
На Bash.
Печатаем суффикс, а потом количество дней. С помощью команды find и флажков -name ```"*$a" -mmin -"$b" -delete``` удаляем все файлы с заданным суффиксом и которым не обращались заданное количество дней.

## 7. Сценарий выполнения работы
Bash: 
1. Изучаем команду find с его флажками.       
2. Создаём bash скрипт.      
3. Делаем проверки входных данных.    
4. Делаем рабочий скрипт.   
Python    
1. Изучаем библиотеки os, time, pathlib
2. Задаём суффикс файла и время его изменения.   
3. Проходим по директории. Когда замечаем файл с заданным суффиксом и заданным временем изменения выписываем его, чтобы узнать, что удаляется, и удаляем его.   
4. Если таких файлов нет, то пишем об этом.    
    
Bash
```
#!/bin/bash

c=$1
if [[ $c == ? ]];
    then echo "To delete all files you should type suffixes of the files. Then type day when file was modified in order to delete this file." >&2; exit 1
fi
read -p "Type suffix = " a
if ! [[ $a =~ ^[a-z]+$ ]];
   then echo "error: Not a suffix" >&2; exit 1
fi

read -p "Type time =" b
if  ! [[  $b =~ ^[0-9]+$ ]];
    then echo "error: Not a number" >&2; exit 1
fi
find . -type f -name "*$a" -mtime +"$b" -delete
# -mmin +n - minutes
# -mtime +n - days
```
    
Pyhon
```
import os
import time
import pathlib

print("Declare suffix of the file")
suffix = input()
if (suffix == '?'):
    print("This code allows you to delete all files with specified suffix and modification date. To do this type suffix and then type the last date of modification. If files are existing they will be deleted, else they aren't")
    print("Declare suffix of the file")
    suffix = input()
    
suffix = '.' + suffix 
print ('Declare how old files are allowed to be and set the root directory')
days = int(input())
days_ago = time.time() - (days * 86400)
root = "/home/alexey/"
count = 0
for i in os.listdir(root):
    path = os.path.join(root, i)
    if ((os.stat(path).st_mtime <= days_ago) and (pathlib.PurePath(path).suffix == suffix)):
        if os.path.isfile(path):
            print(pathlib.PurePath(path).name)
            os.remove(path)
            count+=1
if (count == 0):
    print('Could not remove file')
                                           
```

Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-VirtualBox:~$ ls
 1.c      code1.c   horner.c    snap      x4.txt      Изображения     Шаблоны
'1 sem'   code.c    out.txt     test2.c   Видео       Музыка
 1.txt    he.c      p.py        test.c    Документы   Общедоступные
 a.out    hello.c   script.sh   x4        Загрузки   'Рабочий стол'

alexey@alexey-VirtualBox:~$ python3 p.py
Declare suffix of the file
txt
Declare how old files are allowed to be and set the root directory
3
x4.txt
out.txt

alexey@alexey-VirtualBox:~$ ls
 1.c      code1.c   horner.c    test2.c   Документы     Общедоступные
'1 sem'   code.c    p.py        test.c    Загрузки     'Рабочий стол'
 1.txt    he.c      script.sh   x4        Изображения   Шаблоны
 a.out    hello.c   snap        Видео     Музыка

```
```
alexey@alexey-VirtualBox:~$ ls
 1.c      code1.c   horner.c    snap      x4.txt      Изображения     Шаблоны
'1 sem'   code.c    out.txt     test2.c   Видео       Музыка
 1.txt    he.c      p.py        test.c    Документы   Общедоступные
 a.out    hello.c   script.sh   x4        Загрузки   'Рабочий стол'

alexey@alexey-VirtualBox:~$ bash script.sh
Type suffix = txt
Type time = 3
alexey@alexey-VirtualBox:~$ 

alexey@alexey-VirtualBox:~$ ls
 1.c      code1.c   horner.c    test2.c   Документы     Общедоступные
'1 sem'   code.c    p.py        test.c    Загрузки     'Рабочий стол'
 1.txt    he.c      script.sh   x4        Изображения   Шаблоны
 a.out    hello.c   snap        Видео     Музыка

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 08.12.22 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:
Защита с Codeforces (div 2)
https://codeforces.com/contest/1809/submission/198778410
Дорешка
https://codeforces.com/contest/1809/submission/199044848

## 11. Выводы
Были изучены способы работы и изменений файлов через интерпретируемый командный язык Bash и через Python. Были изучены проверки суффиксов у файлов и дата их последнего изменения  

<b>Подпись студента:</b> ____________________
