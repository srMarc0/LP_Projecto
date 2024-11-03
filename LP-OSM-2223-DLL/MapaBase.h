#pragma once
#include "pch.h"

#include "Common.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestautantSolucio.h"
#include "CamiSolucio.h"


class MapaBase 
{

	public:
		virtual void getPdis(std::vector<PuntDeInteresBase*> &v) = 0;
		virtual void getCamins(std::vector<CamiBase*> &v) = 0;
		virtual void parsejaXmlElements(std::vector<XmlElement>& xmlElements) = 0;
};


