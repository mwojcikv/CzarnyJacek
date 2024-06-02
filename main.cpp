#include "game/gameClasses.hpp"
#include "game/gameRules.hpp"
#include "gui/commandLineInterface.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

// Enumeration for menu and game states
enum MenuState {
    MAIN_MENU,
    BOTS_MENU,
    MULTIPLAYER_MENU,
    SHOP_MENU,
    EXCLUSIVE_CONTENT_MENU,
    RULES_MENU,
    BLACKJACK_GAME
};

// Card struct to represent a card in the deck


// Function to draw a button
void drawButton(sf::RenderWindow& window, sf::RectangleShape& button, sf::Text& text) {
    window.draw(button);
    window.draw(text);
}
<<<<<<< HEAD
//dodanie resetu stołu
void displayImageInWindow(sf::RenderWindow& window, const std::string& imagePath, const sf::Vector2f& position, const sf::Vector2f& size) {
    sf::Texture cardTexture;
    if (!cardTexture.loadFromFile(imagePath)) {
=======

// Function to display a card image in the window
sf::Sprite createCardSprite(const std::string& imagePath) {
    sf::Texture* cardTexture = new sf::Texture();
    if (!cardTexture->loadFromFile(imagePath)) {
>>>>>>> 4fb6efdb82f0c46fefd07a286a5975042029439a
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return sf::Sprite();
    }

    sf::Sprite cardSprite;
    cardSprite.setTexture(*cardTexture);
    cardSprite.setScale(0.3f, 0.3f);  // Further scale down the card to fit more cards
    return cardSprite;
}

// Function to get the path to a card image
std::string getCardImagePath(const Card* card) {
    return "C:/workspace/studia/npg/projekt_npg/CzarnyJacek/cards/" + cardToString(card);
}

// Function to draw a hand of cards
void drawHand(sf::RenderWindow& window, const Hand& hand, float yPosition, const sf::Font& font) {
    std::vector<sf::Sprite> spriteCollection;
    float xPosition = 250;
    for (const auto& card_u_ptr : hand) {
        sf::Sprite cardSprite = createCardSprite(getCardImagePath(card_u_ptr.get()));
        cardSprite.setPosition(xPosition, yPosition);
        window.draw(cardSprite);
        xPosition += 40;  // Adjust spacing between cards to fit more cards

    }
    // Create text object to display hand value
    if(hand.isDealer() == 0){
        sf::Text handValueText;
        handValueText.setFont(font);
        handValueText.setString("Hand Value: " + std::to_string(hand.handValue()));
        handValueText.setCharacterSize(20);
        handValueText.setFillColor(sf::Color::Black);
        handValueText.setPosition(50, 350 );

        // Draw the hand value text
        window.draw(handValueText);
    }
}

sf::Sprite drawReverse(sf::RenderWindow& window,float xPosition, float yPosition) {
    sf::Sprite cardSprite = createCardSprite("C:/workspace/studia/npg/projekt_npg/CzarnyJacek/cards reverse/basic/card_reverse_red.png");
    cardSprite.setPosition(xPosition, yPosition);
    window.draw(cardSprite);

    return cardSprite;
}

// Function to create the menu window
void createMenuWindow() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

    sf::Color backgroundColor = sf::Color::Green;

    sf::Font font;
    if (!font.loadFromFile("C:/workspace/studia/npg/projekt_npg/CzarnyJacek/arial.ttf")) {
        std::cerr << "Failed to load font \"arial.ttf\"" << std::endl;
        return;
    }

    sf::Text title("Czarny Jacek", font, 48);
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 20);

    sf::RectangleShape buttons[6];
    sf::Text buttonTexts[6];
    std::string buttonLabels[] = {"Rozgrywka z botami", "Rozgrywka multiplayer", "Sklep", "Ekskluzywna zawartosc", "Zasady gry", "Wyjscie"};

    for (int i = 0; i < 6; ++i) {
        buttons[i].setSize(sf::Vector2f(300, 50));
        buttons[i].setFillColor(sf::Color::White);
        buttons[i].setPosition(250, float(100 + i * 70));

        buttonTexts[i].setFont(font);
        buttonTexts[i].setString(buttonLabels[i]);
        buttonTexts[i].setCharacterSize(20);
        buttonTexts[i].setFillColor(sf::Color::Black);
        buttonTexts[i].setPosition(270, float(110 + i * 70));
    }

    MenuState currentState = MAIN_MENU;

    // Blackjack game variables
    DeckOfCards deck;
    Gamer playerHand;
    Dealer dealerHand;
    bool isPlayerTurn = true;
    bool isGameOver = false;
    std::string gameResult;
    sf::Sprite dealerReverse = drawReverse(window,290 ,100);

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
                                    currentState = BLACKJACK_GAME;
                                    deck.shuffleDeck();
                                    dealerHand.dealInitialHand(&playerHand, &deck);
                                    isPlayerTurn = true;
                                    isGameOver = false;
                                    gameResult = "";
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
                } else if (currentState == BLACKJACK_GAME) {
                    sf::RectangleShape gameButtons[3];
                    sf::Text gameButtonTexts[3];
                    std::string gameButtonLabels[] = {"Hit", "Stand", "Back to Menu"};
                    for (int i = 0; i < 3; ++i) {
                        gameButtons[i].setSize(sf::Vector2f(150, 50));
                        gameButtons[i].setFillColor(sf::Color::White);
                        gameButtons[i].setPosition(float(50 + i * 170), 500);

                        gameButtonTexts[i].setFont(font);
                        gameButtonTexts[i].setString(gameButtonLabels[i]);
                        gameButtonTexts[i].setCharacterSize(20);
                        gameButtonTexts[i].setFillColor(sf::Color::Black);
                        gameButtonTexts[i].setPosition(float(70 + i * 170), 510);
                    }

                    for (int i = 0; i < 3; ++i) {
                        if (gameButtons[i].getGlobalBounds().contains(mousePosF) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            switch (i) {
                                case 0:  // Hit
                                    if (isPlayerTurn && !isGameOver) {
                                        deck.getTopCard(&playerHand);
                                        if (playerHand.handValue() > 21) {
                                            isGameOver = true;
                                            gameResult = "Player busts! Dealer wins.";
                                        }
                                    }
                                    break;
                                case 1:  // Stand
                                    if (isPlayerTurn && !isGameOver) {
                                        isPlayerTurn = false;
                                        dealerReverse.setColor(sf::Color(255, 255, 255, 0));
                                        while (dealerHand.handValue() < 17 ){
                                            deck.getTopCard(&dealerHand);
                                        }
                                        int playerValue = playerHand.handValue();
                                        int dealerValue = dealerHand.handValue();
                                        if (dealerValue > 21 ) {
                                            gameResult = "Player wins!";
                                        } else if (playerValue < dealerValue) {
                                            gameResult = "Dealer wins!";

                                        isGameOver = true;
                                        }
                                    }
                                    break;
                                case 2:  // Back to menu
                                    currentState = MAIN_MENU;
                                    break;
                            }
                        }
                    }

                    // Draw the game buttons
                    for (int i = 0; i < 3; ++i) {
                        drawButton(window, gameButtons[i], gameButtonTexts[i]);
                    }
                }
            }
        }

        window.clear(backgroundColor);

        if (currentState == MAIN_MENU) {
            window.draw(title);
            for (int i = 0; i < 6; ++i) {
                drawButton(window, buttons[i], buttonTexts[i]);
            }
        } else if (currentState == BLACKJACK_GAME) {
            sf::Text gameTitle("Blackjack", font, 24);
            gameTitle.setFillColor(sf::Color::Black);
            gameTitle.setPosition(250, 20);
            window.draw(gameTitle);

            drawHand(window, playerHand, 350, font);  // Draw player's hand at the bottom
            drawHand(window, dealerHand, 100, font);  // Draw dealer's hand at the top
            window.draw(dealerReverse);

            // Draw the game buttons
            sf::RectangleShape gameButtons[3];
            sf::Text gameButtonTexts[3];
            std::string gameButtonLabels[] = {"Hit", "Stand", "Back to Menu"};

            for (int i = 0; i < 3; ++i) {
                gameButtons[i].setSize(sf::Vector2f(150, 50));
                gameButtons[i].setFillColor(sf::Color::White);
                gameButtons[i].setPosition(float(50 + i * 170), 500);

                gameButtonTexts[i].setFont(font);
                gameButtonTexts[i].setString(gameButtonLabels[i]);
                gameButtonTexts[i].setCharacterSize(20);
                gameButtonTexts[i].setFillColor(sf::Color::Black);
                gameButtonTexts[i].setPosition(float(70 + i * 170), 510);
            }

            for (int i = 0; i < 3; ++i) {
                drawButton(window, gameButtons[i], gameButtonTexts[i]);
            }

            if (isGameOver) {
                sf::Text resultText(gameResult, font, 24);
                resultText.setFillColor(sf::Color::Red);
                resultText.setPosition(250, 400);
                window.draw(resultText);
            }
        }

        window.display();
    }
}

int main() {
    createMenuWindow();
    return 0;
}
