#include "MapFactory.h"

Map * MapFactory::NextMap(SDL_Renderer* ren) {

	// todo, hier wat logica inbakken

	string path = "assets/maps/map-1280x640_spawns.json";

	return new Map(path, *ren);

}