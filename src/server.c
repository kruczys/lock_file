#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int do_calculations(int x) {
    return 3*x*x*x + 11*x*x - 3*x + 103;
}

int main() {
    int fd_data, fd_results;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int number;

    fd_results = open("./wyniki", O_WRONLY | O_CREAT, 0666);
    close(fd_results);

    printf("Serwer ruszył... czeka na klienta...");

    while (1) {
        while ((fd_data = open("./dane", O_RDONLY) == -1)) {
            sleep(1);
        }

        bytes_read = read(fd_data, buffer, BUFFER_SIZE);
        close(fd_data);

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            number = atoi(buffer);
            number = do_calculations(number);
            snprintf(buffer, BUFFER_SIZE, "%d", number);

            fd_results = open("./wyniki", O_WRONLY|O_TRUNC);
            write(fd_results, buffer, strlen(buffer));
            close(fd_results);
        }
    }

    return 0;
}
