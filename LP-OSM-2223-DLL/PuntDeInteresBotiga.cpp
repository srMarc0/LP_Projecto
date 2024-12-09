#include "pch.h"
#include "PuntDeInteresBotiga.h"

std::string PuntDeInteresBotigaSolucio::getName()
{
	return this->PuntDeInteresBase::getName();
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
		if (m_opening_hours.find("06:00-22:00") != std::string::npos && m_wheelchair == "yes")
			color = 0x4CB944;
		else
			color = 0xE85D75;
	}

	return color;
}