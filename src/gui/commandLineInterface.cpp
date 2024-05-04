#include "commandLineInterface.hpp"


void interface() {
    int opcja;
    std::cout << "\n\n========================\n" << "===== Czarny Jacek =====\n" << "========================\n\n";
    std::cout << "Menu:\n";
    std::cout << "1. Rozgrywka z botami\n";
    std::cout << "2. Rozgrywka multiplayer\n";
    std::cout << "3. Sklep\n";
    std::cout << "4. Ekskluzywna zawartosc dla uzytkownikow\n";
    std::cout << "5. Zasady gry w Blackjack\n";
    std::cout << "6. Wyjscie\n\n";
    std::cout << "Wybierz opcje: ";
    std::cin >> opcja;

    switch (opcja) {
        case 1:
            std::cout << "\n===== Rozgrywka z botami =====\n\n";
            std::cout << "*gui_dla_botow*\n";
            break;
        case 2:
            std::cout << "\n===== Rozgrywka multiplayer =====\n\n";
            std::cout << "*gui_dla_multiplayera*\n";
            break;
        case 3:
            std::cout << "\n===== Sklep =====\n\n";
            std::cout << "*gui_dla_sklepu*\n";
            break;
        case 4:
            std::cout << "\n===== Ekskluzywna zawartosc dla uzytkownikow =====\n\n";
            std::cout << "*gui_dla_zawartosci*\n";
            break;
        case 5:
            std::cout << "\n===== Zasady gry w Blackjack =====\n\n";
            std::cout << "*gui_dla_zasad*\n";
            break;
        case 6:
            std::cout << "\nDziekujemy za gre, do nastepnego!\n\n";
            std::cout << "*exit_game*\n";
            break;
        default:
            std::cout << "\nNieprawidlowy wybor. Wybierz ponownie.\n";
            break;
    }
}
