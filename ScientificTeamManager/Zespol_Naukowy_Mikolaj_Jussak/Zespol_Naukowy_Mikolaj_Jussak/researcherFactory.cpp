#include "researcherFactory.h"
#include <stdexcept>

std::unique_ptr<Employee> ResearcherFactory::createResearcher(
    enums::Rank rank,
    const std::string& name,
    const std::string& surname,
    int age,
    enums::Sex sex,
    const FieldofResearch& field,
    const std::vector<Publication>& publications,
    int ministerialPoints,
    double performanceScore,
    int yearsOfExperience
) {
    switch (rank) {
    case enums::Rank::Trainee:
        return std::make_unique<Trainee>(name, surname, age, sex, rank, field, performanceScore);

    case enums::Rank::Junior:
        return std::make_unique<Junior>(name, surname, age, sex, rank, field, publications, ministerialPoints);

    case enums::Rank::Senior:
        return std::make_unique<Senior>(name, surname, age, sex, rank, field, publications, ministerialPoints, yearsOfExperience);

    default:
        throw std::invalid_argument("Invalid researcher rank.");
    }
}