#include <iostream>
#include "salarycalc.h"

void showSalaryCalc() {
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

	std::cout << "Wynagrodzenie dla stazysty: 3000 + ((1000 * <punkty stazysty>) / 100)\n";
	std::cout << "---------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Wynagrodzenie dla juniora: 5500 + ((1000 * <indeks Hirsh'a>) / 10) + (1 * <punkty ministerialne>)\n";
	std::cout << "---------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Wynagrodzenie dla seniora: 2000 * <indeks Hirsh'a>) / 10) + (2 * <punkty ministerialne> + 100 * <lata doswiadczenia>)\n";
	std::cout << "---------------------------------------------------------------------------------------------------------------------\n";

	std::cout << "\nNacisnij Enter, aby wrocic do menu glownego..."; //#FIX_ME do przetestowania
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("cls");




}