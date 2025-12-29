#include <fstream>
#include <sstream>
#include <map>
#include "researcherFactory.h"
#include "loadFromFile.h"

// Bezpieczna konwersja string to int
int safeStoi(const std::string& str) {
    try {
        return std::stoi(str);
    }
    catch (const std::exception& e) {
        std::cerr << "Błąd konwersji na int: \"" << str << "\" – " << e.what() << '\n';
        return 0;
    }
}

// Bezpieczna konwersja string to double
double safeStod(const std::string& str) {
    try {
        return std::stod(str);
    }
    catch (const std::exception& e) {
        std::cerr << "Błąd konwersji na double: \"" << str << "\" – " << e.what() << '\n';
        return 0.0;
    }
}

std::vector<std::unique_ptr<Employee>> loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::unique_ptr<Employee>> employees;

    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku: " << filename << '\n';
        return employees;
    }

    std::string line;
    enums::Rank currentRank;
    std::string name, surname, genderStr, fieldStr;
    int age = 0;
    enums::Sex sex;
    double performanceScore = 0.0;
    int ministralPoints = 0;
    int yearsOfExperience = 0;
    std::vector<Publication> publications;

    auto parseField = [](const std::string& s) -> enums::FieldofResearchName {
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
        auto it = fieldMap.find(s);
        if (it != fieldMap.end()) return it->second;
        std::cerr << "Nieznana dziedzina: " << s << '\n';
        return enums::FieldofResearchName::ComputerScience; 
        };

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] == '#') {
            if (!name.empty()) {
                FieldofResearch field(parseField(fieldStr), 0.0);
                try {
                    auto emp = ResearcherFactory::createResearcher(currentRank, name, surname, age, sex, field, publications, ministralPoints, performanceScore, yearsOfExperience);
                    employees.push_back(std::move(emp));
                }
                catch (const std::exception& e) {
                    std::cerr << "Blad podczas tworzenia pracownika: " << e.what() << '\n';
                }

                // Reset danych
                name = surname = genderStr = fieldStr = "";
                age = 0;
                performanceScore = 0.0;
                ministralPoints = 0;
                yearsOfExperience = 0;
                publications.clear();
            }

            if (line == "#TRAINEE") currentRank = enums::Rank::Trainee;
            else if (line == "#JUNIOR") currentRank = enums::Rank::Junior;
            else if (line == "#SENIOR") currentRank = enums::Rank::Senior;
        }
        else if (line.rfind("Imie:", 0) == 0) {
            name = line.substr(6);
        }
        else if (line.rfind("Nazwisko:", 0) == 0) {
            surname = line.substr(10);
        }
        else if (line.rfind("Wiek:", 0) == 0) {
            std::string value = line.substr(6);
            if (!value.empty()) age = safeStoi(value);
        }
        else if (line.rfind("Plec:", 0) == 0) {
            genderStr = line.substr(6);
            sex = (genderStr == "Male") ? enums::Sex::Male : enums::Sex::Female;
        }
        else if (line.rfind("Dziedzina:", 0) == 0) {
            fieldStr = line.substr(11);
        }
        else if (line.rfind("PunktyStazowe:", 0) == 0) {
            std::string val = line.substr(16);
            if (!val.empty()) performanceScore = safeStod(val);
        }
        else if (line.rfind("PunktyMinisterialne:", 0) == 0) {
            std::string val = line.substr(22);
            if (!val.empty()) ministralPoints = safeStoi(val);
        }
        else if (line.rfind("LataDoswiadczenia:", 0) == 0) {
            std::string val = line.substr(20);
            if (!val.empty()) yearsOfExperience = safeStoi(val);
        }
        else if (line.rfind("Tytul:", 0) == 0) {
            std::string pubLine = line.substr(7);
            size_t sep = pubLine.find("|Cytowania:");
            if (sep != std::string::npos) {
                std::string title = pubLine.substr(0, sep);
                int citations = safeStoi(pubLine.substr(sep + 12));
                publications.emplace_back(title, citations);
            }
            else {
                std::cerr << "Nieprawidlowy format publikacji: " << pubLine << '\n';
            }
        }
    }

    // ostatni naukowiec- zabezpieczenie 
    if (!name.empty()) {
        FieldofResearch field(parseField(fieldStr), 0.0);
        try {
            auto emp = ResearcherFactory::createResearcher(currentRank, name, surname, age, sex, field, publications, ministralPoints, performanceScore, yearsOfExperience);
            employees.push_back(std::move(emp));
        }
        catch (const std::exception& e) {
            std::cerr << "Blad podczas tworzenia ostatniego pracownika: " << e.what() << '\n';
        }
    }

    file.close();
    return employees;
}