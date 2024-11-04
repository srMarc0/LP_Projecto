#pragma once
#include "MapaBase.h"

class MapaSolucio : public MapaBase
{
private:
    std::vector<CamiBase*> m_cami;
    std::vector<PuntDeInteresBase*> m_puntInt;

public:
    void getPdis(std::vector<PuntDeInteresBase*>& v) override
    {
        Coordinate c;

        c.lat = 41.4918606;
        c.lon = 2.1465411;

        PuntDeInteresBotigaSolucio* p = new PuntDeInteresBotigaSolucio(c, "La Millor Pastisseria", "bakery");
        v.push_back(p);

        c.lat = 41.4902204;
        c.lon = 2.1406477;

        PuntDeInteresRestaurantSolucio* r = new PuntDeInteresRestaurantSolucio(c, "El Millor Restaurant", "regional", "yes");
        v.push_back(r);
    }

    void getCamins(std::vector<CamiBase*>& v) override
    {
        CamiSolucio* cami = new CamiSolucio();
        v.push_back(cami);
    }
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override
    {
        for (int i = 0; i < xmlElements.size(); i++)
        {
            XmlElement elem = xmlElements[i];
            if (elem.id_element == "node")
            {

                Coordinate coor;
                coor.lat = std::stod(elem.atributs[7].second); //stod converteix de string a double
                coor.lon = std::stod(elem.atributs[8].second); //Agafem coordenades del node (shop/restaurant)

                if (elem.atributs[0].second == "shop")
                {
                    PuntDeInteresBotigaSolucio* botiga = new PuntDeInteresBotigaSolucio(coor,
                        elem.fills[2].second, elem.fills[1].second); //Ha de tindre les coordenades, el nom de la botiga i el shop?¿ Suposu que sera el tipus de botiga
                    m_puntInt.push_back(botiga);
                }
                else if (elem.atributs[0].second == "restaurant")
                {
                    PuntDeInteresRestaurantSolucio* res = new PuntDeInteresRestaurantSolucio(coor
                        , elem.fills[2].second, elem.fills[1].second, elem.fills[3].second); //Ha de tindre les coordenades, el nom del Restaurant, tipus de cuina i si te acces cadira de rodes
                    m_puntInt.push_back(res);
                }
               
            }
            else if (elem.id_element == "way")
            {
                // Crear el camins
            }
            

        }


    }
};