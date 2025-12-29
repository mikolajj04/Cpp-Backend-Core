#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Struktura wezla drzewa Huffmanna.
 *
 * Ta struktura reprezentuje wezel uzywany w drzewie Huffmanna, gdzie
 * przechowywany jest symbol oraz czestotliwosc wystepowania tego symbolu.
 * Posiada rowniez wskazniki do lewej i prawej galezi drzewa.
 */
struct Node {
    char symbol;         /**< Symbol reprezentowany przez wezel. */
    int frequency;       /**< Czestotliwosc wystepowania symbolu. */
    Node* left;          /**< Wskaznik na lewe dziecko w drzewie Huffmanna. */
    Node* right;         /**< Wskaznik na prawe dziecko w drzewie Huffmanna. */

    /**
     * @brief Konstruktor wezla.
     *
     * Inicjalizuje wezel drzewa Huffmanna dla podanego symbolu i czestotliwosci.
     * Wskazniki do lewego oraz prawego dziecka sa ustawione na nullptr.
     *
     * @param sym Symbol, ktory reprezentuje dany wezel.
     * @param freq Czestotliwosc wystepowania symbolu.
     */
    Node(char sym, int freq) : symbol(sym), frequency(freq), left(nullptr), right(nullptr) {}
};

/**
 * @brief Porownanie wezlow dla kolejki priorytetowej.
 *
 * Struktura sluzy do porownywania dwoch wezlow drzewa Huffmanna na podstawie ich czestotliwosci.
 * Jest uzywana przy implementacji kolejki priorytetowej.
 */
struct Compare {
    /**
     * @brief Operator porownania.
     *
     * Porownuje dwa wezly drzewa Huffmanna.
     *
     * @param a Wskaznik na pierwszy wezel.
     * @param b Wskaznik na drugi wezel.
     * @return true, jesli czestotliwosc wezla a jest wieksza niz czestotliwosc wezla b, w przeciwnym razie false.
     */
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

/**
 * @brief Koduje zawartosc pliku wejsciowego przy uzyciu drzewa Huffmanna.
 *
 * Funkcja przetwarza plik wejsciowy, koduje jego zawartosc metoda Huffmanna
 * i zapisuje wynik do pliku wyjsciowego.
 *
 * @param inputFile Sciezka do pliku wejsciowego.
 * @param outputFile Sciezka do pliku wyjsciowego.
 */
void encodeFile(const string& inputFile, const string& outputFile);

/**
 * @brief Dekoduje zawartosc zakodowanego pliku przy uzyciu drzewa Huffmanna.
 *
 * Funkcja odtwarza oryginalna zawartosc pliku, ktory zostal zakodowany metoda Huffmanna.
 *
 * @param inputFile Sciezka do pliku wejsciowego z zakodowanymi danymi.
 * @param outputFile Sciezka do pliku, do ktorego zostanie zapisana zdekompresowana zawartosc.
 */
void decodeFile(const string& inputFile, const string& outputFile);

/**
 * @brief Buduje tabele kodow Huffmanna.
 *
 * Funkcja rekurencyjnie przechodzi drzewo Huffmanna i przypisuje kazdemu symbolowi
 * odpowiedni kod (ciag znakow) na podstawie jego pozycji w drzewie.
 *
 * @param root Wskaznik na korzen drzewa Huffmanna.
 * @param str Aktualny ciag kodu (sciezka do danego wezla) w drzewie.
 * @param huffmanCode Referencja do mapy, w ktorej zapisywane sa kody Huffmanna.
 */
void buildCodeTable(Node* root, const string& str, unordered_map<char, string>& huffmanCode);

#endif // HUFFMAN_H