#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "computer.h"

int readComputer(computer *comp) {
    printf("Host's surname: ");
    scanf("%s", comp->surname);
    printf("Num of CPU: ");
    scanf("%u", &comp->cpu_num);
    printf("Type of CPU: ");
    scanf("%s", comp->cpu_type);
    printf("RAM: ");
    scanf("%f", &comp->memory);
    printf("Num of hdd: ");
    scanf("%u", &comp->hdd_num);
    printf("Type of largest hdd: ");
    scanf("%s", comp->hdd_type);
    printf("Size of largest hdd: ");
    scanf("%f", &comp->hdd_size);
    printf("OS: ");
    scanf("%s", comp->os);
        if (getchar()!='\n') goto err;
    printf("Computer successfully dumped!\n");
    return 0;
    err:
    errno = EINVAL;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: program filename\n");
        exit(EXIT_SUCCESS);
    }
    computer comp;
    FILE *out = fopen(argv[1], "ab");
    if (!out) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    if (readComputer(&comp)==0)
        fwrite(&comp, sizeof(comp), 1, out);
    else {
        perror("readComputer");
        exit(EXIT_FAILURE);
    }
    if (fclose(out) == EOF) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
    return 0;
}
