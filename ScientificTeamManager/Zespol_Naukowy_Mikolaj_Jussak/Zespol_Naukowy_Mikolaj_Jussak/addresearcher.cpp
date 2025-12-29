#include "addresearcher.h"
#include "publication.h"
#include "researcherFactory.h"
#include <map>

void addResearcher(std::vector<std::unique_ptr<Employee>>& employees) {
    std::string name, surname, fieldStr, sexStr;
    int age = 0;
    enums::Rank rank;
    enums::Sex sex;
    double performanceScore = 0.0;
    int ministerialPoints = 0;
    int yearsOfExperience = 0;
    std::vector<Publication> publications;

    // ========== WYBÓR RANGI ==========
    std::cout << "\nWybierz range:\n";
    std::cout << "1. Trainee\n";
    std::cout << "2. Junior\n";
    std::cout << "3. Senior\n";
    std::cout << "Twoj wybor: ";
    int rankChoice;
    std::cin >> rankChoice;
    switch (rankChoice) {
    case 1: rank = enums::Rank::Trainee; break;
    case 2: rank = enums::Rank::Junior; break;
    case 3: rank = enums::Rank::Senior; break;
    default:
        std::cout << "Nieprawidlowa opcja.\n";
        return;
    }

    //dane do wprowadzenia
    std::cout << "Imie: "; std::cin >> name;
    std::cout << "Nazwisko: "; std::cin >> surname;
    std::cout << "Wiek: ";
    std::cin >> age;
    if (std::cin.fail() || age < 0) {
        system("cls");
        std::cout << "Wprowadz poprawny wiek!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;

    }

    std::cout << "Plec (Male/Female): "; std::cin >> sexStr;
    if (sexStr != "Male" && sexStr != "Female") {
        system("cls");
        std::cout << "Nieprawidlowa wartosc plci.\n";
        
        return;
        
    }
    sex = (sexStr == "Male") ? enums::Sex::Male : enums::Sex::Female;

       
    sex = (sexStr == "Male") ? enums::Sex::Male : enums::Sex::Female;

    std::cout << "Dziedzina naukowa (np. ComputerScience): "; std::cin >> fieldStr;
    enums::FieldofResearchName fieldName;
    try {
        static std::map<std::string, enums::FieldofResearchName> fieldMap = {
            {"Physics", enums::FieldofResearchName::Physics},
            {"Chemistry", enums::FieldofResearchName::Chemistry},
            {"Biology", enums::FieldofResearchName::Biology},
            {"ComputerScience", enums::FieldofResearchName::ComputerScience},
            {"Mathematics", enums::FieldofResearchName::Mathematics},
            {"Medicine", enums::FieldofResearchName::Medicine},
            {"Psychology", enums::FieldofResearchName::Psychology},
            {"SocialSciences", enums::FieldofResearchName::SocialSciences},
            {"Economics", enums::FieldofResearchName::Economics},
            {"Astronomy", enums::FieldofResearchName::Astronomy},
            {"Neuroscience", enums::FieldofResearchName::Neuroscience},
            {"Robotics", enums::FieldofResearchName::Robotics},
            {"Geology", enums::FieldofResearchName::Geology},
            {"Anthropology", enums::FieldofResearchName::Anthropology}
        };
        fieldName = fieldMap.at(fieldStr);
    }
    catch (...) {
        system("cls");
        std::cout << "Nieprawidlowa dziedzina.\n";
        return;
    }

    FieldofResearch field(fieldName, 0.0);

    //tylko dla trainee
    if (rank == enums::Rank::Trainee) {
        std::cout << "Punkty stazowe (performance score): ";
        std::cin >> performanceScore;
        if (std::cin.fail() || performanceScore < 0) {
            std::cout << "Bledna wartosc punktow stazowych.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

    }
    else {
        std::cout << "Punkty ministerialne: ";
        std::cin >> ministerialPoints;
        if (std::cin.fail() || ministerialPoints < 0) {
            std::cout << "Bledna wartosc punktow ministerialnych.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        std::cout << "Liczba publikacji: ";
        int pubCount;
        std::cin >> pubCount;
        if (std::cin.fail() || pubCount < 0) {
            std::cout << "Bledna liczba publikacji.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        std::cin.ignore();

        for (int i = 0; i < pubCount; ++i) {
            std::string title;
            int citations;
            std::cout << "  Tytul publikacji #" << i + 1 << ": ";
            std::getline(std::cin, title);
            std::cout << "  Liczba cytowan: ";
            std::cin >> citations;
            if (std::cin.fail() || citations < 0) {
                std::cout << "Bledna liczba cytowan.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            std::cin.ignore();
            publications.emplace_back(title, citations);
        }

        if (rank == enums::Rank::Senior) {
            std::cout << "Lata doswiadczenia: ";
            std::cin >> yearsOfExperience;
            if (std::cin.fail() || yearsOfExperience < 0) {
                std::cout << "Bledna wartosc lat doswiadczenia.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
        }
    }


        try {
            auto researcher = ResearcherFactory::createResearcher(rank, name, surname, age, sex, field,
                publications, ministerialPoints,
                performanceScore, yearsOfExperience);
            employees.push_back(std::move(researcher));
            std::cout << "Dodano nowego pracownika!\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Blad podczas tworzenia pracownika: " << e.what() << '\n';
        }
    }
