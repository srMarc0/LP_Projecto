#include "pch.h"
#include "MapaSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& v)
{

    v.clear();
    for (auto it = m_puntInt.begin(); it != m_puntInt.end(); it++)
        v.push_back(*it);

}

void MapaSolucio::getCamins(std::vector<CamiBase*>& v)
{
    v.clear();
    for (auto it = m_cami.begin(); it != m_cami.end(); it++)
        v.push_back(*it);
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    m_puntInt.clear();
    m_cami.clear();

    int k = 0;
    typedef struct
    {
        std::string id;
        Coordinate coor;

    }ID_COOR;

    std::vector<ID_COOR> coorNodoWay;
    std::string id;

    for (int i = 0; i < xmlElements.size(); i++)
    {
        XmlElement elem = xmlElements[i];
        if (elem.id_element == "node")
        {
            if (!elem.atributs.empty())
            {
                Coordinate coor;

                for (auto it = elem.atributs.begin(); it != elem.atributs.end(); it++)//busquem coordenades
                {
                    if (it->first == "id")
                    {
                        id = it->second;
                    }
                    else if (it->first == "lat")
                    {
                        coor.lat = std::stod(it->second);
                    }
                    else if (it->first == "lon")
                    {
                        coor.lon = std::stod(it->second);
                        break;
                    }
                }

                if (!elem.fills.empty())
                {
                    std::string name = "", shop = "", cuisine = "", wheel = "no", open = "", amenity = "";
                    for (auto it = elem.fills.begin(); it != elem.fills.end(); it++) //busquem tags
                    {
                        if (it->first != "#text")
                        {
                            if (it->second[0].second == "name")
                                name = it->second[1].second;
                            else if (it->second[0].second == "shop")
                                shop = it->second[1].second;
                            else if (it->second[0].second == "opening_hours")
                                open = it->second[1].second;
                            else if (it->second[0].second == "wheelchair")
                                wheel = it->second[1].second;
                            else if (it->second[0].second == "amenity")
                                amenity = it->second[1].second;
                            else if (it->second[0].second == "cuisine")
                                cuisine = it->second[1].second;
                        }
                    }
                    if (shop != "" && name != "")
                    {
                        PuntDeInteresBotigaSolucio* botiga = new PuntDeInteresBotigaSolucio(coor, name, id, shop, open, wheel);
                        m_puntInt.push_back(botiga);
                    }
                    else if (amenity != "")
                    {
                        PuntDeInteresRestaurantSolucio* res = new PuntDeInteresRestaurantSolucio(coor, name, id, cuisine, wheel, amenity);
                        m_puntInt.push_back(res);
                    }
                    else
                    {
                        ID_COOR id_coor;
                        id_coor.coor.lat = coor.lat;
                        id_coor.coor.lon = coor.lon;
                        id_coor.id = id;
                        coorNodoWay.push_back(id_coor);

                    }
                }
                else
                {
                    ID_COOR id_coor;
                    id_coor.coor.lat = coor.lat;
                    id_coor.coor.lon = coor.lon;
                    id_coor.id = id;
                    coorNodoWay.push_back(id_coor);

                }

            }
        }
        else if (elem.id_element == "way")
        {

            std::vector<std::string> ref;
            std::vector<Coordinate> coor;
            int j = 0;
            while (j < elem.fills.size())
            {
                if (elem.fills[j].first == "nd")
                {
                    if (!coorNodoWay.empty())
                    {
                        for (auto it = coorNodoWay.begin(); it != coorNodoWay.end(); it++)
                        {
                            if (elem.fills[j].second[0].second == it->id && it->coor.lat != 0)
                            {
                                ref.push_back(it->id);
                                coor.push_back(it->coor);
                                //coorNodoWay.erase(it);
                                break;
                            }

                        }
                    }
                    else
                    {
                        ref.push_back(elem.fills[j].second[1].second);
                    }
                }
                
                j++;
            }

            if (coor.size() && ref.size())
            {
                CamiSolucio* cami = new CamiSolucio(elem.atributs[0].first, ref, coor);
                m_cami.push_back(cami);
            }
            

        }


    }
    int hola = 0;
}

CamiBase* MapaSolucio::buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a)
{
    Graf graf = Graf(); //creem el graf per posar els nodes i les seves relacions
    graf.creaMatriu(this);
  //  graf.creaMatriu(m);

    return nullptr;
}