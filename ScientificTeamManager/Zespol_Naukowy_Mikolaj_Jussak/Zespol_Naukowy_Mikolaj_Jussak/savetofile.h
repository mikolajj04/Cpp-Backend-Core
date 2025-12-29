#pragma once
#include <fstream>
#include <vector>
#include "employee.h"

/// \brief Saves the list of employees to a file.
///
/// This function writes the data of all employees to the specified file.
/// \param employees Vector of unique pointers to Employee objects.
/// \param filename Name of the file to save data to.
void saveToFile(const std::vector<std::unique_ptr<Employee>>& employees, const std::string& filename);