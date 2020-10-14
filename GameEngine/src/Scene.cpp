#include "Scene.h"

#include "logger.h"
#include <entityx/entityx.h>
#include "engine.h"

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>

string Scene::getName() {
    return name;
}

void Scene::load() {
    //open file (fileName)
    //ifstream file(fileName);
    //read file, parse it

    Logger::getInstance() << "Loading a scene's map!\n";

    tmx::Map currentMap;

    if (currentMap.load("maps/platformtest.tmx"))
    {
      /*  const auto& layers = currentMap.getLayers();
        for (const auto& layer : layers) 
        {
            if (layer->getType() == tmx::Layer::Type::Tile)
            {
               // const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
               // const auto& objects = objectLayer.getObjects();
               // for (const auto& object : objects)
               // {

                    //Logger::getInstance() << object.getName();

               // }
            }
        } */
    }

    //populate list of entities with their components
    Entity e = Engine::getInstance().entities.create();
    e.assign<CustomScript>("src/CustomScripts/XmlExampleCustomScript.xml");

}

Scene::Scene(string sceneName, string tmxFile) : name(sceneName), fileName(tmxFile) {
    
}