#include "publication.h"


Publication::Publication(std::string title, int citationCount) : title(title), citationCount(citationCount) {}

//przeciazenie op. "<<" w klasie Publication:
std::ostream& operator<<(std::ostream& os, const Publication& pub) {
	os << "Tytul: " << pub.title << "  |  " << "Ilosc cytowan: " << pub.citationCount;
	return os;
}