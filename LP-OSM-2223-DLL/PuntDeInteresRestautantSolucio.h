#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio :public PuntDeInteresBase
{
private:
	std::string m_tipusCuina, m_accesMovReduida, m_amenity;

public:

	PuntDeInteresRestaurantSolucio() : m_tipusCuina(""), m_accesMovReduida(""), m_amenity("") {}
	PuntDeInteresRestaurantSolucio(Coordinate& c, std::string name, std::string tipusCuina, std::string acces)
		: PuntDeInteresBase(c, name), m_tipusCuina(tipusCuina), m_accesMovReduida (acces){}
	std::string getName() override;
	unsigned int getColor() override;

};