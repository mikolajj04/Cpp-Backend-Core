#include "employee.h"


Employee::Employee(const std::string& name,const std::string& surname,int age,enums:: Sex sex,enums:: Rank rank,const FieldofResearch& field)
	: name(name), surname(surname), age(age), sex(sex), rank(rank), field(field) {}

FieldofResearch::FieldofResearch(enums::FieldofResearchName fieldName, double points) 
	: fieldName(fieldName), description(getDescription()), points(points) {};

//gettery dla klasy FieldofResearch:
std::string FieldofResearch::getDescription() const {
    switch (this->fieldName) {
    case enums::FieldofResearchName::Physics:
        return "Study of matter, energy, and the fundamental forces of nature.";
    case enums::FieldofResearchName::Chemistry:
        return "Study of substances, their properties, reactions, and transformations.";
    case enums::FieldofResearchName::Biology:
        return "Study of living organisms, their structure, function, and evolution.";
    case enums::FieldofResearchName::ComputerScience:
        return "Study of computation, programming, algorithms, and data systems.";
    case enums::FieldofResearchName::Mathematics:
        return "Study of numbers, quantities, shapes, and abstract logical structures.";
    case enums::FieldofResearchName::Medicine:
        return "Study of human health, diseases, diagnostics, and treatments.";
    case enums::FieldofResearchName::Psychology:
        return "Study of human behavior, mental processes, and cognition.";
    case enums::FieldofResearchName::SocialSciences:
        return "Study of societies, human interactions, and cultural systems.";
    case enums::FieldofResearchName::Economics:
        return "Study of production, distribution, and consumption of goods and services.";
    case enums::FieldofResearchName::Astronomy:
        return "Study of celestial objects, space, and the universe as a whole.";
    case enums::FieldofResearchName::Neuroscience:
        return "Study of the nervous system, brain structure, and neural processes.";
    case enums::FieldofResearchName::Robotics:
        return "Study of intelligent machines, automation, and robot design.";
    case enums::FieldofResearchName::Geology:
        return "Study of Earth's structure, materials, and geological processes.";
    case enums::FieldofResearchName::Anthropology:
        return "Study of human societies, cultures, and biological evolution.";
    default:
        return "Unknown field of research.";
    }
}
const enums::FieldofResearchName FieldofResearch:: getFieldName() const {
    return fieldName;
}
const double FieldofResearch:: getPoints() const {
    return points;
}
std::string FieldofResearch:: getFieldNametoString() const {
    switch (this->fieldName)
    {
    case enums::FieldofResearchName::Physics:
        return "Physics";
    case enums::FieldofResearchName::Chemistry:
        return "Chemistry";
    case enums::FieldofResearchName::Biology:
        return "Biology";
    case enums::FieldofResearchName::ComputerScience:
        return "ComputerScience";
    case enums::FieldofResearchName::Mathematics:
        return "Mathematics";
    case enums::FieldofResearchName::Medicine:
        return "Medicine";
    case enums::FieldofResearchName::Psychology:
        return "Psychology";
    case enums::FieldofResearchName::SocialSciences:
        return "Social Sciences";
    case enums::FieldofResearchName::Economics:
        return "Economics";
    case enums::FieldofResearchName::Astronomy:
        return "Astronomy";
    case enums::FieldofResearchName::Neuroscience:
        return "Neuroscience";
    case enums::FieldofResearchName::Robotics:
        return "Robotics";
    case enums::FieldofResearchName::Geology:
        return "Geology";
    case enums::FieldofResearchName::Anthropology:
        return "Anthropology";
    default:
        return "Unknown";
    }
}
const  std::string Employee:: sexToString() const {
    if (getSex() == enums::Sex::Male) {
        return "Mezczyzna";
    }
    else if (getSex() == enums::Sex::Female) {
        return "Kobieta";
    }
    else {
        return "Inna";
    }
}
std::string Employee::getFieldNameAsString() const {
    return field.getFieldNametoString();
}
std::string Employee::getDescriptionAsString() const {
    return field.getDescription();
}
//gettery dla klasy Eployee:
const std::string& Employee::getName() const {
    return name;
};
const std::string& Employee::getSurname() const {
    return surname;
};
int Employee::getAge() const {
    return age;
};
enums::Sex Employee::getSex() const{
    return sex;
};
enums::Rank Employee::getRank() const {
    return rank;
};
const FieldofResearch& Employee::getFieldofresearch() const {
    return field;
};
