#pragma once
#include <cctype> 
#include <memory>
#include <vector>
#include "employee.h"

/// \brief Removes a researcher from the employees collection.
///
/// This function allows the user to select and remove a researcher
/// from the provided vector of Employee objects.
/// \param employees Reference to a vector of unique pointers to Employee objects.
void deleteResearcher(std::vector<std::unique_ptr<Employee>>& employees);
