#pragma once
#include "pch.h"

#include "Common.h"
#include "PuntDeInteresBase.h"
#include "CamiBase.h"
#include "PuntDeInteresBotiga.h"
#include "PuntDeInteresRestaurant.h"
#include "CamiSolucio.h"


class MapaBase {

	public:
		virtual void getPdis(std::vector<PuntDeInteresBase*>&) = 0;
		virtual void getCamins(std::vector<CamiBase*>&) = 0;
		virtual void parsejaXmlElements(std::vector<XmlElement>& xmlElements) = 0;

		virtual CamiBase* buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a) = 0;
};



