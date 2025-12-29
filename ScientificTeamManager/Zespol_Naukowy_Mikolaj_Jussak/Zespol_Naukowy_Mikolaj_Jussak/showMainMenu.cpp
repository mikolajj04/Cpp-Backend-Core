#include <iostream>

void showMainMenu() {
    std::cout << R"(
   _____      _            _   _     _   _           _     
  / ____|    (_)          | | (_)   | | | |         | |    
 | (___   ___ _  ___ _ __ | |_ _ ___| |_| |__  _   _| |__  
  \___ \ / __| |/ _ \ '_ \| __| / __| __| '_ \| | | | '_ \ 
  ____) | (__| |  __/ | | | |_| \__ \ |_| | | | |_| | |_) |
 |_____/ \___|_|\___|_| |_|\__|_|___/\__|_| |_|\__,_|_.__/      
-----------------------------------------------------------                                                                          
    )" << std::endl;
    std::cout << "================ MENU ================\n";
    std::cout << "1 - Pokaz tylko Seniorow\n";
    std::cout << "2 - Pokaz tylko Juniorow\n";
    std::cout << "3 - Pokaz tylko Stazystow\n";
    std::cout << "4 - Pokaz wszystkich\n";
    std::cout << "A - Dodaj naukowca\n";
    std::cout << "D - Usun naukowca\n";
    std::cout << "$ - Pokaz kalkulator wynagrodzen\n";
    std::cout << "Q - Zakoncz i zapisz\n";
    std::cout << "======================================\n";
    std::cout << "Wybor: ";
}