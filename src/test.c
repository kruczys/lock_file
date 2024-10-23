#include "lib.c"

int main() {
    int fd = open_data_file();
    int fd_w = open_result_file();
    int number = read_user_input();
    write_last_line(&fd, &number);
    write_last_line(&fd_w, &number);
    printf("%d\n", read_last_line(&fd));
    printf("%d\n", read_last_line(&fd_w));
}
