#include <iostream>
#include <vector>
#include <string>
#include "ResearcherFactory.h" 
#include "showMainMenu.h"
#include "showFiltered.h"
#include "loadFromFile.h"
#include "showall.h"
#include "addresearcher.h"
#include "deleteresearcher.h"
#include "savetofile.h"
#include "salarycalc.h" 


int main() {
	std::vector<std::unique_ptr<Employee>> employees = loadFromFile("dane.txt");
	bool running = true;
	while (running) {
		showMainMenu();
		char choice;
		std::cin >> choice;
		switch (toupper(choice)) {
		case '1': showFiltered(employees, enums::Rank::Senior); break;
		case '2': showFiltered(employees, enums::Rank::Junior); break;
		case '3': showFiltered(employees, enums::Rank::Trainee); break;
		case '4': showAll(employees); break;
		case 'A': addResearcher(employees); break;
		case 'D': deleteResearcher(employees); break;
		case '$': showSalaryCalc(); break;
		case 'Q': running = false; break;
		default: system("cls");  std::cout << "Nieznana opcja.\n"; break;
		} 
	}

	saveToFile(employees, "dane.txt");
		return 0;

}