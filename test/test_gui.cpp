#include <gtest/gtest.h>
#include "wczytaj_kartę.hpp" // Załóż, że funkcja wczytaj_kartę jest zdefiniowana w pliku nagłówkowym

 // Testowanie wczytywania kart
 TEST(WczytajKartęTest, WczytanieKartyTest) {
     // Wywołaj funkcję wczytaj_kartę()
     int result = wczytaj_kartę();

     // Sprawdź, czy funkcja zwróciła 0 (sukces)
     EXPECT_EQ(result, 0);
 }
