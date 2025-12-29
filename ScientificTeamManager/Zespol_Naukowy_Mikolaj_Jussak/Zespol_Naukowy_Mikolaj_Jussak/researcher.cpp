#include "researcher.h"


Researcher::Researcher(const std::string& name,
	const std::string& surrname,
	int age, enums::Sex sex,
	enums::Rank rank,
	const FieldofResearch& field,
	const std::vector<Publication>& pub,
	int ministralPoints) :Employee(name, surrname, age, sex, rank, field), publicationsAndCitations(pub), ministralPoints(ministralPoints) {
};
void Researcher::getPublicationsAndCitations() const{
	if (publicationsAndCitations.empty()) {
		std::cout << "-Brak publikacji-\n";
		return;
	}
	std::cout << "Publikacje pracownika i ich cytowania: \n";
	int index = 1;
	for (const auto& pub : publicationsAndCitations) {
		std::cout << index << ". " << pub << '\n';
		index++;
	}
};
size_t Researcher::publicationCount() const {
	return publicationsAndCitations.size();
}
int Researcher::getHirshIndex() const {
	std::vector<int>citations;
	for (const Publication& pub : publicationsAndCitations) {
		citations.push_back(pub.citationCount);
	}
	std::sort(citations.begin(), citations.end(), std::greater<int>());

	int h = 0;
	size_t elementCount = citations.size();
	for (int i = 0; i < elementCount; i++) {
		if (citations[i] >= i + 1) {
			h = i + 1;
		}
		else {
			break;
		}
	}
	return h;
}
int Researcher::getMinistralPoints() const {
	return ministralPoints;
}


const std::vector<Publication>& Researcher::getPublications() const {
	return publicationsAndCitations;
}