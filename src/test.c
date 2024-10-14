#include <fcntl.h>
#include "lib.c"

void test_write(int fd) {
    int number = 2137;
    for (int i = 0; i < 10; i++) {
       write_last_line(fd, &number);
    }
}

int main() {
    int fd = open("test_file", O_RDWR|O_APPEND|O_CREAT, 0666);
    test_write(fd);
    close(fd);
}
