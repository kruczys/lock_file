#include <stdio.h>
#include <stdlib.h>

int read_user_input() {
  int number;
  scanf("%d", &number);
  return number;
}

int main() {
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
