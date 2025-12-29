#include "rank.h"




Trainee::Trainee(const std::string& name,
	const std::string& surname,
	int age, enums::Sex sex,
	enums::Rank rank,
	const FieldofResearch& field,
	double performanceScore) :Employee(name, surname, age, sex, rank, field),
	performanceScore(performanceScore) {};

double Trainee::getPerformanceScore()const{
	return performanceScore;


}
void Trainee::show() const {
	std::cout << "Imie: " << getName() << '\n';
	std::cout << "Nazwisko: " << getSurname() << '\n';
	std::cout << "Status/Stopien: Stazysta\n";
	std::cout << "Plec: " << sexToString() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	std::cout << "Dziedzina badawcza: " << getFieldNameAsString() << " ~ " << getDescriptionAsString() << '\n';
	std::cout << "Punkty stazowe: " << getPerformanceScore() << '\n';
	std::cout << "Wynagrodzenie (*patrz kalkulator wynagrodzen): " << getSalary() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';

}

double Trainee:: getSalary()const {
	return 3000 + ((1000 * performanceScore) / 100);
}
	



Junior::Junior(const std::string& name,
	const std::string& surname,
	int age, enums::Sex sex,
	enums::Rank rank,
	const FieldofResearch& field,
	const std::vector<Publication>& pub,
	int ministralPoints) :
	Researcher(name, surname, age, sex, rank, field, pub, ministralPoints) {
};
void Junior::show() const {
	std::cout << "Imie: " << getName() << '\n';
	std::cout << "Nazwisko: " << getSurname() << '\n';
	std::cout << "Status/Stopien: Junior\n";
	std::cout << "Plec: " << sexToString() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	std::cout << "Dziedzina badawcza: " << getFieldNameAsString() << " ~ " << getDescriptionAsString() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	getPublicationsAndCitations();
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	std::cout << "Indeks Hirsh'a: " << getHirshIndex() << '\n';
	std::cout << "Punkty ministerialne: " << getMinistralPoints() << '\n';
	std::cout << "Wynagrodzenie (*patrz kalkulator wynagrodzen): " << getSalary() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
}

double Junior::getSalary()const {
	return 5500 + ((1000 * getHirshIndex()) / 10) + 1 * ministralPoints;
}


Senior::Senior(const std::string& name,
	const std::string& surname,
	int age, enums::Sex sex,
	enums::Rank rank,
	const FieldofResearch& field,
	const std::vector<Publication>& pub,
	int ministralPoints, int yearsofExperience) :
	Researcher(name, surname, age, sex, rank, field, pub, ministralPoints),
	yearsofExperience(yearsofExperience) {
};

int Senior::getYearsofExperience() const{
	return yearsofExperience;
};


void Senior::show() const {
	std::cout << "Imie: " << getName() << '\n';
	std::cout << "Nazwisko: " << getSurname() << '\n';
	std::cout << "Status/Stopien: Senior\n";
	std::cout << "Plec: " << sexToString() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	std::cout << "Dziedzina badawcza: " << getFieldNameAsString() << " ~ " << getDescriptionAsString() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	getPublicationsAndCitations();
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';
	std::cout << "Indeks Hirsh'a: " << getHirshIndex() << '\n';
	std::cout << "Punkty ministerialne: " << getMinistralPoints() << '\n';
	std::cout << "Lata doswiadczenia seniorskiego: " << getYearsofExperience()<< '\n';
	std::cout << "Wynagrodzenie (*patrz kalkulator wynagrodzen): " << getSalary() << '\n';
	std::cout << "--------------------------------------------------------------------------------------------------------------" << '\n';


}

double Senior::getSalary()const {
	return 5800 + ((2000 * getHirshIndex()) / 10) + 2 * ministralPoints + 100 * getYearsofExperience();
}
