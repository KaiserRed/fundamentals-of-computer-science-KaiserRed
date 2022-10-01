# **Отчёт по лабораторной работе № 3** по курсу "Фундаментальная информатика"

**Студент группы**: М8О-108Б-22 № по списку 3 \
**Контакты**: alexgalkin2004@mail.ru \
**Работа выполнена**: "21" сентября 2022 г. \
**Преподаватель**: Сахарин Никита Александрович \
Отчёт сдан "24" сентября 2022 г. итоговая оценка - 5 

### 1. **Тема** 
Сети и телекоммуникации в ос UNIX 

### 2. **Цель работы** 
Изучение работы сетевых команд консоли ОС UNIX

### 3. **Задание**
Подключиться через ssh к другому пользователю, перенести файлы от одного пользователя к другому.

### 4. **Оборудование**
Процессор: 11th Gen Intel(R) Core (TM) i7-11370H 3.30GHz \
ОП: 16ГБ \
Монитор: 2880x1800
### 5. **Програмное обеспечение**
Опереционная система семейства: **Linux (Ubuntu)**, версия **22.04 LTS** \
Интерпретатор команд: *bash**, версия **5.1.16** \
Система программирования: **--**, версия **--** \
Редактор текстов: **emacs**, версия **28.2** \
Утилиты операционной системы: **--** \
Прикладные системы и программы: **--** \
Местанохождение и имена файлов программ и данных на домашнем компьютере: **--**
### 6. **Идея, метод, алгоритм**
1. Изучить справочный материал и дополнительную литературу.
2. Собственноручно проделать основные примеры и продемонстрировать владение сетевыми средствами.
3. Запротоколировать содержательное подмножество сеанса.

### 7. **Сценария выполнения работы**
| № | Утилита | Комментарий |
| -------- | -------- | ------ |
| 1 | **rlogin** [-p] <>| Подключение к удалённой машине | 
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

```
### 9. **Дневник откладки**
### 10. **Замечания автора** по существу работы
### 11. **Выводы**
Были изучены сетевые команды консоли ОС UNIX
