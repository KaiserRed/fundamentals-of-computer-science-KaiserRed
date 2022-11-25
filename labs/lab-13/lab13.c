#include <stdio.h>
#include <ctype.h>

#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)
char Repeat_of_vowels();
enum State{
    OUT,
    IN
};

unsigned int char_to_set(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c-'a');
     }
}
int main() {
    printf("%c\n", Repeat_of_vowels());
    return 0;
}    

char Repeat_of_vowels(){
    enum State state = OUT;
    int  c;
    unsigned int set = 0;
    while ((c = getchar()) != EOF){
        switch (state) {
        case OUT:
            set = 0;
            if (isspace((c) || (c == '\t') || (c == '\n'))
                break;
            state = IN;
        case IN:
            if (isalpha((c)){
                if (set & char_to_set(c)){
                    printf("Repeat of vowel %c\n",(char) c);
                    return 0;
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
    printf("There are not similar vowels");
    return 0;
}
