#pragma once

#include "pch.h"
#include "CamiBase.h"
class CamiSolucio : public CamiBase
{
private:
    std::vector<Coordinate> m_camiCoords;
    std::string m_highway;
    std::vector<std::string> m_id;
public:
    CamiSolucio() {  }
    CamiSolucio(std::string highway, std::vector<std::string> id, std::vector<Coordinate> camiCoord) : m_highway(highway), m_id(id), m_camiCoords(camiCoord) {}
    ~CamiSolucio() {}
    std::vector<Coordinate>getCamiCoords() override { return m_camiCoords; }
    void setCamiCoords(const std::vector<Coordinate>& c) override { m_camiCoords = c; }
};