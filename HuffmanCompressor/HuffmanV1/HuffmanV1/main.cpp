#include <iostream>
#include <cstring>
#include "huffman.h"

using namespace std;

/**
 * @brief Glowna funkcja aplikacji do kodowania Huffmana.
 *
 * Funkcja ta przetwarza argumenty wiersza polecen, aby zakodowac lub zdekodowac plik przy uzyciu kodowania Huffmana.
 * Sprawdza, czy podano wszystkie wymagane argumenty oraz upewnia sie, ze operacje kodowania i dekodowania nie sa
 * wykonywane jednoczesnie.
 *
 * Sposob uzycia:
 *   program -i <plik_wejsciowy> -o <plik_wyjsciowy> -c/-d
 *
 * @param argc Liczba argumentow wiersza polecen.
 * @param argv Tablica ciagow znakow z argumentami wiersza polecen.
 * @return int Zwraca 0 przy powodzeniu lub 1 w przypadku bledu.
 */
int main(int argc, char* argv[]) {
    // Sprawdzenie, czy podano minimalna liczbe argumentow
    if (argc < 5) {
        cerr << "Uzycie: program -i <plik_wejsciowy> -o <plik_wyjsciowy> -c/-d" << endl;
        return 1;
    }

    string inputFile, outputFile;
    bool encode = false, decode = false;

    // Przetwarzanie opcji z wiersza polecen
    for (int i = 1; i < argc; i++) {
        // Sprawdzenie opcji pliku wejsciowego
        if (strcmp(argv[i], "-i") == 0) {
            inputFile = argv[++i];
        }
        // Sprawdzenie opcji pliku wyjsciowego
        else if (strcmp(argv[i], "-o") == 0) {
            outputFile = argv[++i];
        }
        // Ustawienie flagi kodowania, gdy znaleziono opcje "-c"
        else if (strcmp(argv[i], "-c") == 0) {
            encode = true;
        }
        // Ustawienie flagi dekodowania, gdy znaleziono opcje "-d"
        else if (strcmp(argv[i], "-d") == 0) {
            decode = true;
        }
    }

    // Upewnienie sie, ze nie wybrano jednoczesnie opcji kodowania i dekodowania
    if (encode && decode) {
        cerr << "Opcje -c i -d nie moga byc uzywane jednoczesnie!" << endl;
        return 1;
    }

    // Wykonanie odpowiedniej operacji w zaleznosci od podanej opcji
    if (encode) {
        encodeFile(inputFile, outputFile);
    }
    else if (decode) {
        decodeFile(inputFile, outputFile);
    }
    else {
        cerr << "Brak podanej operacji kodowania lub dekodowania!" << endl;
        return 1;
    }

    return 0;
}