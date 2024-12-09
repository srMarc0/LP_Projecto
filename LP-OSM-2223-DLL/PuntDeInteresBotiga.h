#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
private:
	std::string m_shop, m_opening_hours, m_wheelchair, m_id;

public:
	PuntDeInteresBotigaSolucio() : m_shop(""), m_opening_hours(""), m_wheelchair(""), m_id("") {}
	PuntDeInteresBotigaSolucio(Coordinate& c, std::string name, std::string id, std::string shop, std::string open, std::string wheel)
		: PuntDeInteresBase(c, name), m_id(id), m_shop(shop), m_opening_hours(open), m_wheelchair(wheel) {}
	~PuntDeInteresBotigaSolucio() {}

	std::string getName()override;
	unsigned int getColor() override;
};