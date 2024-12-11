//#pragma once
//
//#include "Common.h"
//#include <vector>
//
//class CamiBase {
//	public:
//		virtual std::vector<Coordinate> getCamiCoords() = 0;
//};
//

#pragma once
#include "pch.h"
#include "Util.h"
#include "Common.h"
#include <vector>

class CamiBase {
public:
	virtual std::vector<Coordinate> getCamiCoords() = 0;
	virtual void setCamiCoords(const std::vector<Coordinate>& c) = 0;
	virtual ~CamiBase() {}
private:

};