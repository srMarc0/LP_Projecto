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
    std::vector<Coordinate> getCamiCoords() override { return m_camiCoords; }
    std::vector<Coordinate>* getCamiCoordsPtr() override { return &m_camiCoords; }
    void setCamiCoords(const std::vector<Coordinate>& c) override { m_camiCoords = c; }
    int getNCoords() override { return m_camiCoords.size(); }
    std::vector<std::string> getID() override { return m_id; }
    std::vector<std::string>* getIDPtr() override { return &m_id; }
};