#pragma once
#include "employee.h"
#include <cctype> 
#include <vector>
#include <memory>

/// \brief Displays information about all employees.
///
/// This function iterates through the vector of employees and displays their details.
/// \param employees Vector of unique pointers to Employee objects.
void showAll(const std::vector<std::unique_ptr<Employee>>& employees);
