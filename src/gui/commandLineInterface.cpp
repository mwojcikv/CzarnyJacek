#include "gui/commandLineInterface.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>


//funkcja nie działa przez problem sfml
//void Create_Window()
//{
//    // Utworzenie okna
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
//
//    // Ustawienie zielonego tła
//    sf::Color backgroundColor = sf::Color::Green;
//
//    // Czcionka i napis
//    sf::Font font;
//    if (!font.loadFromFile("C:/Users/PC/Desktop/Blackjack/CzarnyJacek/arial.ttf")) {
//        std::cerr << "Failed to load font \"arial.ttf\"" << std::endl;
//    }
//
//    sf::Text title("czarnyjacek", font, 24);
//    title.setFillColor(sf::Color::Black);
//    title.setPosition(350, 20); // Ustawienie pozycji napisu
//
//    // Przyciski
//    sf::RectangleShape startButton(sf::Vector2f(100, 50));
//    startButton.setFillColor(sf::Color::White);
//    startButton.setPosition(50, 100);
//
//    sf::Text startText("Start", font, 20);
//    startText.setFillColor(sf::Color::Black);
//    startText.setPosition(70, 110); // Ustawienie pozycji napisu na przycisku
//
//    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
//    exitButton.setFillColor(sf::Color::White);
//    exitButton.setPosition(50, 200);
//
//    sf::Text exitText("Wyjscie", font, 20);
//    exitText.setFillColor(sf::Color::Black);
//    exitText.setPosition(60, 210); // Ustawienie pozycji napisu na przycisku
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            } else if (event.type == sf::Event::MouseButtonPressed) {
//                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//                if (startButton.getGlobalBounds().contains(mousePosF)) {
//                    // Kod, który ma się wykonać po kliknięciu przycisku "Start"
//                    std::cout << "Start button clicked" << std::endl;
//                } else if (exitButton.getGlobalBounds().contains(mousePosF)) {
//                    window.close(); // Zamykanie okna po kliknięciu "Wyjście"
//                }
//            }
//        }
//
//        window.clear(backgroundColor);
//
//        window.draw(title);
//        window.draw(startButton);
//        window.draw(startText);
//        window.draw(exitButton);
//        window.draw(exitText);
//
//        window.display();
//    }
//}

void displayDeck(std::string suit, std::string rank) {
            std::string imagePath = "C:/Users/PC/Desktop/Blackjack/CzarnyJacek/cards/" + rank + "_of_" + suit + ".png";
            displayImage(imagePath);
}// wstępna implementacja funkcji wyświetlającej talię kart



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