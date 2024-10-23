#include <fcntl.h>
#include <unistd.h>
#include "lib.c"


int main() {
    int input = read_user_input();
    int fd_data = open_data_file();
    int fd_results = open_result_file();
    int results_size_before = get_file_size(&fd_results);
    write_last_line(&fd_data, &input);
    
    if (file_changed(&fd_results, &results_size_before))
        printf("%d", read_last_line(&fd_results));

    exit(0);
}
