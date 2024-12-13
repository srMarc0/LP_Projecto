#include "GrafSolucio.h"


Graf::Graf()
{
	m_numArestes = 0;
	m_numNodes = 0;

	m_nodes.resize(0);
	m_matriuAdj.resize(0);
}

void Graf::creaMatriu(MapaBase* m)
{

	std::vector<CamiBase*> camins;
	m->getCamins(camins);

	//porro intocable////////////////////////////////////////////////////////////////////
	size_t cont = 0;

	for (auto it = camins.begin(); it != camins.end(); it++)
	{
		cont += (*it)->getNCoords();
	}
	std::unordered_map<std::string, Coordinate> comprovaReps;
	comprovaReps.reserve(cont);
	for (auto it = camins.begin(); it != camins.end(); it++)
	{
		std::vector<Coordinate>* camiActualCoords = (*it)->getCamiCoordsPtr();
		std::vector<std::string>* camiActualIDs = (*it)->getIDPtr();
		
		auto itID = camiActualIDs->begin();
		for (auto itNode = camiActualCoords->begin(); itNode != camiActualCoords->end() && itID != camiActualIDs->end(); itNode++, itID++)
		{
			auto nodeComprovat = comprovaReps.insert({ (*itID), (*itNode) });
		
			if (nodeComprovat.second)
			{
				m_nodes.emplace_back((*itNode));
			}
		}
	}
	m_numNodes = m_nodes.size();
	//porro intocable////////////////////////////////////////////////////////////////////

	for (size_t i = 0; i < camins.size(); i++)
	{

	}






	//for (size_t i = 0; i < camins.size(); i++)
	//{
	//	for (size_t j = 0; j < (*camins[i]).getNCoords(); j++)
	//	{
	//		//auto nodeComprovat = comprovaReps.insert({ camins[i].getCamiCoords() });
	//		//std::pair<auto, Coordinate>::iterator, bool> nodeComprovat = comprovaReps.insert(camins[i][j]);
	//	}
	//}

}
/*
void Graf::creaMatriu(CamiSolucio* c)
{
	std::vector<Coordinate> nodes;
	c->getCamiCoords();
	int hola = 0;
}
*/
void Graf::afegirNode(const std::string node)
{

}