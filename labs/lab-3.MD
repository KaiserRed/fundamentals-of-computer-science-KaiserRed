# **Отчёт по лабораторной работе № 3** по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «1» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «1 <ins>октября<ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Сети и телекоммуникации в ос UNIX 

## 2. Цель работы
Изучение работы сетевых команд консоли ОС UNIX

## 3. Задание
Подключиться через ssh к другому пользователю, перенести файлы от одного пользователя к другому.

## 4. Оборудование
<b>Процессор:</b> 11th Gen Intel(R) Core (TM) i7-11370H 3.30GHz<br/>
<b>ОП: 16ГБ <br/>
<b>Монитор: 2880x1800 <br/>
## 5. Програмное обеспечение
<b>Опереционная система семейства: VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS<br/>
<b>Интерпретатор команд:</b> bash, версия 5.1.16<br/>
<b>Система программирования:</b> --, версия --<br/>
<b>Редактор текстов:</b> emacs, версия **28.2**<br/>
<b>Утилиты операционной системы:</b> cd, pwd, ls, cp, mc, mkdir, rmdir, cat, man, ps,rm<br/>
<b>Прикладные системы и программы:</b> gnuplot<br/>
<b>Местанохождение и имена файлов программ и данных на домашнем компьютере:</b> home/alexey<br/>
## 6. Идея, метод, алгоритм
| № | Утилита | Комментарий |
| -------- | -------- | ------ |
| 1 | **rlogin** [-p] <192.168.2.140>| Подключение к удалённой машине | 
| 2 | **telnet** [options] [host] [port] | Создание интерактивного соединения между удалёнными компьютерами|
| 3 | **hostname [-i]** | Вывод IP адреса |
| 4 | **rsync [–a] dir axp6** | Синхранизация каталогов на разных ЭВМ |
| 5 | **ssh** < host > @ < IP > | Подключение к удалённой машине через ssh |
| 6 | **ping 0**  | Узнать пинг локальной сети |
| 7 | **ping [IP]** | Убедиться в доступности сервера |
| 8 | **logout** | Прервать соединение с локальной машиной |
| 9 | **scp file1 axp5: ` pwd `** | Копирование файла с текущей машины на удалённую машину|
| 10 | **scp axp6: ` pwd ` /file2 file 3**  | Копирование файла с удалённой машины на текушую |
| 11 | **scp cameron: ` pwd `/file1 aplha:` pwd `/file3**| Копирование файла с одной удалённой машины на другую с переименованием; команда передаётся с третьей машины |
| 12 | **scp -r dir1 axp6** | Копирование директории вместе со всем её содержимым на удалённую машину
| 13 | **rsync -a dir axp6** | Синхронизация каталогов на разных ЭВМ |
| 14 | **tar [-xf] name.tar** | Разархивирует архив «name.tar» в текущую директорию |
| 15 | **tar [-cf] name.tar dir** | Создаёт архив «name.tar» и помещает в него все файлы и поддиректории указанной директории «dir»
| 16 | **get file1** | Получить файл «file1» с удалённой машины |
| 17 | **put file2** | Передать файл «file2» на удалённую машину |
| 18 | **gzip -9 -c** name.tar.tar > name.tar.tgz | Упаковка файла |
| 19 | **gzip -d -c** name.tar.tgz > name.tar.tar | Распаковка файла |
## 7. Сценария выполнения работы
1. Изучить справочный материал и дополнительную литературу.
2. Собственноручно проделать основные примеры и продемонстрировать владение сетевыми средствами.
3. Запротоколировать содержательное подмножество сеанса.
  
### 8. **Протокол**
```
stud@it-20:~$ ssh 192.168.2.140
The authenticity of host '192.168.2.140 (192.168.2.140)' can't be established.
ED25519 key fingerprint is SHA256:I6maFdaVFjUtE4EzhyP3nJUGC0bDgxdK1nexQWZWkWg.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.2.140' (ED25519) to the list of known hosts.
stud@192.168.2.140's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

149 updates can be applied immediately.
65 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 09:52:41 2022 from 127.0.0.1
stud@it-10:~$ ls
1         and      Documents  f5            filesh_zh  fl.gz    homestud  misha  Pictures  snap     Templates  Untitled.ipynb  zh_hz.gz
4444.txt  Desktop  Downloads  file2345.txt  file.txt   gnuplot  Kochev    Music  Public    spasibo  test1      Videos
stud@it-10:~$ exit
logout
Connection to 192.168.2.140 closed.
stud@it-20:~$ ls
106B_11  767  Desktop  Documents  Downloads  _file.txt  file.txt.save  hello.txt  lll.gz  Music  Pictures  Public  snap  Templates  Videos
stud@it-20:~$ scp hello.txt 192.168.2.140:`pwd`
stud@192.168.2.140's password: 
hello.txt    
stud@it-20:~$ scp 192.168.2.140:~/4444.txt .
stud@192.168.2.140's password: 
4444.txt                                                           100%    6     4.8KB/s   00:00    
stud@it-20:~$ ls
106B_11   767      Documents  _file.txt      hello.txt  Music     Public  Templates
4444.txt  Desktop  Downloads  file.txt.save  lll.gz     Pictures  snap    Videos
stud@it-20:~$ cat 4444.txt
hello
stud@it-20:~$ ssh 192.168.2.140
stud@192.168.2.140's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

149 updates can be applied immediately.
65 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:04:39 2022 from 192.168.2.224
stud@it-10:~$ ls
1         Documents     filesh_zh  gnuplot    Kochev    Public     test1
4444.txt  Downloads     _file.txt  hello      misha     snap       Untitled.ipynb
and       f5            file.txt   hello.txt  Music     spasibo    Videos
Desktop   file2345.txt  fl.gz      homestud   Pictures  Templates  zh_hz.gz
stud@it-10:~$ mkdir ~/test/
stud@it-10:~$ ls
1         Documents     filesh_zh  gnuplot    Kochev    Public     test            zh_hz.gz
4444.txt  Downloads     _file.txt  hello      misha     snap       test1
and       f5            file.txt   hello.txt  Music     spasibo    Untitled.ipynb
Desktop   file2345.txt  fl.gz      homestud   Pictures  Templates  Videos
stud@it-10:~$ cp 4444.txt ~/test/
stud@it-10:~/test$ exit
logout
Connection to 192.168.2.140 closed.
stud@it-20:~$ scp -r 192.168.2.140:~/test/ .
stud@192.168.2.140's password: 
4444.txt                                                                                                                                                                 100%    6    17.5KB/s   00:00
stud@it-20:~$ cd test
stud@it-20:~/test$ ls
4444.txt

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 2809.22 | 13:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
```
stud@it-20:~$ ssh 192.168.2.140
The authenticity of host '192.168.2.140 (192.168.2.140)' can't be established.
ED25519 key fingerprint is SHA256:I6maFdaVFjUtE4EzhyP3nJUGC0bDgxdK1nexQWZWkWg.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.2.140' (ED25519) to the list of known hosts.
stud@192.168.2.140's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

149 updates can be applied immediately.
65 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 09:52:41 2022 from 127.0.0.1
stud@it-10:~$ ls
1         and      Documents  f5            filesh_zh  fl.gz    homestud  misha  Pictures  snap     Templates  Untitled.ipynb  zh_hz.gz
4444.txt  Desktop  Downloads  file2345.txt  file.txt   gnuplot  Kochev    Music  Public    spasibo  test1      Videos
stud@it-10:~$ exit
logout
Connection to 192.168.2.140 closed.
stud@it-20:~$ scp hello.txt 192.168.2.140:`pwd`
stud@192.168.2.140's password: 
hello.txt    
stud@it-20:~$ scp 192.168.2.140:~/4444.txt .
stud@192.168.2.140's password: 
4444.txt                                                           100%    6     4.8KB/s   00:00    

stud@it-20:~$ echo да > f.txt
stud@it-20:~$ cat f.txt
да
stud@it-20:~$ file -i f.txt
f.txt: text/plain; charset=utf-8
stud@it-20:~$ xxd -b f.txt
00000000: 11010000 10110100 11010000 10110000 00001010           .....
stud@it-20:~$ iconv -c -f utf-8 -t utf-16 f.txt
��40

```

## 11. Выводы
Были изучены сетевые команды консоли ОС UNIX
