/*Hulpcklasse voor de mainparser
 *@Author: Robbe
 *@Date: 05/06/2018
 */

#ifndef OPDRACHT3_PARSER_H
#define OPDRACHT3_PARSER_H


#include <iostream>
#include "../TinyXML/tinyxml.h"

using namespace std;

/*
 * This class is meant as a superclass for classes that can load parse xml files.
 * The abstract parsers can load any xml file into a TinyXML document (TiXmlDocument)
 * and remembers the first element (aka the root) in that document.
 */
class Parser {
private:
    TiXmlElement * root;
    TiXmlDocument doc;
public:
    Parser();
    virtual ~Parser();

    /*
     * Returns the first element (aka the root) of the loaded XML Document.
     * Root is returned as a TiXmlElement*
     */
    TiXmlElement* getRoot(){return root;}

    /*
     * Loads any XML file. Returns true when loading the file was succesfull.
     * Returns false, when something went wrong during loading.
     */
    bool loadFile(string filename);
};

#endif //OPDRACHT3_PARSER_H
