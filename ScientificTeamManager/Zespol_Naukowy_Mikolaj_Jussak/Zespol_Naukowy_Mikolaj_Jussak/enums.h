#pragma once
/// \file
/// \brief Contains enumerations used in the scientific team application.

namespace enums {

/// \brief Enumeration for sex.
enum class Sex {
    Male,   ///< Male sex.
    Female  ///< Female sex.
};

/// \brief Enumeration for academic rank.
enum class Rank {
    Trainee, ///< Trainee rank.
    Junior,  ///< Junior rank.
    Senior   ///< Senior rank.
};

/// \brief Enumeration for field of research names.
enum class FieldofResearchName {
    Physics,          ///< Physics.
    Chemistry,        ///< Chemistry.
    Biology,          ///< Biology.
    ComputerScience,  ///< Computer Science.
    Mathematics,      ///< Mathematics.
    Medicine,         ///< Medicine.
    Psychology,       ///< Psychology.
    SocialSciences,   ///< Social Sciences.
    Economics,        ///< Economics.
    Astronomy,        ///< Astronomy.
    Neuroscience,     ///< Neuroscience.
    Robotics,         ///< Robotics.
    Geology,          ///< Geology.
    Anthropology      ///< Anthropology.
};

};