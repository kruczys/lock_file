#include <stdio.h>

int do_calculations(int x) {
    return 3*x*x*x + 11*x*x - 3*x + 103;
}

int main() {
    int number = 3;
    printf("%d\n", do_calculations(number));
}
