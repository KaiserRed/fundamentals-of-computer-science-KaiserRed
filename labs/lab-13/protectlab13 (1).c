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
