#pragma once
#include <string>
#include <iostream>
#include "thirdparty/pugixml-1.6/src/pugixml.hpp"
#include "Map.h"
#include "MapLayer.h"

using namespace std;
class MapRender
{
public:
	MapRender(char* xml_url);
	void renderLayer(pugi::xml_node element, MapLayer ml);
private:
protected:

};