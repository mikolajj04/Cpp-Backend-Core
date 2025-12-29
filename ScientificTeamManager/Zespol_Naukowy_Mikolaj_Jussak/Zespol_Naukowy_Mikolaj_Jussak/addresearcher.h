#pragma once
#include "employee.h"
#include <vector>
#include <iostream>

/// \brief Adds a new researcher to the employees collection.
///
/// This function prompts the user for researcher details and creates a new
/// Employee-derived object, which is then added to the provided vector.
/// \param employees Reference to a vector of unique pointers to Employee objects.
void addResearcher(std::vector<std::unique_ptr<Employee>>& employees);