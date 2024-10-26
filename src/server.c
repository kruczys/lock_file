#include <fcntl.h>
#include "lib.c"

int do_calculations(int x) {
    return 3*x*x*x + 11*x*x - 3*x + 103;
}

int main() {
    int fd_data;
    int result;
    int fd_results;

    while (1) {
        sleep(1);
        printf("Otweram plik dane");
        while ((fd_data = open("./dane", O_RDONLY) == -1)) {
            sleep(1);
        }
        result = do_calculations(read_last_line(fd_data));
        close(fd_data);
        printf("Zamknalem plik");
        fd_results = open("./wyniki", O_RDWR | O_TRUNC | O_CREAT, 0666);
        write_last_line(fd_results, result);
        close(fd_results);
    }
}
