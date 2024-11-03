#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
private:
	std::string m_shop, m_opening_hours, m_wheelchair;

public:
	PuntDeInteresBotigaSolucio() : m_shop(""), m_opening_hours(""), m_wheelchair("") {}
	PuntDeInteresBotigaSolucio(Coordinate& c, std::string name, std::string shop)
		: PuntDeInteresBase(c, name), m_shop(shop) {}
	~PuntDeInteresBotigaSolucio() {}

	std::string getName()override;
	unsigned int getColor() override;

};