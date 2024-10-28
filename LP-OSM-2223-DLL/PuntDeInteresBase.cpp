#include "pch.h"
#include "PuntDeInteresBase.h"


PuntDeInteresBase::PuntDeInteresBase() {
	this->m_coord = Coordinate{ 0.0, 0.0 };
	this->m_name = "undefinit";
}

PuntDeInteresBase::PuntDeInteresBase(Coordinate coord, std::string name) {
	this->m_name = name;
	this->m_coord = coord;
}

Coordinate PuntDeInteresBase::getCoord() {
	return this->m_coord;
}

std::string PuntDeInteresBase::getName() {
	return this->m_name;
}

unsigned int PuntDeInteresBase::getColor() {
	return 0xFFA500;
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
	unsigned int color = 0xEFD6AC;

	if (m_shop == "supermarket")
		color = 0xA5BE00;
	else if (m_shop == "tobacco")
		color = 0xFFAD69;
	else if (m_shop == "bakery")
	{
		if (m_opening_hours == "06:00-22:00" && m_wheelchair == "yes")
			color = 0x4CD944;
		else
			color = 0xE85D75;
	}

	return color;
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