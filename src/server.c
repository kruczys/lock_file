#include "lib.c"

int do_calculations(int x) {
    return 3*x*x*x + 11*x*x - 3*x + 103;
}

int main() {
    int fd_data = open_data_file();
    int fd_results = open_result_file();
    int data_size_before = get_file_size(&fd_data);

    while (1) {
        if (file_changed(&fd_data, &data_size_before)) {
            int number = read_last_line(&fd_data);
            number = do_calculations(number);
            write_last_line(&fd_results, &number); 
            data_size_before = get_file_size(&fd_data);
        }
    }
}
