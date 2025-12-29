#pragma once
#include <iostream>
#include <vector>
#include "enums.h"
#include "employee.h"

/// \brief Displays employees filtered by a given criterion.
///
/// This function lists employees matching the provided filter (e.g., rank),
/// allows the user to select one, and then displays detailed information.
/// \tparam T Type of filter (default: enums::Rank).
/// \param employees Vector of unique pointers to Employee objects.
/// \param filter Value to filter employees by.
template<typename T = enums::Rank>
void showFiltered(const std::vector<std::unique_ptr<Employee>>& employees, T filter) {
    std::vector<size_t> instances;
    char label = 'A';
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
        if (employees[i]->getRank() == filter) {
            std::cout << "[" << label << "] " << employees[i]->getName() << " " << employees[i]->getSurname() << '\n';
            instances.push_back(i);
            ++label;
        }
    }

    if (instances.empty()) {
        system("cls");
        std::cout << "Brak naukowcow tej rangi.\n";
        return;
    }

    std::cout << "Wybierz indeks, aby pokazac szczegoly: ";
    char choice;
    std::cin >> choice;
    choice = toupper(choice);
    system("cls");

    size_t index = choice - 'A';
    if (index < instances.size()) {
        std::cout << R"(
   _____      _            _   _     _   _           _     
  / ____|    (_)          | | (_)   | | | |         | |    
 | (___   ___ _  ___ _ __ | |_ _ ___| |_| |__  _   _| |__  
  \___ \ / __| |/ _ \ '_ \| __| / __| __| '_ \| | | | '_ \ 
  ____) | (__| |  __/ | | | |_| \__ \ |_| | | | |_| | |_) |
 |_____/ \___|_|\___|_| |_|\__|_|___/\__|_| |_|\__,_|_.__/ 
------------------------------------------------------------                                                                               
    )" << std::endl;
        employees[instances[index]]->show();
    }
    else {
        std::cout << "Nieprawidlowy wybor.\n";
    }
    std::cout << "\nNacisnij Enter, aby wrocic do menu glownego..."; //#FIX_ME do przetestowania
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
}