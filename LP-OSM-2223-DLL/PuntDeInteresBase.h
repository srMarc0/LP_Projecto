#pragma once
#include "pch.h"
#include <string>
#include "Common.h"

class PuntDeInteresBase 
{

	private:
		Coordinate m_coord; //coordenades; latitud i longitud
		std::string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);

		virtual std::string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

		//virtual PuntDeInteresBase* clone() = 0;

};