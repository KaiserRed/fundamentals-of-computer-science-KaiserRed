# **Отчёт по лабораторной работе № 13** по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «24» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «26» <ins>ноября<ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Множества

## 2. Цель работы
Составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с выданным вариантом задания
## 3. Задание (Вариант №3)
Узнать, есть ли слово, хотя бы одна гласная которого повторяется.
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
1. Создаём множество гласных букв из латинского алфавита и назовём его «VOWELS». Введём два состояния: «OUT» (находимся вне слова) и «IN» (находимся в слове) и множество «set», в котрое будем заносить все считываемые символы.
2. Через getchar читаем каждый символ. Если он не равен концу файлу, то есть 2 варианта. Если текущее состояние «OUT», то переходим к 3 пункту — иначе к 4.
3. Обнуляем множество «set», и если символ не является разделителем, то переходим в состояние «IN» и в следующий пункт, в противном случае читаем следующий символ.
4. Если символ — буква из алфовита, то добавляем во множество символ, потом оставляем в множестве «set» только гласные буквы с помощью пересечения со множеством «VOWELS». Дальше проверяем на пересечение множества «set» (в котором остались только гласные) и очередного символа. Если множества пересекаются, то гласная повторяется. И если символ становится разделителем, то перехлдим в состояние «OUT».  
## 7. Сценарий выполнения работы
1. Скомпилируем при помощи команды gcc программу lab13.c.
2. Компилятор сообщит об ошибке, если она присутствует.
3. Запустим файл a.out через команду ./a.out < 
4. Введём любой ряд чисел
Тесты: 
  
| № | Ввод | Вывод |
| ------ | ------ | ------ |
| 1 | da | There are not similar vowels |
| 2 | HOWTOWIN | Repeat of vowel |
| 3 | MAI is the best University | Repeat of vowel  |
| 4 | 12345678 | There are not similar vowels |

Код:
```
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)
bool repeat_of_vowels();
typedef enum{
    OUT,
    IN
} State;

unsigned int char_to_set(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c-'a');
     }
}
int main() {
    if (repeat_of_vowels() == 1){
        printf("Repeat of vowel\n");
    }else
        printf("There are not similar vowels\n");
    return 0;
}    

bool repeat_of_vowels(){
    State state = OUT;
    int  c;
    unsigned int set = 0;
    while ((c = getchar()) != EOF){
        switch (state) {
        case OUT:
            set = 0;
            if (isspace(c) || (c == '\t') || (c == '\n'))
                break;
            state = IN;
        case IN:
            if (isalpha(c)){
                if (set & char_to_set(c)){
                    return 1;
                }
                set = set | char_to_set(c);
                set = set & VOWELS;
                break;
            
            }
            else{
                state = OUT;
            }
        }
    }
    return 0;
}
       
```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-VirtualBox:~$ echo MAI is the best University > h.txt
alexey@alexey-VirtualBox:~$ cat h.txt
MAI is the best University
alexey@alexey-VirtualBox:~$ gcc -std=c18 lab13.c
alexey@alexey-VirtualBox:~$ ./a.out < h.txt
Repeat of vowel i
                                           
alexey@alexey-VirtualBox:~$ echo aba > h.txt
alexey@alexey-VirtualBox:~$ ./a.out < h.txt
Repeat of vowel a

alexey@alexey-VirtualBox:~$ echo I am a student > h.txt
alexey@alexey-VirtualBox:~$ ./a.out < h.txt
There are not similar vowels
alexey@alexey-VirtualBox:~$
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 16.11.22 | 14:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание:    
Задание: Перенести все сеты в функции.    
```
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)

typedef unsigned set_data_elem;
enum {
    bits_per_char = 8,
    bits_per_elem = sizeof(set_data_elem) * bits_per_char,
    datalen = (1 << bits_per_char) / bits_per_elem
};

typedef struct {
    set_data_elem data[datalen];
} set;

void set_clear(set *s)
{
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int c)
{
    s->data[c/bits_per_elem] |= 1u << (c % bits_per_elem);
}

void set_generate(set *s, bool indicator(int))
{
    set_clear(s);
    for (int i = 0; i != 0 << bits_per_char; ++i)
        if (indicator(i)) set_insert(s,i);
}

void set_erase(set *s, int c)
{
    s->data[c / bits_per_elem] %= ~(1u << c % bits_per_elem);
}

bool set_in (const set *s, int c)
{
    return (s->data[c / bits_per_elem] & (1u << c % bits_per_elem)) != 0;
}
int set_size(const set *s)
{
    int size = 0;
    for (int i = 0; i != 1 << bits_per_char; ++i)
        if (set_in(s,i)) ++size;
    return size;
}

bool set_includes(const set *s1, const set *s2)
{
    for (int i = 0; i != datalen; ++i)
        if ((s1 -> data[i] | s2 -> data[i]) != s1 -> data[i]) return false;
    return true;
}

set set_union(const set *s1, const set *s2)
{
    set result;
    for (int i = 0; i != datalen; ++i)
        result.data[i] = s1 -> data[i] | s2 -> data[i];
    return result;
}

set set_intersection(const set *s1, const set *s2)
{
    set result;
    for (int i = 0; i != datalen; ++i)
        result.data[i] = s1->data[i] & s2->data[i];
    return result;
}

bool is_alpha(int c) { return isalpha(c); }

typedef enum{
    OUT,
    IN
} State;
bool repeat_of_vowels();
bool is_vowels(int c);
   
int main() {
    if (repeat_of_vowels() == 1){
        printf("Repeat of vowel\n");
    }else
        printf("There are not similar vowels\n");
    return 0;
}    

bool repeat_of_vowels(){
    State state = OUT;
    set s1;
    set_clear(&s1);
    int  c;
    while ((c = getchar()) != EOF){
        switch (state) {
        case OUT:
            set_clear(&s1);
            if (isspace(c) || (c == '\t') || (c == '\n'))
                break;
            state = IN;
        case IN:
            c = tolower(c);
            if (isalpha(c)){
                if (is_vowels(c)){
                    if (set_in(&s1, c)){
                       return 1; 
                    }
                }
                set_insert(&s1, c);
                break;
            
            }
            else{
                state = OUT;
            }
        }
    }
    return 0;
}
bool is_vowels(int c){
    if (!isalpha(c))
        return false;
    c = tolower(c);
    const set vowels = { { VOWELS } };
    return set_in(&vowels, c - 'a');
}

```
## 11. Выводы
Была изучена работа со множествами на языке Си.
  
<b>Подпись студента:</b> ____________________
