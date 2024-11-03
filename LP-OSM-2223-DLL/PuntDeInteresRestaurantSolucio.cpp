#include "pch.h"
#include "PuntDeInteresRestautantSolucio.h"

std::string PuntDeInteresRestaurantSolucio::getName()
{
	return this->getName();
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	unsigned int color = 0xEFD6AC;
	if (m_tipusCuina == "pizza" && m_accesMovReduida == "yes")
		color = 0x03FCBA;
	else if (m_tipusCuina == "chinese")
		color = 0xA6D9F7;
	else if (m_accesMovReduida == "yes")
		color = 0x251351;

	return color;
}