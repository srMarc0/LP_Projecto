#pragma once
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
//#include "CamiSolucio.h"
#include "MapaBase.h" //en comtes de #include "MapaSolucio.h" 
#include "Util.h"



class Graf
{
private:
	size_t m_numNodes;
	size_t m_numArestes;
	std::vector<Coordinate> m_nodes; //Guardem tots els nodes, que son Coordenades
	// ver como hacer la matriz que agrupe todos los nodos
	std::vector<std::vector<size_t>> m_matriuAdj;// matriu de coordenades

	std::vector<std::pair<Coordinate, Coordinate>> m_arestes; // per fer la conexions de arestes
	std::vector<double> m_pesos;

public:
	Graf();
	~Graf(){}
	void creaMatriu(MapaBase* m);
	size_t getNumNodes()const { return m_numNodes; }
	size_t getNumArestes()const { return m_numArestes;  }
	//void creaMatriu(CamiSolucio* c);
	void afegirNode(const Coordinate& node);

	void afegirAresta(const Coordinate& node1, const Coordinate& node2);
};





