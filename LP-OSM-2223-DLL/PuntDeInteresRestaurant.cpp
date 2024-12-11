#include "pch.h"
#include "PuntDeInteresRestaurant.h"

std::string PuntDeInteresRestaurantSolucio::getName()
{
	return this->PuntDeInteresBase::getName();
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	unsigned int color = PuntDeInteresBase::getColor();
	if (m_tipusCuina == "pizza" && m_accesMovReduida == "yes")
		color = 0x03FCBA;
	else if (m_tipusCuina == "chinese")
		color = 0xA6D9F7;
	else if (m_accesMovReduida == "yes" && m_tipusCuina != "")
		color = 0x251351;

	return color;
}