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

        PuntDeInteresRestaurantSolucio* r = new PuntDeInteresRestaurantSolucio(c, "El Millor Restaurant", "regional", "restaurant");
        v.push_back(r);
    }

    void getCamins(std::vector<CamiBase*>& v) override
    {
        CamiSolucio* cami = new CamiSolucio();
        v.push_back(cami);
    }
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override
    {



    }
};