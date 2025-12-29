#include "savetofile.h"
#include "researcherFactory.h"
#include "researcher.h"


void saveToFile(const std::vector<std::unique_ptr<Employee>>& employees, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << filename << '\n';
        return;
    }

    for (const auto& emp : employees) {
        enums::Rank rank = emp->getRank();
        switch (rank) {
        case enums::Rank::Trainee:
            file << "#TRAINEE\n";
            break;
        case enums::Rank::Junior:
            file << "#JUNIOR\n";
            break;
        case enums::Rank::Senior:
            file << "#SENIOR\n";
            break;
        default:
            std::cerr << "Nieznany typ rangi!\n";
            continue; 
    }


        file << "Imie: " << emp->getName() << '\n';
        file << "Nazwisko: " << emp->getSurname() << '\n';
        file << "Wiek: " << emp->getAge() << '\n';
        file << "Plec: " << (emp->getSex() == enums::Sex::Male ? "Male" : "Female") << '\n';
        file << "Dziedzina: " << emp->getFieldNameAsString() << '\n';

        if (rank == enums::Rank::Trainee) {
            const Trainee* t = dynamic_cast<const Trainee*>(emp.get());
            if (t) {
                file << "PunktyStazowe: " << t->getPerformanceScore() << '\n';
            }
        }

        if (rank == enums::Rank::Junior || rank == enums::Rank::Senior) {
            const Researcher* r = dynamic_cast<const Researcher*>(emp.get());
            if (r) {
                file << "PunktyMinisterialne: " << r->getMinistralPoints() << '\n';

                if (rank == enums::Rank::Senior) {
                    const Senior* s = dynamic_cast<const Senior*>(emp.get());
                    if (s) {
                        file << "LataDoswiadczenia: " << s->getYearsofExperience() << '\n';
                    }
                }

                std::vector<Publication> pubs;
                if (const Junior* j = dynamic_cast<const Junior*>(r)) {
                    pubs = j->getPublications(); 
                }
                else if (const Senior* s = dynamic_cast<const Senior*>(r)) {
                    pubs = s->getPublications(); 
                }
                if (!pubs.empty()) {
                    file << "Publikacje:\n";
                    for (const auto& pub : pubs) {
                        file << "Tytul: " << pub.title << "|Cytowania: " << pub.citationCount << '\n';
                    }
                }
            }
        }

        file << '\n'; 
    }

    std::cout << "Dane zapisane w formacie czytelnym do pliku: " << filename << '\n';
}