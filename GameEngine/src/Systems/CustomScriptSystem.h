#pragma once

#include <fstream>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <windows.h>

#include "entityx/entityx.h"
#include "../Components/Components.h"

using namespace entityx;
using namespace std;
class CustomScriptSystem : public System<CustomScriptSystem> {
    public:
        void update(EntityManager& es, EventManager& events, TimeDelta dt) override {
            // auto entities = es.entities_with_components<CustomScript>();

            // for (Entity e : entities) {
            //     ComponentHandle<CustomScript> handle = e.component<CustomScript>();
            //     string updateContent = handle->getUpdate();
            //     runUpdate(updateContent, handle);
            // }
        }

    private:
        // void runUpdate(string updateContent, ComponentHandle<CustomScript> cScript) {
        //     //run update stuff
        // }

}; 