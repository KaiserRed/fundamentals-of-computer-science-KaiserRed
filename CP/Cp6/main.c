#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "computer.h"

typedef struct {
    FILE *in, *out;
} Data;

bool get(computer * const comp, const void * const data);
void put(const computer *comp, const void * const data);

bool get(computer * const comp, const void * const data){
    FILE * const in = ((Data *) data)->in;
    const size_t count = fread(comp, sizeof(computer), 1U, in);
    if (count != 1U && ferror(in) != 0){
        perror("fread");
        exit(EXIT_FAILURE);
    } else if (count != 1U)
        return false;
    return true;
}

void put(const computer *comp, const void * const data){
    FILE * const out = ((Data *) data)->out;
    fprintf(out,"Surname: %s\n", comp->surname);
    fprintf(out,"Num of CPU: %u\n", comp->cpu_num);
    fprintf(out,"Type of CPU: %s\n", comp->cpu_type);
    fprintf(out,"RAM: %f\n", comp->memory);
    fprintf(out,"Num of hdd: %u\n", comp->hdd_num);
    fprintf(out,"Type of largest hdd: %s\n", comp->hdd_type);
    fprintf(out,"Size of largest hdd (TB): %f\n", comp->hdd_size);
    fprintf(out,"OS: %s\n", comp->os);
    fprintf(out, "----------------\n");
}
int main(const int argc, char ** const argv) {
    if (argc != 5) {
        fprintf(stderr, "%s: wrong count of arguments\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (strcmp(argv[1], "--help") == 0) {
        printf("Usage:\n  %s -f FILE -p PARAMETER\n", argv[0]);
        exit(EXIT_SUCCESS);
    };

    const char *file = NULL;
    bool hasParam = false;
    long long parameter = 0;
    for (int opt; opt = getopt(argc, argv, "f:p:"), opt != -1; ) {
        switch (opt) {
            case ':':
                fprintf(stderr, "%s: unknown option -- %c\n", argv[0], optopt);
                break;
            case '?':
                printf("help");
                break;
            case 'f':
                file = optarg;
                break;
            case 'p': ; 
                char *end;
                parameter = strtoll(optarg, &end, 10);
                hasParam = true;
                break;
            default:
                assert(false);
        }
    }

    FILE *in = fopen(file, "rb");
    if (in == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    Data data = { .in = in, .out = stdout };
    if (hasParam)
        select(parameter, get, put, &data);

    if (fclose(in) == EOF) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return 0;
}