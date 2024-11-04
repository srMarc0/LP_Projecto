#include "MapaBase.h"

class MapaSolucio : public MapaBase
{
private:
    std::vector<CamiBase*> m_cami;
    std::vector<PuntDeInteresBase*> m_puntInt;

public:
    MapaSolucio()
    {
        /*
        getPdis(m_puntInt);
        getCamins(m_cami);
        */
    }
    ~MapaSolucio() {}

    void getPdis(std::vector<PuntDeInteresBase*>& v) override;
    void getCamins(std::vector<CamiBase*>& v) override;
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;
};