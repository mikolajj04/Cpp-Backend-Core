#include "deleteresearcher.h"


void deleteResearcher(std::vector<std::unique_ptr<Employee>>& employees) {
    if (employees.empty()) {
        system("cls");
        std::cout << "Brak naukowcow do usuniecia.\n";
        return;
    }
    system("cls");
    std::cout << R"(
   _____      _            _   _     _   _           _     
  / ____|    (_)          | | (_)   | | | |         | |    
 | (___   ___ _  ___ _ __ | |_ _ ___| |_| |__  _   _| |__  
  \___ \ / __| |/ _ \ '_ \| __| / __| __| '_ \| | | | '_ \ 
  ____) | (__| |  __/ | | | |_| \__ \ |_| | | | |_| | |_) |
 |_____/ \___|_|\___|_| |_|\__|_|___/\__|_| |_|\__,_|_.__/      
-----------------------------------------------------------                                                                          
    )" << std::endl;
    std::cout << "\n======= Lista naukowcow =======\n";
    char label = 'A';

    for (size_t i = 0; i < employees.size() && label <= 'Z'; ++i) {
        std::cout << "[" << label << "] "
            << employees[i]->getName() << " "
            << employees[i]->getSurname() << " ("
            << employees[i]->getFieldNameAsString() << ")\n";
        ++label;
    }

    std::cout << "\nWybierz indeks naukowca do usuniecia (lub 0 aby anulowac): ";
    char choice;
    std::cin >> choice;
    choice = toupper(choice);
    system("cls");
    if (choice == '0') return;

    size_t index = choice - 'A';
    if (index >= employees.size()) {
        std::cout << "Nieprawidlowy wybor.\n";
        return;
    }

    std::cout << "\nCzy na pewno chcesz usunac "
        << employees[index]->getName() << " "
        << employees[index]->getSurname()
        << "? (t/n): ";

    char confirm;
    std::cin >> confirm;
    if (confirm == 't' || confirm == 'T') {
        employees.erase(employees.begin() + index);
        std::cout << "Usunieto pracownika.\n";
    }
    else {
        std::cout << "Anulowano usuwanie.\n";
    }
    std::cout << "Nacisnij Enter, aby wrocic do menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

}