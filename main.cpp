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


enum MenuState {
    MAIN_MENU,
    BOTS_MENU,
    MULTIPLAYER_MENU,
    SHOP_MENU,
    RULES_MENU,
    BLACKJACK_GAME
};


void drawButton(sf::RenderWindow& window, sf::RectangleShape& button, sf::Text& text) {
    window.draw(button);
    window.draw(text);
}


sf::Sprite createCardSprite(const std::string& imagePath) {
    sf::Texture* cardTexture = new sf::Texture();
    if (!cardTexture->loadFromFile(imagePath)) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return sf::Sprite();
    }

    sf::Sprite cardSprite;
    cardSprite.setTexture(*cardTexture);
    cardSprite.setScale(0.3f, 0.3f);
    return cardSprite;
}


std::string getCardImagePath(const Card* card) {
    return "C:\\Users\\maksi\\Downloads\\CzarnyJacek-maksw-dev\\CzarnyJacek-maksw-dev/cards/" + cardToString(card);
}

void drawHand(sf::RenderWindow& window, const Hand& hand, float yPosition, const sf::Font& font) {
    std::vector<sf::Sprite> spriteCollection;
    float xPosition = 250;
    for (const auto& card_u_ptr : hand) {
        sf::Sprite cardSprite = createCardSprite(getCardImagePath(card_u_ptr.get()));
        cardSprite.setPosition(xPosition, yPosition);
        window.draw(cardSprite);
        xPosition += 40;
    }


    if (hand.isDealer() == 0) {
        sf::Text handValueText;
        handValueText.setFont(font);
        handValueText.setString("Hand Value: " + std::to_string(hand.handValue()));
        handValueText.setCharacterSize(20);
        handValueText.setFillColor(sf::Color::Black);
        handValueText.setPosition(50, 350);


        window.draw(handValueText);
    }
}

sf::Sprite drawReverse(sf::RenderWindow& window, float xPosition, float yPosition) {
    sf::Sprite cardSprite = createCardSprite("C:\\Users\\maksi\\Downloads\\CzarnyJacek-maksw-dev\\CzarnyJacek-maksw-dev reverse/basic/card_reverse_red.png");
    cardSprite.setPosition(xPosition, yPosition);
    window.draw(cardSprite);

    return cardSprite;
}


void createMenuWindow() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");

    sf::Color backgroundColor = sf::Color::Green;

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\maksi\\Downloads\\CzarnyJacek-maksw-dev\\CzarnyJacek-maksw-dev/arial.ttf")) {
        std::cerr << "Failed to load font \"arial.ttf\"" << std::endl;
        return;
    }

    sf::Text title("Czarny Jacek", font, 48);
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 20);

    sf::RectangleShape buttons[6];
    sf::Text buttonTexts[6];
    std::string buttonLabels[] = {"Singleplayer game", "Multiplayer game", "In-game store", "Game rules", "Exit game"};

    for (int i = 0; i < 5; ++i) {
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


    DeckOfCards deck;
    Gamer playerHand;
    Dealer dealerHand;
    bool isPlayerTurn = true;
    bool isGameOver = false;
    std::string gameResult;
    sf::Sprite dealerReverse = drawReverse(window, 290, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                if (currentState == MAIN_MENU) {
                    for (int i = 0; i < 5; ++i) {
                        if (buttons[i].getGlobalBounds().contains(mousePosF)) {
                            switch (i) {
                                case 0:
                                    std::cout << "Gameplay" << std::endl;
                                    currentState = BLACKJACK_GAME;
                                    deck.shuffleDeck();
                                    dealerHand.dealInitialHand(&playerHand, &deck);
                                    isPlayerTurn = true;
                                    isGameOver = false;
                                    gameResult = "";
                                    break;
                                case 1:
                                    std::cout << "Multiplayer game selected" << std::endl;
                                    currentState = MULTIPLAYER_MENU;
                                    break;
                                case 2:
                                    std::cout << "In-game store selected" << std::endl;
                                    currentState = SHOP_MENU;
                                    break;
                                case 3:
                                    std::cout << "Game rules selected" << std::endl;
                                    currentState = RULES_MENU;
                                    break;
                                case 4:
                                    window.close();
                                    break;
                            }
                        }
                    }
                } else if (currentState == MULTIPLAYER_MENU) {
                    sf::RectangleShape backButton;
                    backButton.setSize(sf::Vector2f(300, 50));
                    backButton.setFillColor(sf::Color::White);
                    backButton.setPosition(250, 400);

                    sf::Text backButtonText;
                    backButtonText.setFont(font);
                    backButtonText.setString("Back to Menu");
                    backButtonText.setCharacterSize(20);
                    backButtonText.setFillColor(sf::Color::Black);
                    backButtonText.setPosition(270, 410);

                    if (backButton.getGlobalBounds().contains(mousePosF)) {
                        currentState = MAIN_MENU;
                    }

                    window.draw(backButton);
                    window.draw(backButtonText);
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
                                case 0:
                                    if (isPlayerTurn && !isGameOver) {
                                        deck.getTopCard(&playerHand);
                                        if (playerHand.handValue() > 21) {
                                            isGameOver = true;
                                            gameResult = "Player busts! Dealer wins.";
                                        }
                                    }
                                    break;
                                case 1:
                                    if (isPlayerTurn && !isGameOver) {
                                        isPlayerTurn = false;
                                        dealerReverse.setColor(sf::Color(255, 255, 255, 0));
                                        while (dealerHand.handValue() < 17) {
                                            deck.getTopCard(&dealerHand);
                                        }
                                        int playerValue = playerHand.handValue();
                                        int dealerValue = dealerHand.handValue();
                                        if (dealerValue > 21) {
                                            gameResult = "Player wins!";
                                        } else if (playerValue < dealerValue) {
                                            gameResult = "Dealer wins!";
                                        }

                                        isGameOver = true;
                                    }
                                    break;
                                case 2:  // Back to menu
                                    currentState = MAIN_MENU;
                                    break;
                            }
                        }
                    }


                    for (int i = 0; i < 3; ++i) {
                        drawButton(window, gameButtons[i], gameButtonTexts[i]);
                    }
                }
            }
        }

        window.clear(backgroundColor);

        if (currentState == MAIN_MENU) {
            window.draw(title);
            for (int i = 0; i < 5; ++i) {
                drawButton(window, buttons[i], buttonTexts[i]);
            }
        } else if (currentState == MULTIPLAYER_MENU) {
            sf::Text multiplayerMessage("Multiplayer game is under development. Stay tuned!", font, 24);
            multiplayerMessage.setFillColor(sf::Color::Black);
            multiplayerMessage.setPosition(50, 200);

            sf::RectangleShape backButton;
            backButton.setSize(sf::Vector2f(300, 50));
            backButton.setFillColor(sf::Color::White);
            backButton.setPosition(250, 400);

            sf::Text backButtonText;
            backButtonText.setFont(font);
            backButtonText.setString("Back to Menu");
            backButtonText.setCharacterSize(20);
            backButtonText.setFillColor(sf::Color::Black);
            backButtonText.setPosition(270, 410);

            window.draw(multiplayerMessage);
            window.draw(backButton);
            window.draw(backButtonText);
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
