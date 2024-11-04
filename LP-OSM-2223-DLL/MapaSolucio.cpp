#include "pch.h"
#include "MapaSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& v)
{
    /*
    Coordinate c;

    c.lat = 41.4918606;
    c.lon = 2.1465411;

    PuntDeInteresBotigaSolucio* p = new PuntDeInteresBotigaSolucio(c, "La Millor Pastisseria", "bakery");
    v.push_back(p);

    c.lat = 41.4902204;
    c.lon = 2.1406477;

    PuntDeInteresRestaurantSolucio* r = new PuntDeInteresRestaurantSolucio(c, "El Millor Restaurant", "regional", "yes");
    v.push_back(r);
    */
    v = m_puntInt;
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& v)
{ /*
    CamiSolucio* cami = new CamiSolucio();
    v.push_back(cami);
    */
    v = m_cami;
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    for (int i = 0; i < xmlElements.size(); i++)
    {
        XmlElement elem = xmlElements[i];
        if (elem.id_element == "node")
        {
            if (!elem.fills.empty())
            {

                Coordinate coor;
                coor.lat = std::stod(elem.atributs[2].second); //stod converteix de string a double
                coor.lon = std::stod(elem.atributs[3].second); //Agafem coordenades del node (shop/restaurant)

                if (elem.fills[1].second[0].second == "highway")
                {
                    //carreta, implementar més endevant
                }
                else if (elem.fills[5].second[0].second == "shop")
                {
                    PuntDeInteresBotigaSolucio* botiga = new PuntDeInteresBotigaSolucio(coor, elem.fills[1].second[1].second
                        , elem.fills[5].second[1].second); //Ha de tindre les coordenades, el nom de la botiga i el shop?¿ Suposu que sera el tipus de botiga
                    m_puntInt.push_back(botiga);
                }
                else if (elem.fills[1].second[1].second == "restaurant")
                {
                    PuntDeInteresRestaurantSolucio* res = new PuntDeInteresRestaurantSolucio(coor, elem.fills[5].second[1].second,
                        elem.fills[3].second[1].second, elem.fills[7].second[1].second); //Ha de tindre les coordenades, el nom del Restaurant, tipus de cuina i si te acces cadira de rodes
                    m_puntInt.push_back(res);
                }
            }
        }
        else if (elem.id_element == "way")
        {
            // Crear el camins
            std::vector<std::string> id_nodes;
            int i = 1;
            while (elem.fills[i].first == "nd")
            {
                id_nodes.push_back(elem.fills[i].second[0].second); //id dels nodes que componen el cami
                i += 2;
            }
            CamiSolucio* cami = new CamiSolucio(elem.fills[9].second[1].second, id_nodes);
            m_cami.push_back(cami);

        }


    }
}