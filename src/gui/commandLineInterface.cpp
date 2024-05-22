#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

enum MenuState {
    MAIN_MENU,
    BOTS_MENU,
    MULTIPLAYER_MENU,
    SHOP_MENU,
    EXCLUSIVE_CONTENT_MENU,
    RULES_MENU
};

void drawButton(sf::RenderWindow& window, sf::RectangleShape& button, sf::Text& text) {
    window.draw(button);
    window.draw(text);
}

void displayImageInWindow(sf::RenderWindow& window, const std::string& imagePath) {
    sf::Texture cardTexture;
    if (!cardTexture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return;
    }

    sf::Sprite cardSprite;
    cardSprite.setTexture(cardTexture);
    cardSprite.setPosition(400, 200);  // Position the card within the window

    window.draw(cardSprite);
}

void displayDeck(sf::RenderWindow& window, const std::string& suit, const std::string& rank) {
    std::string imagePath = "C:/Users/maksi/CLionProjects/untitled14/cards/" + rank + "_of_" + suit + ".png";
    displayImageInWindow(window, imagePath);
}

void createMenuWindow() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

    sf::Color backgroundColor = sf::Color::Green;

    sf::Font font;
    if (!font.loadFromFile("C://Users//maksi//Downloads/arial.ttf")) {
        std::cerr << "Failed to load font \"arial.ttf\"" << std::endl;
        return;
    }

    sf::Text title("Czarny Jacek", font, 48);  // Increase the size of the title
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 20);  // Centered based on the increased size

    sf::RectangleShape buttons[6];
    sf::Text buttonTexts[6];
    std::string buttonLabels[] = {"Rozgrywka z botami", "Rozgrywka multiplayer", "Sklep", "Ekskluzywna zawartosc", "Zasady gry", "Wyjscie"};

    for (int i = 0; i < 6; ++i) {
        buttons[i].setSize(sf::Vector2f(300, 50));
        buttons[i].setFillColor(sf::Color::White);
        buttons[i].setPosition(250, 100 + i * 70);

        buttonTexts[i].setFont(font);
        buttonTexts[i].setString(buttonLabels[i]);
        buttonTexts[i].setCharacterSize(20);
        buttonTexts[i].setFillColor(sf::Color::Black);
        buttonTexts[i].setPosition(270, 110 + i * 70);
    }

    MenuState currentState = MAIN_MENU;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (currentState == MAIN_MENU) {
                    for (int i = 0; i < 6; ++i) {
                        if (buttons[i].getGlobalBounds().contains(mousePosF)) {
                            switch (i) {
                                case 0:
                                    std::cout << "Rozgrywka z botami selected" << std::endl;
                                    currentState = BOTS_MENU;
                                    break;
                                case 1:
                                    std::cout << "Rozgrywka multiplayer selected" << std::endl;
                                    currentState = MULTIPLAYER_MENU;
                                    break;
                                case 2:
                                    std::cout << "Sklep selected" << std::endl;
                                    currentState = SHOP_MENU;
                                    break;
                                case 3:
                                    std::cout << "Ekskluzywna zawartosc selected" << std::endl;
                                    currentState = EXCLUSIVE_CONTENT_MENU;
                                    break;
                                case 4:
                                    std::cout << "Zasady gry selected" << std::endl;
                                    currentState = RULES_MENU;
                                    break;
                                case 5:
                                    window.close();
                                    break;
                            }
                        }
                    }
                } else if (currentState == BOTS_MENU || currentState == MULTIPLAYER_MENU || currentState == SHOP_MENU) {
                    
                }
            }
        }

        window.clear(backgroundColor);

        if (currentState == MAIN_MENU) {
            window.draw(title);
            for (int i = 0; i < 6; ++i) {
                drawButton(window, buttons[i], buttonTexts[i]);
            }
        } else if (currentState == BOTS_MENU) {
            sf::Text botsTitle("Rozgrywka z botami", font, 24);
            botsTitle.setFillColor(sf::Color::Black);
            botsTitle.setPosition(250, 20);
            window.draw(botsTitle);

            sf::RectangleShape botButtons[3];
            sf::Text botButtonTexts[3];
            std::string botButtonLabels[] = {"Rozpocznij gre", "Wybierz poziom trudnosci", "Wroc do menu"};

            for (int i = 0; i < 3; ++i) {
                botButtons[i].setSize(sf::Vector2f(300, 50));
                botButtons[i].setFillColor(sf::Color::White);
                botButtons[i].setPosition(250, 100 + i * 70);

                botButtonTexts[i].setFont(font);
                botButtonTexts[i].setString(botButtonLabels[i]);
                botButtonTexts[i].setCharacterSize(20);
                botButtonTexts[i].setFillColor(sf::Color::Black);
                botButtonTexts[i].setPosition(270, 110 + i * 70);

                drawButton(window, botButtons[i], botButtonTexts[i]);
            }

            // Detect button clicks in BOTS_MENU
            for (int i = 0; i < 3; ++i) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (botButtons[i].getGlobalBounds().contains(mousePosF) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    switch (i) {
                        case 0:
                            std::cout << "Rozpocznij gre selected" << std::endl;
                            // Implement game start logic
                            break;
                        case 1:
                            std::cout << "Wybierz poziom trudnosci selected" << std::endl;
                            // Implement difficulty selection logic
                            break;
                        case 2:
                            currentState = MAIN_MENU;
                            break;
                    }
                }
            }
        } else if (currentState == MULTIPLAYER_MENU) {
            sf::Text multiplayerTitle("Rozgrywka multiplayer", font, 24);
            multiplayerTitle.setFillColor(sf::Color::Black);
            multiplayerTitle.setPosition(250, 20);
            window.draw(multiplayerTitle);

            sf::RectangleShape multiplayerButtons[3];
            sf::Text multiplayerButtonTexts[3];
            std::string multiplayerButtonLabels[] = {"Rozpocznij gre", "Twoja ranga", "Wroc do menu"};

            for (int i = 0; i < 3; ++i) {
                multiplayerButtons[i].setSize(sf::Vector2f(300, 50));
                multiplayerButtons[i].setFillColor(sf::Color::White);
                multiplayerButtons[i].setPosition(250, 100 + i * 70);

                multiplayerButtonTexts[i].setFont(font);
                multiplayerButtonTexts[i].setString(multiplayerButtonLabels[i]);
                multiplayerButtonTexts[i].setCharacterSize(20);
                multiplayerButtonTexts[i].setFillColor(sf::Color::Black);
                multiplayerButtonTexts[i].setPosition(270, 110 + i * 70);

                drawButton(window, multiplayerButtons[i], multiplayerButtonTexts[i]);
            }

            // Detect button clicks in MULTIPLAYER_MENU
            for (int i = 0; i < 3; ++i) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (multiplayerButtons[i].getGlobalBounds().contains(mousePosF) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    switch (i) {
                        case 0:
                            std::cout << "Rozpocznij gre selected" << std::endl;
                            // Implement game start logic
                            break;
                        case 1:
                            std::cout << "Twoja ranga selected" << std::endl;
                            // Implement rank display logic
                            break;
                        case 2:
                            currentState = MAIN_MENU;
                            break;
                    }
                }
            }
        } else if (currentState == SHOP_MENU) {
            sf::Text shopTitle("Sklep", font, 24);
            shopTitle.setFillColor(sf::Color::Black);
            shopTitle.setPosition(250, 20);
            window.draw(shopTitle);

            sf::RectangleShape shopButtons[3];
            sf::Text shopButtonTexts[3];
            std::string shopButtonLabels[] = {"Sklep z kartami", "Sklep z ulepszeniami", "Wroc do menu"};

            for (int i = 0; i < 3; ++i) {
                shopButtons[i].setSize(sf::Vector2f(300, 50));
                shopButtons[i].setFillColor(sf::Color::White);
                shopButtons[i].setPosition(250, 100 + i * 70);

                shopButtonTexts[i].setFont(font);
                shopButtonTexts[i].setString(shopButtonLabels[i]);
                shopButtonTexts[i].setCharacterSize(20);
                shopButtonTexts[i].setFillColor(sf::Color::Black);
                shopButtonTexts[i].setPosition(270, 110 + i * 70);

                drawButton(window, shopButtons[i], shopButtonTexts[i]);
            }

            // Detect button clicks in SHOP_MENU
            for (int i = 0; i < 3; ++i) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (shopButtons[i].getGlobalBounds().contains(mousePosF) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    switch (i) {
                        case 0:
                            std::cout << "Sklep z kartami selected" << std::endl;
                            // Implement card shop logic
                            break;
                        case 1:
                            std::cout << "Sklep z ulepszeniami selected" << std::endl;
                            // Implement upgrade shop logic
                            break;
                        case 2:
                            currentState = MAIN_MENU;
                            break;
                    }
                }
            }
        }

        window.display();
    }
}


