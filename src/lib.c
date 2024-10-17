#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void write_last_line(int* fd, int* number) {
    char buffer[20];
    int length = snprintf(buffer, sizeof(buffer), "%d\n",*number);
    write(*fd, buffer, length);
}

int read_last_line(int* fd) {
    char buffer[20];
    int number;
    
    lseek(*fd, sizeof(number), SEEK_END);
    read(*fd, buffer, sizeof(number));
    number = atoi(buffer);

    return number;
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
