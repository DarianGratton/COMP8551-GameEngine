#pragma once

#include <string>
#include <vector>
#include "../logger.h"
#include <cstring>
#include <fstream>
#include <iostream>

#include "../CScript.h"
#include "../Components/Components.h"
#include "tinyxml2.h"

// using namespace std;
using namespace tinyxml2;
struct CustomScript
{

        CustomScript(string xmlFile) {

            doc = new TinyXMLDocument();
            XMLError xmlerr = doc->LoadFile(xmlFile.c_str());
            if (xmlerr != XML_SUCCESS)
            {
                Logger::getInstance() << "Could not read game object XML file!\n";
                return;
            }
            root = doc->FirstChildElement("root");
        }

        XMLElement* getUpdate() {
            return root->FirstChildElement("update");
        }

        ~CustomScript() {
            delete doc;
        }


        TinyXMLDocument* doc;
        XMLElement* root;
        string xml;
};
