#pragma once
#include <vector>
#include <string>
#include <utility>
//#include "CamiSolucio.h"
#include "MapaSolucio.h"
#include <unordered_map>
#include "Util.h"



class Graf
{
private:
	size_t m_numNodes;
	size_t m_numArestes;
	std::vector<std::string> m_nodes; //Guardem tots els nodes
	// ver como hacer la matriz que agrupe todos los nodos
	std::vector<std::pair<size_t, size_t>> m_matriuAdj;

public:
	Graf();
	~Graf(){}
	void creaMatriu(MapaBase* m);
	size_t getNumNodes()const { return m_numNodes; }
	size_t getNumArestes()const { return m_numArestes;  }


	void afegirNode(const std::string node);
	void eliminaNode(const std::string& node) {  }

	void afegirAresta() {  }
};



