#pragma once
#include <vector>
#include <string>
#include <utility>
//#include "CamiSolucio.h"
#include "MapaBase.h" //en comtes de #include "MapaSolucio.h" 
#include <unordered_map>
#include "Util.h"



class Graf
{
private:
	size_t m_numNodes;
	size_t m_numArestes;
	std::vector<Coordinate> m_nodes; //Guardem tots els nodes, que son Coordenades
	// ver como hacer la matriz que agrupe todos los nodos
	std::vector<std::pair<Coordinate, Coordinate>> m_matriuAdj;// han de ser les coordenades¿?

public:
	Graf();
	~Graf(){}
	void creaMatriu(MapaBase* m);
	size_t getNumNodes()const { return m_numNodes; }
	size_t getNumArestes()const { return m_numArestes;  }
	//void creaMatriu(CamiSolucio* c);

	void afegirNode(const std::string node);
	void eliminaNode(const std::string& node) {  }

	void afegirAresta() {  }
};



