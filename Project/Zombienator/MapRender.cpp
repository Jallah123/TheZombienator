#include "MapRender.h"
#include "thirdparty/pugixml-1.6/src/pugixml.cpp"


MapRender::MapRender(char* xml_url)
{

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(xml_url);

	//std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("map").child("layer").attribute("name").value() << std::endl;
	
	// Get map
	pugi::xml_node map = doc.child("map");

	// Loop though elements
	for (pugi::xml_node element = map.first_child(); element; element = element.next_sibling()) {

		std::string elementName = element.name();

		cout << elementName << endl;

		if (elementName == "tileset") {
			cout << "TILESET " << element.attribute("name").value() << endl;
		}
		else if (elementName == "layer") {
			cout << "LAYER " << element.attribute("name").value() << endl;
		}

	}

}