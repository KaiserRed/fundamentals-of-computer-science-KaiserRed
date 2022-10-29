# **Отчёт по лабораторной работе № 1-2** по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «24» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «24» <ins>сентября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема 
Операционная среда UNIX 

## 2. Цель работы 
Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

## 3. Задание (вариант № —)
Изучение команд и утилит bash.

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
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Ввод команд:
1. ```ls -l/-A/-lAF``` – ознакомление с содержимым директории
2. ```whoami``` – определение имени пользователя
3. ```hostname``` – определение терминала, котором ведётся работа
4. ```date``` – определение даты
5. ```tty``` – определение номера группы имени пользователя
6. ```uname -a``` – определение сетевого имени машины
7. ```finger alexey``` – отображение полного имени и другой информации о пользователе
8. ```pwd``` – отображение полного пути к текущей директории
9. ```sudo ruptime``` – узнать, какие узлы сети в настоящий момент доступны, а какие нет
10. ```sudo rwho``` – узнать, какие пользователи работают на всех доступных UNIX-машинах
11. ```uptime``` – показывает текущее время, время работы после загрузки, количество  текущих пользователей и  нагрузку за последние 1, 5, 15 минут
12. ```man``` – получение оперативной документации по командам UNIX
13. ```cd``` – переход в другую директорию
14. ```ps``` - процессор
15. ```emacs``` – текстовый редактор
16. ```cp``` – копировать
17. ```cat``` – создание нового файла с возможностью записи/копировать
18. ```touch``` – создание пустого файла, если его нет. Если файл есть, то команда установит дату обращения в текущий момент времени 
19. ```rm``` – удаление
20. ```mv``` – перемещение
21. ```mkdir``` – создание директории
22. ```rmdir``` – удаление директории
23. ```gnuplot``` – утилита графики для построения двух- и трехмерных графиков
24. ```chmod +x ./myscript``` – делает скрипт исполняемым
25. ```./myscript``` – запуск скрипта
26. ```exit``` – выход
27. ```vim``` – текстовый редактор
    
## 7. Сценарий выполнения работы
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Приобрести основные навыки работы в OC UNIX
- Освоить навигацию в иерархической файловой системе OC UNIX
- Научиться манипулировать с файлами 
- Ознакомиться с утилитой графики 
- Научиться писать и запускать скрипты
- Запротоколировать сеанс

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________    
## 8. Распечатка протокола
```
alexey@alexey-VirtualBox:~$ dir
snap  Видео  Документы  Загрузки  Изображения  Музыка  Общедоступные  Рабочий\ стол  Шаблоны
alexey@alexey-VirtualBox:~$ who
alexey   tty2         2022-09-22 18:21 (tty2)
alexey   pts/1        2022-09-22 18:28 (10.0.2.2)
alexey@alexey-VirtualBox:~$ pwd
/home/alexey
alexey@alexey-VirtualBox:~$ ps
    PID TTY          TIME CMD
   2072 pts/1    00:00:00 bash
   2111 pts/1    00:00:00 ps
alexey@alexey-VirtualBox:~$ whoami
alexey
alexey@alexey-VirtualBox:~$ hostname
alexey-VirtualBox
alexey@alexey-VirtualBox:~$ date
Ср 22 сен 2022 18:28
alexey@alexey-VirtualBox:~$ touch text.txt
alexey@alexey-VirtualBox:~$ echo 1234567890 > text.txt
alexey@alexey-VirtualBox:~$ cat text.txt
1234567890
alexey@alexey-VirtualBox:~$ cp text.txt text2.txt
alexey@alexey-VirtualBox:~$ cat text.txt text2.txt > text3.txt
alexey@alexey-VirtualBox:~$ cat text3.txt
1234567890
1234567890
alexey@alexey-VirtualBox:~$ rm text2.txt text3.txt
alexey@alexey-VirtualBox:~$ mkdir lab course
alexey@alexey-VirtualBox:~$ cp text.txt ~/lab/
alexey@alexey-VirtualBox:~$ cp text.txt ~/course/
alexey@alexey-VirtualBox:~$ rm text.txt
alexey@alexey-VirtualBox:~$ cd lab
alexey@alexey-VirtualBox:~/lab$ ls
text.txt
alexey@alexey-VirtualBox:~/lab$ rm text.txt
alexey@alexey-VirtualBox:~$ rmdir ~/lab/ ~/course/
rmdir: не удалось удалить '/home/alexey/course/': Каталог не пуст
alexey@alexey-VirtualBox:~$ cd course
alexey@alexey-VirtualBox:~/course$ rm text.txt
alexey@alexey-VirtualBox:~/course$ cd
alexey@alexey-VirtualBox:~$ rmdir ~/course/
alexey@alexey-VirtualBox:~$ touch f.txt
alexey@alexey-VirtualBox:~$ mv f.txt ~/Видео/
alexey@alexey-VirtualBox:~$ cd ~/Видео/
alexey@alexey-VirtualBox:~/Видео$ ls
f.txt
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
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 24.09.22 | 13:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы были продемонстрированы команды:
```
alexey@alexey-VirtualBox:~$ touch text.txt
alexey@alexey-VirtualBox:~$ echo 1234567890 > text.txt
alexey@alexey-VirtualBox:~$ cat text.txt
1234567890
alexey@alexey-VirtualBox:~$ emacs
alexey@alexey-VirtualBox:~$ pgrep -l emacs
3359 emacs
alexey@alexey-VirtualBox:~$ pkill emacs
alexey@alexey-VirtualBox:~$ ps -e
    PID TTY          TIME CMD
      1 ?        00:00:00 systemd
      2 ?        00:00:00 kthreadd
      3 ?        00:00:00 rcu_gp
      4 ?        00:00:00 rcu_par_gp
      5 ?        00:00:00 netns
      7 ?        00:00:00 kworker/0:0H-events_highpri
      8 ?        00:00:00 kworker/u4:0-ext4-rsv-conversion
      9 ?        00:00:00 kworker/0:1H-events_highpri
     10 ?        00:00:00 mm_percpu_wq
     11 ?        00:00:00 rcu_tasks_rude_
     12 ?        00:00:00 rcu_tasks_trace
     13 ?        00:00:00 ksoftirqd/0
     14 ?        00:00:00 rcu_sched
     15 ?        00:00:00 migration/0
     16 ?        00:00:00 idle_inject/0
     18 ?        00:00:00 cpuhp/0
     19 ?        00:00:00 cpuhp/1
     20 ?        00:00:00 idle_inject/1
     21 ?        00:00:00 migration/1
     22 ?        00:00:00 ksoftirqd/1
     24 ?        00:00:00 kworker/1:0H-events_highpri
     25 ?        00:00:00 kdevtmpfs
     26 ?        00:00:00 inet_frag_wq
     27 ?        00:00:00 kauditd
     28 ?        00:00:00 khungtaskd
     29 ?        00:00:00 oom_reaper
     30 ?        00:00:00 writeback
     31 ?        00:00:00 kcompactd0
     32 ?        00:00:00 ksmd
     33 ?        00:00:00 khugepaged
     38 ?        00:00:00 kworker/1:1-events
     80 ?        00:00:00 kintegrityd
     81 ?        00:00:00 kblockd
     82 ?        00:00:00 blkcg_punt_bio
     83 ?        00:00:00 tpm_dev_wq
     84 ?        00:00:00 ata_sff
     85 ?        00:00:00 md
     86 ?        00:00:00 edac-poller
     87 ?        00:00:00 devfreq_wq
     88 ?        00:00:00 watchdogd
     91 ?        00:00:00 kswapd0
     92 ?        00:00:00 ecryptfs-kthrea
     94 ?        00:00:00 kthrotld
     95 ?        00:00:00 acpi_thermal_pm
     96 ?        00:00:00 kworker/u4:2-events_unbound
     97 ?        00:00:00 scsi_eh_0
     98 ?        00:00:00 scsi_tmf_0
     99 ?        00:00:00 scsi_eh_1
    100 ?        00:00:00 scsi_tmf_1
    101 ?        00:00:00 kworker/u4:3-ext4-rsv-conversion
    102 ?        00:00:00 vfio-irqfd-clea
    104 ?        00:00:00 kworker/1:1H-events_highpri
    105 ?        00:00:00 mld
    106 ?        00:00:00 ipv6_addrconf
    109 ?        00:00:00 kworker/1:2-events
    117 ?        00:00:00 kstrp
    120 ?        00:00:00 zswap-shrink
    121 ?        00:00:00 kworker/u5:0
    126 ?        00:00:00 charger_manager
    171 ?        00:00:00 kworker/1:3-cgroup_destroy
    172 ?        00:00:00 scsi_eh_2
    174 ?        00:00:00 kworker/0:2-events
    175 ?        00:00:00 scsi_tmf_2
    200 ?        00:00:00 jbd2/sda3-8
    201 ?        00:00:00 ext4-rsv-conver
    241 ?        00:00:00 systemd-journal
    265 ?        00:00:00 kworker/0:3-cgroup_destroy
    273 ?        00:00:00 ipmi-msghandler
    283 ?        00:00:00 systemd-udevd
    285 ?        00:00:00 ttm_swap
    286 ?        00:00:00 irq/18-vmwgfx
    287 ?        00:00:00 card0-crtc0
    288 ?        00:00:00 card0-crtc1
    289 ?        00:00:00 card0-crtc2
    290 ?        00:00:00 card0-crtc3
    291 ?        00:00:00 card0-crtc4
    292 ?        00:00:00 card0-crtc5
    293 ?        00:00:00 card0-crtc6
    294 ?        00:00:00 card0-crtc7
    331 ?        00:00:00 cryptd
    334 ?        00:00:00 kworker/u4:6-ext4-rsv-conversion
    338 ?        00:00:00 kworker/u4:8-events_unbound
    487 ?        00:00:00 systemd-oomd
    489 ?        00:00:00 systemd-resolve
    490 ?        00:00:00 systemd-timesyn
    627 ?        00:00:00 accounts-daemon
    628 ?        00:00:00 acpid
    629 ?        00:00:00 anacron
    631 ?        00:00:00 avahi-daemon
    632 ?        00:00:00 cron
    633 ?        00:00:00 dbus-daemon
    634 ?        00:00:00 NetworkManager
    640 ?        00:00:00 irqbalance
    648 ?        00:00:00 networkd-dispat
    652 ?        00:00:00 polkitd
    656 ?        00:00:00 power-profiles-
    659 ?        00:00:00 rsyslogd
    661 ?        00:00:00 switcheroo-cont
    665 ?        00:00:00 systemd-logind
    670 ?        00:00:00 udisksd
    672 ?        00:00:00 wpa_supplicant
    683 ?        00:00:00 avahi-daemon
    711 ?        00:00:00 ModemManager
    714 ?        00:00:00 cupsd
    750 ?        00:00:00 unattended-upgr
    755 ?        00:00:00 gdm3
    771 ?        00:00:00 dbus
    772 ?        00:00:00 dbus
    773 ?        00:00:00 dbus
    774 ?        00:00:00 dbus
    775 ?        00:00:00 gdm-session-wor
    798 ?        00:00:00 systemd
    799 ?        00:00:00 (sd-pam)
    818 ?        00:00:00 pipewire
    819 ?        00:00:00 pipewire-media-
    821 ?        00:00:00 pulseaudio
    824 ?        00:00:00 gnome-keyring-d
    829 ?        00:00:00 rtkit-daemon
    837 tty2     00:00:00 gdm-wayland-ses
    839 ?        00:00:00 dbus-daemon
    851 ?        00:00:00 gvfsd
    852 ?        00:00:00 xdg-document-po
    854 tty2     00:00:00 gnome-session-b
    868 ?        00:00:00 xdg-permission-
    876 ?        00:00:00 fusermount3
    884 ?        00:00:00 gvfsd-fuse
    933 ?        00:00:00 gnome-session-c
    948 ?        00:00:00 gnome-session-b
    964 ?        00:01:18 gnome-shell
    966 ?        00:00:00 at-spi-bus-laun
    975 ?        00:00:00 dbus-daemon
   1029 ?        00:00:00 snapd-desktop-i
   1092 ?        00:00:00 xdg-desktop-por
   1096 ?        00:00:00 xdg-desktop-por
   1103 ?        00:00:00 gnome-shell-cal
   1109 ?        00:00:00 evolution-sourc
   1110 ?        00:00:00 upowerd
   1123 ?        00:00:00 goa-daemon
   1124 ?        00:00:00 gvfs-udisks2-vo
   1134 ?        00:00:00 gvfs-goa-volume
   1135 ?        00:00:00 evolution-calen
   1146 ?        00:00:00 goa-identity-se
   1148 ?        00:00:00 gvfs-gphoto2-vo
   1155 ?        00:00:00 gvfs-afc-volume
   1161 ?        00:00:00 gvfs-mtp-volume
   1170 ?        00:00:00 dconf-service
   1175 ?        00:00:00 evolution-addre
   1180 ?        00:00:02 packagekitd
   1194 ?        00:00:00 gvfsd-trash
   1206 ?        00:00:00 at-spi2-registr
   1207 ?        00:00:00 gjs
   1215 ?        00:00:00 sh
   1216 ?        00:00:00 gsd-a11y-settin
   1219 ?        00:00:00 gsd-color
   1222 ?        00:00:00 gsd-datetime
   1224 ?        00:00:00 gsd-housekeepin
   1225 ?        00:00:00 gsd-keyboard
   1230 ?        00:00:00 ibus-daemon
   1240 ?        00:00:00 gsd-media-keys
   1242 ?        00:00:00 gsd-power
   1245 ?        00:00:00 gsd-print-notif
   1247 ?        00:00:00 gsd-rfkill
   1254 ?        00:00:00 gsd-screensaver
   1255 ?        00:00:00 gsd-sharing
   1260 ?        00:00:00 gsd-smartcard
   1263 ?        00:00:00 gsd-sound
   1265 ?        00:00:00 gsd-wacom
   1281 ?        00:00:00 cups-browsed
   1288 ?        00:00:00 kerneloops
   1293 ?        00:00:00 kerneloops
   1368 ?        00:00:00 ibus-dconf
   1369 ?        00:00:00 ibus-extension-
   1373 ?        00:00:00 ibus-portal
   1375 ?        00:00:00 evolution-alarm
   1398 ?        00:00:00 gsd-disk-utilit
   1411 ?        00:00:01 snap-store
   1453 ?        00:00:00 ibus-engine-sim
   1459 ?        00:00:00 gsd-printer
   1540 ?        00:00:00 colord
   1542 ?        00:00:00 xdg-desktop-por
   1549 ?        00:00:00 tracker-miner-f
   1582 ?        00:00:00 gjs
   1594 ?        00:00:00 gjs
   1629 ?        00:00:00 gvfsd-metadata
   1635 ?        00:00:00 fwupd
   1946 ?        00:00:01 gnome-terminal-
   1972 pts/0    00:00:00 bash
   2006 ?        00:00:00 update-notifier
   2044 ?        00:01:06 firefox
   2195 ?        00:00:07 Xwayland
   2199 ?        00:00:00 gsd-xsettings
   2224 ?        00:00:00 ibus-x11
   2290 ?        00:00:00 Socket Process
   2327 ?        00:00:00 WebExtensions
   2345 ?        00:00:00 Privileged Cont
   2373 ?        00:00:00 snap
   2491 ?        00:00:00 Isolated Web Co
   3135 ?        00:00:13 Isolated Web Co
   3146 ?        00:00:00 Web Content
   3179 ?        00:00:00 Web Content
   3199 ?        00:00:00 RDD Process
   3216 ?        00:00:00 Web Content
   3303 ?        00:00:00 Utility Process
   3501 pts/2    00:00:00 bash
   3602 ?        00:00:06 snapd
   3901 ?        00:00:00 kworker/0:0-events
   4026 pts/2    00:00:00 ps
alexey@alexey-VirtualBox:~$ ps -e | wc
    210     851    8121

```
## 11. Выводы
Было выяснено, что в OC UNIX есть множество полезных утилит, которые облегчают работу в этой системе. Были изучены некоторые из них. Освоены навигация в файловой системе, создание, удаление файлов и директорий. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
