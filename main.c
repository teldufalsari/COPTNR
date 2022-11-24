#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>

void parallel_qsort(int* base, size_t nmemb);

int is_integer(const char* str_repr)
{
    size_t len = strlen(str_repr);
    for (size_t i = 0; i < len; i++) {
        if (!isdigit(str_repr[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage:\n\
            %s -s [N]\n\
            %s -f [file]\n",
            argv[0], argv[0]);
        return 1;
    }

    int* array;
    size_t batch_size = 0;
    if (0 == strcmp("-s", argv[1])) {
        // read from stdin
        if (!is_integer(argv[2])) { // FAIL
            printf("\"%s\" is not a valid integer. Arrey size must be an integer\n", argv[2]);
            return 2;
        }
        batch_size = strtoul(argv[2], NULL, 10);
        if (batch_size == 0) {
            return 0;
        }
        array = calloc(batch_size, sizeof(int));
        if (NULL == array) {
            perror("Your system must be SOOOO fucked up rn");
            return 1;
        }
        for (size_t i = 0; i < batch_size; i++) {
            scanf(" %d", array + i);
        }
    } else if (0 == strcmp("-f", argv[1])) {
        // read from a file
        FILE* input_stream = fopen(argv[2], "r");
        if (NULL == input_stream) {
            // fopen failed
            if (errno == ENOENT || errno == ENOTDIR)
                printf("Error: file \"%s\" does not exist\n", argv[2]);
            else
                perror("OS error");
            return 1;
        }
        // fopen was successfull, now read
        array = calloc(10000, sizeof(int));
        if (NULL == array) {
            perror("Your system must be SOOOO fucked up rn");
            fclose(input_stream);
            return 1;
        }
        int buf = 0; // check scanf result
        while (EOF != fscanf(input_stream, " %d", &buf)) {
            array[batch_size++] = buf;
        }
        fclose(input_stream);
    } else { // FAIL
        printf("Unrecognized option \"%s\"\n", argv[1]);
        return 1;
    }
    // assume array and batch_size are initialized and we can sort them
    printf("Unsorted:\n[");
    for (size_t i = 0; i < batch_size; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");

    parallel_qsort(array, batch_size);
    printf("Sorted:\n[");
    for (size_t i = 0; i < batch_size; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n\n");
    free(array);
    puts("╔══  ╔══╗ ╔══╗ ══╦══ ║   ║ ╔══╗");
    puts("║    ║  ║ ║  ║   ║   ║  ╔╣ ║  ║");
    puts("║    ║  ║ ╠══╝   ║   ║ ╔╝║ ╠══╝");
    puts("║    ║  ║ ║      ║   ║╔╝ ║ ║");
    puts("╚══  ╚══╝ ║      ║   ╚╝  ║ ║");
    puts("\nПРОВЕРЕНО. СОРТИРУЕТ");
    return 0;
}
