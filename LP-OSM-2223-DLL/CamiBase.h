#pragma once
#include "pch.h"

#include "Common.h"
#include <vector>

class CamiBase {
public:
		virtual std::vector<Coordinate> getCamiCoords() = 0;
		virtual void setCamiCoords(const std::vector<Coordinate>& c) = 0;
private:
	
};

class CamiSolucio : public CamiBase
{
private:
	std::vector<Coordinate> m_camiCoords;
public:
	CamiSolucio(){}
	~CamiSolucio(){}
	/*
	void afegeixCoords();
	void mostrarCoords();
	*/
	std::vector<Coordinate>getCamiCoords() override {return m_camiCoords;}
	void setCamiCoords(const std::vector<Coordinate>& c) override{}
};
/*
void CamiSolucio::afegeixCoords()
{
	Coordinate c;
	c.lat = 41.4928803;
	c.lon = 2.1452381;
	m_camiCoords.push_back(c);
}
void CamiSolucio::mostrarCoords()
{
	for (auto it = m_camiCoords.begin(); it != m_camiCoords.end(); it++)
		std::cout << "Lat : " << it->lat << " y Lon: " << it->lon << std::endl;
}
*/
