#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

#include "entityx/entityx.h"
#include "../Components/Components.h"
#include "tinyxml2.h"

using namespace entityx;
using namespace std;
using namespace tinyxml2;
class CustomScriptSystem : public System<CustomScriptSystem> {
    public:
        void update(EntityManager& es, EventManager& events, TimeDelta dt) override {
            auto entities = es.entities_with_components<CustomScript>();

            for (Entity e : entities) {
                ComponentHandle<CustomScript> handle = e.component<CustomScript>();
                XMLElement* updateContent = handle->getUpdate();
                runCommands(updateContent->FirstChild(), handle);
            }
        }

    private:
        void runCommands(XMLNode* command, ComponentHandle<CustomScript> cScript) {
            while (command != NULL) {
                //do commands

                string name = command->Value();
                Logger::getInstance() << name << "\n";
                const XMLAttribute* attr = command->ToElement()->FirstAttribute();
                vector<string> attribNames;
                vector<string> attribVals;

                while (attr != NULL) {
                    attribNames.push_back(attr->Name());
                    attribVals.push_back(attr->Value());
                    attr = attr->Next();
                }

                command = command->NextSibling();
            }
        }

}; 