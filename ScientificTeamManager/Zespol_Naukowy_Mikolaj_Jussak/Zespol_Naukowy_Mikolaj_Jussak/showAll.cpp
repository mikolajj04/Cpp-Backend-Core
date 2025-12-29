#include <cctype> 
#include "showall.h"

void showAll(const std::vector<std::unique_ptr<Employee>>& employees) {
    if (employees.empty()) {
        system("cls");
        std::cout << "Brak zapisanych naukowcow.\n";
        return;
    }

    std::cout << "\n========= Wszyscy naukowcy =========\n";
    char label = 'A';

    
    std::vector<size_t> instances;
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
    for (size_t i = 0; i < employees.size(); ++i) {
        std::cout << "[" << label << "] " << employees[i]->getName()
            << " " << employees[i]->getSurname() << " (" << employees[i]->getFieldNameAsString() << ")\n";
        instances.push_back(i);
        ++label;

        if (label > 'Z') {
            std::cout << "Osiagnieto limit 26 naukowcow. Reszta nie bedzie pokazana.\n";
            break;
        }
    }

    std::cout << "\nWybierz indeks, aby zobaczyc szczegoly (lub 0 aby anulowac): ";
    char choice;
    std::cin >> choice;
    choice = toupper(choice);
    system("cls");
    if (choice == '0') return;

    size_t selectedIndex = choice - 'A';
    std::cout << R"(
   _____      _            _   _     _   _           _     
  / ____|    (_)          | | (_)   | | | |         | |    
 | (___   ___ _  ___ _ __ | |_ _ ___| |_| |__  _   _| |__  
  \___ \ / __| |/ _ \ '_ \| __| / __| __| '_ \| | | | '_ \ 
  ____) | (__| |  __/ | | | |_| \__ \ |_| | | | |_| | |_) |
 |_____/ \___|_|\___|_| |_|\__|_|___/\__|_| |_|\__,_|_.__/      
-----------------------------------------------------------                                                                          
    )" << std::endl;
    if (selectedIndex < instances.size()) {
        std::cout << "\n====== Szczegoly naukowca ======\n";
        employees[instances[selectedIndex]]->show();
    }
    else {
        std::cout << "Nieprawidlowy wybor.\n";
    }
    std::cout << "\nNacisnij Enter, aby wrocic do menu glownego..."; //#FIX_ME do przetestowania
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
}