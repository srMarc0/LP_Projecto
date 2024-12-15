#include "BallTree.h"

size_t BallTree::calcularPuntMesLluny(std::vector<double>& distances)
{
    double max = distances[0];
    size_t length = distances.size();
    size_t index = 0;

    for (size_t i = 1; i < length; i++)
    {
        if (distances[i] > max)
        {
            max = distances[i];
            index = i;
        }
    }

    return index;
}

size_t BallTree::calcularPuntMesLluny(std::vector<double>& distances, double& maxDistance)
{
    double max = distances[0];
    size_t length = distances.size();
    size_t index = 0;

    for (size_t i = 1; i < length; i++)
    {
        if (distances[i] > max)
        {
            max = distances[i];
            index = i;
        }
    }

    maxDistance = max;
    return index;
}

void BallTree::construirArbre(const std::vector<Coordinate>& coordenades) {
    // TODO: Utilitza aquest metode per construir el teu BallTree
    // TODO: amb les coordenades que se us passen per parametre
    if (coordenades.size() > 1)
    {
        m_root = this;
        construirArbreRec(coordenades);
    }
}

void BallTree::construirArbreRec(const std::vector<Coordinate>& coordenades)
{
    m_coordenades = coordenades;
    if (m_coordenades.size() > 1)
    {
        // Calcula el punt central dels nodes (punt C)
        m_pivot = Util::calcularPuntCentral(m_coordenades);

        // Calcula totes les distancies dels nodes respecte el punt C
        std::vector<double> distancesPivot;

        size_t length = m_coordenades.size();
        for (size_t i = 0; i < length; i++)
        {
            distancesPivot.push_back(Util::DistanciaHaversine(m_pivot, m_coordenades[i]));
        }

        // Agafem el punt mes llunya (punt A)
        double maxA;
        size_t indexA = calcularPuntMesLluny(distancesPivot, maxA);
        m_radi = maxA;

        // Calcula totes les distancies dels nodes respecte el punt A
        std::vector<double> distancesPuntA;

        for (size_t i = 0; i < length; i++)
        {
            distancesPuntA.push_back(Util::DistanciaHaversine(m_coordenades[indexA], m_coordenades[i]));
        }

        // Agafem el punt mes llunya (punt B)
        double maxB;
        size_t indexB = calcularPuntMesLluny(distancesPuntA, maxB);

        std::vector<Coordinate> left, right;
        for (size_t i = 0; i < length; i++)
        {
            // Per cada node:
            Coordinate node = m_coordenades[i];

            // Calcula la distancia del node al punt A (D1)
            double D1 = Util::DistanciaHaversine(node, m_coordenades[indexA]);
            // Calcula la distancia del node al punt B (D2)
            double D2 = Util::DistanciaHaversine(node, m_coordenades[indexB]);

            if (D1 < D2)
            {
                // Si D1 < D2, assignem el node a la bola esquerra
                left.emplace_back(node);

            }
            else
            {
                // Si D1 >= D2, assignem el node a la bola dreta
                right.emplace_back(node);
            }
        }

        if (!left.empty())
        {
            m_left = new BallTree();
            m_left->setArrel(m_root);
            m_left->construirArbreRec(left);
        }
        if (!right.empty())
        {
            m_right = new BallTree();
            m_right->setArrel(m_root);
            m_right->construirArbreRec(right);
        }
    }
}

void BallTree::inOrdre(std::vector<std::list<Coordinate>>& out) {
    if (this != nullptr) 
    {
        if (m_left != nullptr) // Baixem pel subarbre esquerre
        {
            m_left->inOrdre(out);
        }
        std::list<Coordinate> llistaNodes; //llista on guardem les coordenades per pujarles
        for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++)
            llistaNodes.emplace_back(*it);

        out.emplace_back(llistaNodes);

        if (m_right != nullptr) // Baixem el subarbre dret
        {
            m_right->inOrdre(out);
        }
    }
}

void BallTree::preOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
    if (this != nullptr)
    {
        std::list<Coordinate> llistaNodes; //llista on guardem les coordenades per pujarles
        for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++)
            llistaNodes.emplace_back(*it);

        out.emplace_back(llistaNodes);

        if (m_left != nullptr) // Baixem pel subarbre esquerre
        {
            m_left->inOrdre(out);
        }

        if (m_right != nullptr) // Baixem el subarbre dret
        {
            m_right->inOrdre(out);
        }
    }
   
}

void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
    if (this != nullptr)
    {
        if (m_left != nullptr) // Baixem pel subarbre esquerre
        {
            m_left->inOrdre(out);
        }

        if (m_right != nullptr) // Baixem el subarbre dret
        {
            m_right->inOrdre(out);
        }

        std::list<Coordinate> llistaNodes; //llista on guardem les coordenades per pujarles
        for (auto it = m_coordenades.begin(); it != m_coordenades.end(); it++)
            llistaNodes.emplace_back(*it);

        out.emplace_back(llistaNodes);
    }
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) {
    // TODO: TASCA 3
    // 
    //calcula la distancia del punt central de la bola al pdi (D1)
    //pdi = targetQuery
    double D1 = Util::DistanciaHaversine(targetQuery, ball->getPivot());

    //calcula distancia del punt central de la bola respecte al Q (D2)
    double D2 = Util::DistanciaHaversine(Q, ball->getPivot());

    //si  D1 - bola.radi >= D2 retorna Q
    if (D1 - ball->getRadi() >= D2) 
        return Q;

    //Si la bola es una fulla del arbre, actualiza Q si es el node camí més propor al pdi, dels punts que formen la bola
    if (m_left == nullptr && m_right == nullptr)
    {
       
        auto coords = ball->getCoordenades();
        double minDist = Util::DistanciaHaversine(targetQuery, coords[0]);
        for (size_t i = 1; i < coords.size(); i++)
        {
            double dist = Util::DistanciaHaversine(targetQuery, coords[i]);
            if (minDist > dist)
            {
                minDist = dist;
                Q = coords[i];
            }
               
        }
    }
    else
    {   //else calcula pdi respecte punt central bola esquerra Da
        double Da = Util::DistanciaHaversine(targetQuery, ball->getEsquerre()->getPivot());

        //Calcula la distancia pdi respecte del punt central la bola dreta
        double Db = Util::DistanciaHaversine(targetQuery, ball->getDreta()->getPivot());

        //Si Da < Db comença cerca per la bola esquerra i despres dreta
        if (Da < Db)
        {
            Q = nodeMesProper(targetQuery, Q, m_left);
            Q = nodeMesProper(targetQuery, Q, m_right);
        }
        else
        {
            Q = nodeMesProper(targetQuery, Q, m_right);
            Q = nodeMesProper(targetQuery, Q, m_left);
           
        }
    }
    
    //Si Da < Db comença cerca per la bola esquerra i despres dreta
    //else comença cerca per bola dreta i despres esquerra
    
    return Q;
}



