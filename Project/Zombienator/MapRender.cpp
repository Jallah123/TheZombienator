#include "MapRender.h"
#include "thirdparty/pugixml-1.6/src/pugixml.cpp"


MapRender::MapRender(char* xml_url)
{
	cout << "gayy" << endl;

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(xml_url);

	std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;


}
