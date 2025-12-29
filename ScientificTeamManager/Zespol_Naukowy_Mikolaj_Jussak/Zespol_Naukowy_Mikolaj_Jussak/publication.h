#include <iostream>
#pragma once

/// \brief Represents a scientific publication.
///
/// This class stores information about a publication, including its title and citation count.
class Publication {
public:
    std::string title;        ///< Title of the publication.
    int citationCount;        ///< Number of citations.

    /// \brief Constructs a Publication object.
    /// \param title Title of the publication.
    /// \param citationCount Number of citations.
    Publication(std::string title, int citationCount);

    /// \brief Outputs publication details to the given output stream.
    /// \param os Output stream.
    /// \param pub Publication to output.
    /// \return Reference to the output stream.
    friend std::ostream& operator<<(std::ostream& os, const Publication& pub);
};