#pragma once
#include "employee.h"
#include "rank.h"
#include <memory>
#include <vector>

/// \brief Factory class for creating researcher objects.
///
/// Provides a static method to create different types of Employee-derived researchers
/// based on the given parameters.
class ResearcherFactory {
public:
    /// \brief Creates a researcher object based on the specified rank and parameters.
    ///
    /// Depending on the rank, this method creates and returns a unique pointer to the appropriate
    /// Employee-derived object (e.g., Trainee, Junior, Senior).
    /// \param rank Researcher's rank.
    /// \param name First name.
    /// \param surname Surname.
    /// \param age Age.
    /// \param sex Sex.
    /// \param field Field of research.
    /// \param publications List of publications (default: empty).
    /// \param ministerialPoints Ministerial points (default: 0).
    /// \param performanceScore Performance score (default: 0.0).
    /// \param yearsOfExperience Years of experience (default: 0).
    /// \return Unique pointer to the created Employee object.
    static std::unique_ptr<Employee> createResearcher(
        enums::Rank rank,
        const std::string& name,
        const std::string& surname,
        int age,
        enums::Sex sex,
        const FieldofResearch& field,
        const std::vector<Publication>& publications = {},
        int ministerialPoints = 0,
        double performanceScore = 0.0,
        int yearsOfExperience = 0
    );
};