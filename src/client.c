#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "lib.c"


int main() {
    int fd = open("buffer", O_RDWR|O_APPEND|O_CREAT, 0666);
    int input = read_user_input();
    write_last_line(&fd, &input);
    input = read_last_line(&fd);
    printf("%d", input + 123);
    close(fd);
    exit(0);
}

// 1. Sprawdz czy plik istnieje, jesli nie to utworz, jesli tak to nadpisz
// 2. wez plik na wylacznosc (plik zamkowy)
// 3. pobierz od uzytkownika liczbe
// 4. dopisz liczbe do pliku
// 5. zwolnij plik
// 6. sprawdzaj czy plik jest zajety, jesli bedzie zajety to czekaj az sie zwolni
// 7. zajmij plik na wylacznosc
// 8. wyswietl liczbe z ostatniej linii pliku 
// 9. wroc do 3, dopoki uzytkownik nie wyjdzie z programu
