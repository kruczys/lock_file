#include <stdio.h>
#include <unistd.h>

void write_last_line(int* fd, int* number) {
    char buffer[20];
    int length = snprintf(buffer, sizeof(buffer), "%d\n",*number);
    write(*fd, buffer, length);
}

int read_last_line(int* fd) {
    return *fd;
}

int read_user_input() {
    int number;
    scanf("%d", &number);
    return number;
}

int take_file(char* path) {
    int fd;

    return fd;
}

void give_file() {
    ;;;;;;;;;;;;;;;
}
