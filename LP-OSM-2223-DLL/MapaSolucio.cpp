#include "pch.h"
#include "MapaSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& v)
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

void MapaSolucio::getCamins(std::vector<CamiBase*>& v)
{
    CamiSolucio* cami = new CamiSolucio();
    v.push_back(cami);
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
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
                PuntDeInteresBotigaSolucio* botiga = new PuntDeInteresBotigaSolucio(coor, elem.fills[2].second[0].second
                    , elem.fills[1].second[0].second); //Ha de tindre les coordenades, el nom de la botiga i el shop?¿ Suposu que sera el tipus de botiga
                m_puntInt.push_back(botiga);
            }
            else if (elem.atributs[0].second == "restaurant")
            {
                PuntDeInteresRestaurantSolucio* res = new PuntDeInteresRestaurantSolucio(coor, elem.fills[2].second[0].second,
                    elem.fills[1].second[0].second, elem.fills[3].second[0].second); //Ha de tindre les coordenades, el nom del Restaurant, tipus de cuina i si te acces cadira de rodes
                m_puntInt.push_back(res);
            }

        }
        else if (elem.id_element == "way")
        {
            // Crear el camins
            /*
            int i = 0;
            while (elem.fills[i].first == "nd")
            {
               //
            }
            CamiSolucio* cami = new CamiSolucio(elem.fills[4].second[0].second);
            */
        }


    }
}