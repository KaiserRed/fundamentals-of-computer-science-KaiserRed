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
