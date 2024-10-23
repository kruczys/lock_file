#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

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

int open_data_file() {
    int fd = open("./dane", O_RDWR|O_APPEND|O_CREAT, 0666);
    return fd;
}

int open_result_file() {
    int fd = open("./wyniki", O_RDWR|O_APPEND|O_CREAT, 0666);
    return fd;
}

int get_file_size(int* fd) {
    struct stat buffer;
    fstat(*fd, &buffer);
    return buffer.st_size;
}

int file_changed(int* fd, int* size_before) {
    struct stat buffer;

    while (buffer.st_size <= *size_before) {
        fstat(*fd, &buffer);
        sleep(1);
    }

    return 1;
}
