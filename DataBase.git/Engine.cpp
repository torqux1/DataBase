/*
//
// Created by Lenovo on 5/12/2017.
//

#include "Engine.h"
#include<cstring>
#include <string>
#include <iostream>

using namespace std;
void Engine::run() {
    TableRepo tr();
    string command;
    cin >> command;
    if(command.substr(0,4) == "Load"){
        string path = command.substr(6,command.length());

        tr.load(path);
    }
    else if(command.substr(0,4)== "Save"){
        string name = command.substr(6,command.find(''));
        string path = command.substr(name.length() + 1, command.length());
        tr.save(name,path);

    }
    else if(command.substr(0,5) == "Print"){
      string name = command.substr(7,command.length());

        tr.print(name);
    }
    else if(command.substr(0,6)== "Rename" ){
        string oldName = command.substr(6,command.find(''));
        string newName = command.substr(oldName.length(),command.length());
        tr.rename(oldName,newName);

    }
    else if(command.substr(0,6)== "Describe" ){

        string table = command.substr(8,command.length());
        tr.describe(table);

    }

    else if()

}
*/
