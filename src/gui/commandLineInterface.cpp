#include "commandLineInterface.hpp"
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>


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


using namespace cv;

int wczytaj_kartę() {
    // Lista nazw plików z kartami
  // Tutaj będą dodawane karty z tali
    std::vector<std::string> fileNames = {"karta1.jpg", "karta2.jpg", "karta3.jpg"}; 

    // Przejście przez każdą kartę z tali.
    for (const auto& fileName : fileNames) 
    
    {
        // Wczytanie obrazu
        Mat image = imread(fileName);

        // Sprawdzanie, czy obraz został poprawnie wczytany
        if (image.empty()) {
            std::cout << "Nie można wczytać obrazu: " << fileName << std::endl;
            continue;
        }

        // Wyświetlanie karty
        imshow("Karta", image);

        // Poczekaj na naciśnięcie klawisza przez użytkownika
        waitKey(0);
    }
    
    return 0;
}

// kod jest narazie szkieletem orginalnej wersji ale mniej więcej na tym będzie polegała inplementacja kart i wyswietlanie je w formacie .jpg

