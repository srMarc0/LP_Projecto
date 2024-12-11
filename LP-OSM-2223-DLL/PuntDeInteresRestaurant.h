#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio :public PuntDeInteresBase
{
private:
	std::string m_tipusCuina, m_accesMovReduida, m_amenity, m_id;

public:

	PuntDeInteresRestaurantSolucio() : m_tipusCuina(""), m_accesMovReduida(""), m_id(""), m_amenity("") {}
	PuntDeInteresRestaurantSolucio(Coordinate& c, std::string name, std::string id, std::string tipusCuina, std::string acces, std::string amenity)
		: PuntDeInteresBase(c, name), m_id(id), m_tipusCuina(tipusCuina), m_accesMovReduida(acces), m_amenity(amenity) {}

	std::string getName() override;
	unsigned int getColor() override;
};