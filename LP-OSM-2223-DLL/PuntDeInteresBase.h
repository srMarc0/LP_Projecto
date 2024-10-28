#pragma once
#include "pch.h"
#include <string>
#include "Common.h"

class PuntDeInteresBase {

	private:
		Coordinate m_coord; //coordenades; latitud i longitud
		std::string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);

		virtual std::string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

};

class PuntDeInteresBotigaSolucio : PuntDeInteresBase
{
private:
	std::string m_shop, m_opening_hours, m_wheelchair;

public:
	PuntDeInteresBotigaSolucio() : m_shop(""), m_opening_hours(""), m_wheelchair("") {}
	~PuntDeInteresBotigaSolucio() {}

	std::string getName()override;
	unsigned int getColor() override;


};

class PuntDeInteresRestaurantSolucio :public PuntDeInteresBase
{
private:
	std::string m_tipusCuina, m_accesMovReduida;

public:

	PuntDeInteresRestaurantSolucio() : m_tipusCuina(""), m_accesMovReduida("") {}
	std::string getName() override;
	unsigned int getColor() override;


};