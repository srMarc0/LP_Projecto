#include "GrafSolucio.h"

void Graf::afegirNode(const std::string node)
{

}

Graf::Graf()
{
	m_numArestes = 2;
	m_numNodes = 1;
}

void Graf::creaMatriu(MapaBase* m)
{
	std::vector<CamiBase*> nodesYeah;
	m->getCamins(nodesYeah);

}