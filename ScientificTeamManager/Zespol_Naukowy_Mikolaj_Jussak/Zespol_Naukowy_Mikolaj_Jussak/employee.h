#pragma once
#include <iostream>
#include <string>
#include "enums.h"

/// \brief Represents a scientific field of research.
///
/// This class stores information about the research field, including its name,
/// description, and associated points.
class FieldofResearch { //#INFO klasa zamknieta 
private:     
   enums::FieldofResearchName fieldName;       
   std::string description;
   double points;
public:
    /// \brief Constructs a FieldofResearch object.
    /// \param fieldName Name of the research field.
    /// \param points Points associated with the field.
    FieldofResearch(enums::FieldofResearchName fieldName, double points);

    /// \brief Returns the description of the research field.
    std::string getDescription() const;

    /// \brief Returns the name of the research field as an enum.
    const enums::FieldofResearchName getFieldName() const;

    /// \brief Returns the points associated with the research field.
    const double getPoints() const;

    /// \brief Returns the name of the research field as a string.
    std::string getFieldNametoString() const;
};


/// \brief Abstract base class representing an employee.
///
/// This class defines the common interface and properties for all employees.
class Employee { //#INFO klasa zakmnieta
private:
    std::string name;
    std::string surname;
    int age;
    enums::Sex sex;
    enums::Rank rank;
    FieldofResearch field; 

public:
    /// \brief Constructs an Employee object.
    /// \param name Employee's first name.
    /// \param surname Employee's surname.
    /// \param age Employee's age.
    /// \param sex Employee's sex.
    /// \param rank Employee's rank.
    /// \param field Employee's field of research.
    Employee(const std::string& name, const std::string& surname, int age, enums::Sex sex, enums::Rank rank, const FieldofResearch& field);

    /// \brief Displays employee information (pure virtual).
    virtual void show() const = 0;

    /// \brief Returns the employee's salary (pure virtual).
    virtual double getSalary() const = 0;

    /// \brief Virtual destructor.
    virtual ~Employee() = default;

    /// \brief Returns the employee's first name.
    const std::string& getName() const;

    /// \brief Returns the employee's surname.
    const std::string& getSurname() const;

    /// \brief Returns the employee's age.
    int getAge() const;

    /// \brief Returns the employee's sex.
    enums::Sex getSex() const;

    /// \brief Returns the employee's rank.
    enums::Rank getRank() const;

    /// \brief Returns the employee's field of research.
    const FieldofResearch& getFieldofresearch() const;

    /// \brief Returns the employee's sex as a string.
    const std::string sexToString() const;

    /// \brief Returns the employee's field name as a string.
    std::string getFieldNameAsString() const;

    /// \brief Returns the employee's field description as a string.
    std::string getDescriptionAsString() const;
};
