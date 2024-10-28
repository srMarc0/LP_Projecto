#pragma once
#include "pch.h"

#include "Common.h"
#include "PuntDeInteresBase.h"
#include "CamiBase.h"


class MapaBase {

	public:
		virtual void getPdis(std::vector<PuntDeInteresBase*>&) = 0;
		virtual void getCamins(std::vector<CamiBase*>&) = 0;
		virtual void parsejaXmlElements(std::vector<XmlElement>& xmlElements) = 0;

};

class MapaSolucio : public MapaBase
{
private:

public:
	void getPdis(std::vector<PuntDeInteresBase*>&) override {}
	void getCamins(std::vector<CamiBase*>&) override {}
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override {}
};



