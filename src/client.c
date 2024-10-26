#include <fcntl.h>
#include "lib.c"


int main() {
    int input = read_user_input();
    int fd_data = open("./dane", O_CREAT|O_TRUNC|O_RDWR, 0666);
    int fd_results;

    write_last_line(fd_data, input);
    close(fd_data);
    sleep(1);
    while ((fd_results = open("./wyniki", O_RDONLY|O_TRUNC, 0666) == -1)) {
        sleep(1);
    }

    printf("%d", read_last_line(fd_results));
    close(fd_results);
    exit(0);
}
