#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int wczytaj_kartę() {
    // Lista nazw plików z kartami
  // Tutaj będą dodawane karty z tali
    vector<string> fileNames = {"karta1.jpg", "karta2.jpg", "karta3.jpg"}; 

    // Przejście przez każdą kartę z tali.
    for (const auto& fileName : fileNames) 
    
    {
        // Wczytanie obrazu
        Mat image = imread(fileName);

        // Sprawdzanie, czy obraz został poprawnie wczytany
        if (image.empty()) {
            cout << "Nie można wczytać obrazu: " << fileName << endl;
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
