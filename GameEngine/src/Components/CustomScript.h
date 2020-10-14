#pragma once

#include <string>
#include <vector>
#include "../logger.h"
#include <cstring>
#include <fstream>
#include <iostream>

#include "../CScript.h"
#include "../Components/Components.h"
#include <rapidxml/rapidxml.hpp>
// #include <rapidxml/rapidxml_print.hpp>
// #include <rapidxml/rapidxml_iterators.hpp>
// #include <rapidxml/rapidxml_utils.hpp>

using namespace rapidxml;
using namespace std;

struct CustomScript
{

        CustomScript(string xmlFile) {
            ifstream f(xmlFile);
            if (!f.is_open()) {
                Logger::getInstance() << "Custom script file: " + xmlFile + " failed to open!\n";
            }
            xml = string((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());

            char* cstr;
            cstr = (char*)malloc(sizeof(char) * xml.size());
            strcpy(cstr, xml.c_str());
            doc.parse<0>(cstr);    // 0 means default parse flags
            // cout << doc;
            // print()
            // Logger::getInstance() << doc.value() << "\n";

            free(cstr);
        }

        // string getUpdate() {
        //     // doc.first_node("update");
        // }


        xml_document<> doc; // character type defaults to char
        string xml;
};
