#include "GrafSolucio.h"


Graf::Graf()
{
	m_numArestes = 0;
	m_numNodes = 0;

	m_nodes.resize(0);
	m_arestes.resize(0);
	m_matriuAdj.resize(0);

	m_pesos.resize(0);
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
	
	//guardem les arestes
	for (size_t i = 0; i < camins.size(); i++)//iterem dintre el vector que conte camins
	{
		for (size_t j = 0; j < camins[i]->getNCoords() - 1; j++)//iterem els nodes dels camins	
		{
			std::pair<Coordinate, Coordinate> duplaCoor(camins[i]->getCamiCoords()[j], camins[i]->getCamiCoords()[j + 1]);
			m_arestes.emplace_back(duplaCoor);
		}
		
	}
	m_numArestes = m_arestes.size();
	
	for (size_t i = 0; i < m_numArestes; i++)
	{
		Util u;
		m_pesos.emplace_back(u.DistanciaHaversine(m_arestes[i].first, m_arestes[i].second));
	}
	int hola = 0;

	/*
	//fem la matriu
	m_matriuAdj.resize(m_numNodes);
	for (auto& it : m_matriuAdj)
	{
		it.resize(m_numNodes);
	}

	
	for (size_t i = 0; i < m_numArestes; i++)
	{
		Util u;
		auto itRow = std::find(m_nodes.begin(), m_nodes.end(), m_arestes[i].first);
		auto itCol = std::find(m_nodes.begin(), m_nodes.end(), m_arestes[i].second); 
		
		if (itRow != m_nodes.end() && itCol != m_nodes.end())
		{
			size_t indexRow = std::distance(m_nodes.begin(), itRow);
			size_t indexCol = std::distance(m_nodes.begin(), itCol);
			m_matriuAdj[indexRow][indexCol] = 1;//u.DistanciaHaversine(m_arestes[i].first, m_arestes[i].second);
		}
	}
	*/
	


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
void Graf::afegirNode(const Coordinate& node)
{
	m_nodes.emplace_back(node);
	m_numNodes++;
}

void Graf::afegirAresta(const Coordinate& node1, const Coordinate& node2)
{
	std::pair<Coordinate, Coordinate> p(node1, node2);
	m_arestes.emplace_back(p);
	m_numArestes++;
}