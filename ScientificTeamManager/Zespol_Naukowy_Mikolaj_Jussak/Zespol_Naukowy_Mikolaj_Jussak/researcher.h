#pragma once
#include "employee.h"
#include "enums.h"
#include "publication.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/// \brief Represents a researcher employee.
///
/// Inherits from Employee and adds publications and ministral points.
class Researcher : public Employee {
protected:
    int ministralPoints; ///< Ministral points of the researcher.
    std::vector<Publication> publicationsAndCitations; ///< List of publications and their citation counts.

public:
    /// \brief Displays the researcher's publications and citations.
    void getPublicationsAndCitations() const;

    /// \brief Returns the number of publications.
    size_t publicationCount() const;

    /// \brief Calculates and returns the Hirsch index (h-index).
    int getHirshIndex() const;

    /// \brief Returns the ministral points.
    int getMinistralPoints() const;

    /// \brief Returns a const reference to the list of publications.
    const std::vector<Publication>& getPublications() const;

    /// \brief Constructs a Researcher object.
    /// \param name First name.
    /// \param surrname Surname.
    /// \param age Age.
    /// \param sex Sex.
    /// \param rank Rank.
    /// \param field Field of research.
    /// \param pub List of publications.
    /// \param ministralPoints Ministral points.
    Researcher(const std::string& name,
        const std::string& surrname,
        int age, enums::Sex sex,
        enums::Rank rank,
        const FieldofResearch& field,
        const std::vector<Publication>& pub,
        int ministralPoints);
};