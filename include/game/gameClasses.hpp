#ifndef BLACKJACK_BLACKJACK_HPP
#define BLACKJACK_BLACKJACK_HPP

#include <iostream>
#include <string>

class Krupier {
private:
    std::vector<Karta> reka; // krupier trzyma na ręcę elementy klasy Karta

public:
    void otrzymajKarte(Karta karta) {
        reka.push_back(karta);
    }

    int sumaRęki() {
        int suma = 0;
        int asy = 0;
        for (const Karta& karta : reka) {
            if (karta.wartość() == "As") {
                asy++;
            } else {
                suma += karta.wartość();
            }
        }

        for (int i = 0; i < asy; i++) {
            if (suma + 11 <= 21) {
                suma += 11;
            } else {
                suma += 1;
            }
        }

        return suma;
    }

    bool czyPrzegrałeś() {
        return sumaRęki() > 21;
    }

    bool czyPokonałeś(int sumaGracza) {
        return sumaRęki() > sumaGracza || sumaGracza > 21;
    }

    bool czyRemis(int sumaGracza) {
        return sumaRęki() == sumaGracza;
    }

    void wyczyśćRękę() {
        reka.clear();
    }
};

#endif //BLACKJACK_BLACKJACK_HPP
