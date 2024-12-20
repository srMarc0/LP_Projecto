
#include "CamiBase.h"
class CamiSolucio : public CamiBase
{
private:
    std::vector<Coordinate> m_camiCoords;
    std::string m_highway;
    std::vector<Coordinate> m_coordCami;
public:
    CamiSolucio()
    {   /*
        m_camiCoords = {
            {41.4928803, 2.1452381},
            {41.4929072, 2.1452474},
            {41.4933070, 2.1453852},
            {41.4939882, 2.1456419}
        };
        */
    }
    CamiSolucio(std::string highway, std::vector<Coordinate> coord) : m_highway(highway), m_coordCami(coord) {}
    ~CamiSolucio() {}
    std::vector<Coordinate>getCamiCoords() override { return m_camiCoords; }
    void setCamiCoords(const std::vector<Coordinate>& c) override { m_camiCoords = c; }
};