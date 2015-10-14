#include "MapRender.h"
#include "thirdparty/pugixml-1.6/src/pugixml.cpp"


MapRender::MapRender(char* xml_url)
{

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(xml_url);

	//std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("map").child("layer").attribute("name").value() << std::endl;
	
	// Get map
	pugi::xml_node map = doc.child("map");

	std::string _map_img = map.child("tileset").child("image").attribute("source").value();
	char *map_img = &_map_img[0];

	// Create map
	Map m = Map{ map_img };

	// Loop though elements
	for (pugi::xml_node element = map.first_child(); element; element = element.next_sibling()) {

		std::string elementName = element.name();

		if (elementName == "layer") {

			std::string _layer_name = element.attribute("name").value();
			char *layer_name = &_layer_name[0];

			// Create MapLayer
			MapLayer ml = MapLayer{ layer_name };

			// Add tiles to MapLayer
			renderLayer(element, ml);

			// Add MapLayer to Map
			m.setMapLayer(ml);
		}

	}

}

void MapRender::renderLayer(pugi::xml_node layer, MapLayer ml) {

	for (pugi::xml_node tile = layer.child("data").first_child(); tile; tile = tile.next_sibling()) {

		std::string _tileGID = tile.attribute("gid").value();
		int tileGID = atoi(_tileGID.c_str());

		// Add tile gID to MapLayer
		ml.setGID(tileGID);

	}

}