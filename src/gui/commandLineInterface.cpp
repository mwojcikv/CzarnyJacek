#include <iostream>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int card_loading() {
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

//bedzie tu realizowana ,,GUI: 2: stworzenie dokumentacji używanych bibliotek (instrukcja jak pobrac uzywaną bibliotekę Openc)"
// mój koncept na to zadanie opiera sie na opisaniu i ułatwieniu poprawnej intalacji biblioteki.
