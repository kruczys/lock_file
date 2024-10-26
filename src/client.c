#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 256


int main() {
    int fd_data, fd_results;
    char input_buffer[BUFFER_SIZE];
    char result_buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    printf("Podaj numer: ");
    fgets(input_buffer, BUFFER_SIZE, stdin);

    fd_data = open("./dane", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    write(fd_data, input_buffer, strlen(input_buffer));
    close(fd_data);

    sleep(5);

    fd_results = open("./wyniki", O_RDONLY);
    bytes_read = read(fd_results, result_buffer, BUFFER_SIZE);
    close(fd_results);

    if (bytes_read > 0) {
        result_buffer[bytes_read] = '\0';
        printf("Wynik z serwera %s", result_buffer);
    }

    return 0;
}
