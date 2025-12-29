#pragma once
#include <fstream>
#include <sstream>
#include <map>
#include "researcherFactory.h"

/// \brief Loads employees from a file.
///
/// This function reads employee data from the specified file and creates
/// a vector of unique pointers to Employee objects.
/// \param filename Name of the file to load data from.
/// \return Vector of unique pointers to Employee objects.
std::vector<std::unique_ptr<Employee>> loadFromFile(const std::string& filename);