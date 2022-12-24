#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t time_now;
    time(&time_now);
    struct tm *local = localtime(&time_now);
    char path[10000];
    scanf("%s", path);
    FILE *file;
    file = fopen(path, "w");
    if (file == NULL) {
        printf("File is null");
        exit(1);
    }
    for (int i = 0; i < 10; ++i) {
        char s[20] = {0};
        strftime(s, 80, "%d.%m.%Y", local);
        fprintf(file, "%s\n", s);
        time_now += 86400;
        local = localtime(&time_now);
    }
    fclose(file);
    getch();
    return 0;
}