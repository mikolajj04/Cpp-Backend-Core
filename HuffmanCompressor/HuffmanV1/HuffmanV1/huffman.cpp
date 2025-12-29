#include "huffman.h"

/**
 * @brief Buduje tablice kodow Huffmana przez rekurencyjne przeszukiwanie drzewa.
 *
 * Funkcja rekurencyjnie przechodzi przez drzewo Huffmana i przypisuje kazdemu lisciowi (symbolowi)
 * odpowiedni kod binarny. Do lewego poddrzewa dodawane jest "0", a do prawego "1".
 *
 * @param root Wskaznik do biezacego wezla drzewa Huffmana.
 * @param str Aktualnie zbudowany kod binarny.
 * @param huffmanCode Mapa, ktora przechowuje ostateczne kody Huffmana dla kazdego symbolu.
 */
void buildCodeTable(Node* root, const string& str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;
    // Jezeli wezel jest lisciem (brak lewego i prawego potomka), przypisz kod do symbolu.
    if (!root->left && !root->right) {
        huffmanCode[root->symbol] = str;
    }
    // Rekurencyjne przejscie do lewego poddrzewa z dodaniem "0" do kodu.
    buildCodeTable(root->left, str + "0", huffmanCode);
    // Rekurencyjne przejscie do prawego poddrzewa z dodaniem "1" do kodu.
    buildCodeTable(root->right, str + "1", huffmanCode);
}

/**
 * @brief Koduje plik wejsciowy przy uzyciu algorytmu Huffmana.
 *
 * Funkcja odczytuje zawartosc pliku wejsciowego, liczy czestotliwosc wystepowania kazdego znaku,
 * buduje drzewo Huffmana, generuje kody dla znakow, a nastepnie koduje tekst. Zakodowany tekst
 * oraz tablica kodow sa zapisywane do pliku wyjsciowego.
 *
 * @param inputFile Nazwa pliku wejsciowego (sciezka do pliku).
 * @param outputFile Nazwa pliku wyjsciowego (sciezka do pliku).
 */
void encodeFile(const string& inputFile, const string& outputFile) {
    // Otwieranie pliku wejsciowego w trybie binarnym.
    ifstream input(inputFile, ios::binary);
    if (!input.is_open()) {
        cerr << "Nie mozna otworzyc pliku wejsciowego!" << endl;
        return;
    }

    // Zliczanie czestotliwosci wystepowania znakow.
    unordered_map<char, int> frequency;
    stringstream buffer;
    buffer << input.rdbuf();
    string text = buffer.str();
    input.close();

    // Przeliczanie wystapienia kazdego znaku w tekscie.
    for (char ch : text) {
        frequency[ch]++;
    }

    // Tworzenie kolejki priorytetowej do budowy drzewa Huffmana.
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Budowa drzewa Huffmana.
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        // Tworzenie nowego wezla sumujacego czestotliwosci.
        Node* sum = new Node('\0', left->frequency + right->frequency);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }
    Node* root = pq.top();

    // Generowanie tablicy kodow Huffmana.
    unordered_map<char, string> huffmanCode;
    buildCodeTable(root, "", huffmanCode);

    // Kodowanie tekstu przy pomocy wygenerowanych kodow.
    string encodedText;
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }

    // Zapisanie tablicy kodow i zakodowanego tekstu do pliku wyjsciowego.
    ofstream output(outputFile, ios::binary);
    if (!output.is_open()) {
        cerr << "Nie mozna otworzyc pliku wyjsciowego!" << endl;
        return;
    }
    // Zapis rozmiaru tablicy kodow.
    output << huffmanCode.size() << endl;
    // Zapis par: symbol:kod.
    for (auto pair : huffmanCode) {
        output << pair.first << ":" << pair.second << endl;
    }
    // Zapis zakodowanego tekstu.
    output << encodedText;
    output.close();
}

/**
 * @brief Dekoduje plik zakodowany algorytmem Huffmana.
 *
 * Funkcja odczytuje z pliku zakodowany tekst oraz tablice kodow (w postaci klucz: kod binarny, wartosc: symbol),
 * odwraca mapowanie, a nastepnie dekoduje tekst przy uzyciu odwroconej tablicy kodow.
 * Zdekodowany tekst jest zapisywany do pliku wyjsciowego.
 *
 * @param inputFile Nazwa pliku wejsciowego z zakodowanym tekstem.
 * @param outputFile Nazwa pliku wyjsciowego, do ktorego zapisany zostanie zdekodowany tekst.
 */
void decodeFile(const string& inputFile, const string& outputFile) {
    // Otwieranie pliku wejsciowego w trybie binarnym.
    ifstream input(inputFile, ios::binary);
    if (!input.is_open()) {
        cerr << "Nie mozna otworzyc pliku wejsciowego!" << endl;
        return;
    }

    // Odczyt tablicy kodow zapisanej w pliku.
    unordered_map<string, char> reverseHuffmanCode; // Klucz: kod binarny, Wartosc: symbol.
    int tableSize; // Liczba roznych elementow (symboli) zapisanych w tablicy.
    input >> tableSize;
    input.ignore(); // Ignorowanie znaku nowej linii.

    for (int i = 0; i < tableSize; i++) {
        char symbol;
        string code;
        input.get(symbol);
        input.ignore(1); // Pomijanie dwukropka ':'.
        getline(input, code);
        reverseHuffmanCode[code] = symbol;
    }

    // Odczyt zakodowanego tekstu z pliku.
    string encodedText;
    getline(input, encodedText, '\0');
    input.close();

    // Dekodowanie tekstu przy uzyciu odwroconej tablicy kodow.
    string decodedText;
    string currentCode;
    for (char bit : encodedText) {
        currentCode += bit;
        if (reverseHuffmanCode.count(currentCode)) {
            decodedText += reverseHuffmanCode[currentCode];
            currentCode = "";
        }
    }

    // Zapis zdekodowanego tekstu do pliku wyjsciowego.
    ofstream output(outputFile, ios::binary);
    if (!output.is_open()) {
        cerr << "Nie mozna otworzyc pliku wyjsciowego!" << endl;
        return;
    }
    output << decodedText;
    output.close();
}