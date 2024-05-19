#include "gui/commandLineInterface.hpp"
#include <iostream>
#include <vector>
// #include <SFML/Graphics.hpp>


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
    //system("cls");

    switch (opcja) {
        case 1:
            std::cout << "\n===== Rozgrywka z botami =====\n\n";
            std::cout << "*gui_dla_botow*\n";
            std::cout << "1. Rozpocznij gre\n";
            std::cout << "2. Wybierz poziom trudnosci\n";
            std::cout << "3. Wroc do menu\n\n";
            int opcja1;
            std::cout << "Wybierz opcje: ";
            std::cin >> opcja1;
            //system("cls");
            break;
        case 2:
            std::cout << "\n===== Rozgrywka multiplayer =====\n\n";
            std::cout << "*gui_dla_multiplayera*\n";
            std::cout << "1. Rozpocznij gre\n";
            std::cout << "2. Twoja ranga\n";
            std::cout << "3. Wroc do menu\n\n";
            int opcja2;
            std::cout << "Wybierz opcje: ";
            std::cin >> opcja2;
            //system("cls");
            break;
        case 3:
            std::cout << "\n===== Sklep =====\n\n";
            std::cout << "*gui_dla_sklepu*\n";
            std::cout << "1. Sklep z kartami\n";
            std::cout << "2. Sklep z ulepszeniami\n";
            std::cout << "3. Wroc do menu\n\n";
            int opcja3;
            std::cout << "Wybierz opcje: ";
            std::cin >> opcja3;
            //system("cls");
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

//std::string imagePath = "C:\\Users\\maksi\\CLionProjects\\untitled14\\f4.png";

// void displayImage(const std::string& imagePath) {
//     sf::RenderWindow window(sf::VideoMode(1000, 800), "Wyświetlanie karty PNG");

//     sf::Texture cardTexture;
//     if (!cardTexture.loadFromFile(imagePath)) {
//         return;
//     }

//     sf::Sprite cardSprite;
//     cardSprite.setTexture(cardTexture);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         window.clear();
//         window.draw(cardSprite);
//         window.display();
//     }
// }



