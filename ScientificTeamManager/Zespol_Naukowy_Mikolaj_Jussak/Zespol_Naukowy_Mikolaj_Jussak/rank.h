#pragma once
#include "employee.h"
#include "publication.h"
#include "researcher.h"
#include <vector>
#include <algorithm>
#include <functional>

/// \brief Represents a trainee employee.
///
/// Inherits from Employee and adds a performance score.
class Trainee : public Employee {
private:
    double performanceScore; ///< Performance score of the trainee.
public:
    /// \brief Constructs a Trainee object.
    /// \param name First name.
    /// \param surname Surname.
    /// \param age Age.
    /// \param sex Sex.
    /// \param rank Rank.
    /// \param field Field of research.
    /// \param performanceScore Performance score.
    Trainee(const std::string& name, 
        const std::string& surname,
        int age, enums::Sex sex,
        enums::Rank rank,
        const FieldofResearch& field,
        double performanceScore);

    /// \brief Returns the performance score.
    double getPerformanceScore() const;

    /// \brief Displays trainee information.
    void show() const override;

    /// \brief Returns the trainee's salary.
    double getSalary() const override;
};


/// \brief Represents a junior researcher.
///
/// Inherits from Researcher.
class Junior : public Researcher {
public:
    /// \brief Constructs a Junior object.
    /// \param name First name.
    /// \param surname Surname.
    /// \param age Age.
    /// \param sex Sex.
    /// \param rank Rank.
    /// \param field Field of research.
    /// \param pub List of publications.
    /// \param ministralPoints Ministral points.
    Junior(const std::string& name,
        const std::string& surname,
        int age, enums::Sex sex,
        enums::Rank rank,
        const FieldofResearch& field,
        const std::vector<Publication>& pub,
        int ministralPoints);

    /// \brief Displays junior researcher information.
    void show() const override;

    /// \brief Returns the junior researcher's salary.
    double getSalary() const override;
};


/// \brief Represents a senior researcher.
///
/// Inherits from Researcher and adds years of experience.
class Senior : public Researcher {
private:
    int yearsofExperience; ///< Years of experience.
public:
    /// \brief Constructs a Senior object.
    /// \param name First name.
    /// \param surname Surname.
    /// \param age Age.
    /// \param sex Sex.
    /// \param rank Rank.
    /// \param field Field of research.
    /// \param pub List of publications.
    /// \param ministralPoints Ministral points.
    /// \param yearsofExperience Years of experience.
    Senior(const std::string& name,
        const std::string& surname,
        int age, enums::Sex sex,
        enums::Rank rank,
        const FieldofResearch& field,
        const std::vector<Publication>& pub,
        int ministralPoints, int yearsofExperience);

    /// \brief Returns the years of experience.
    int getYearsofExperience() const;

    /// \brief Displays senior researcher information.
    void show() const override;

    /// \brief Returns the senior researcher's salary.
    double getSalary() const override;
};
