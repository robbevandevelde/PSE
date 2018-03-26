//
// Created by Robbe Van de Velde on 15/02/18.
//

#include "Parser.h"
Parser::Parser() {
    // TODO Auto-generated constructor stub

}

Parser::~Parser() {
    // TODO Auto-generated destructor stub
}

bool Parser::loadFile(string filename) {
    if(!doc.LoadFile(filename.c_str())){
        cerr << doc.ErrorDesc() << endl;
        return false;
    }

    root = doc.FirstChildElement();
    if(root == NULL){
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return false;
    }
    return true;
}

