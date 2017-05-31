//
// Created by Lenovo on 5/12/2017.
//

#include <iostream>
#include <fstream>
#include "TableRepo.h"
#include<sstream>
template <typename T, typename Y, typename V>
TableRepo<T, Y, V>::TableRepo(const string &name): name(name) {
}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::addTable(Table<T,Y,V> table) {
    savedTables.insert(pair<string,Table<T,Y,V>>(table.getName(), table));

}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::describeTableTypes(string name) {
    savedTables.at(name).describeTable();
}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::showTables() {
    for (typename map<string, Table<T, Y, V>>::iterator it = savedTables.begin(); it != savedTables.end(); ++it)
    {
        cout << it->second.getName() << endl;

    }
}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::print(string name) {
        savedTables.at(name).print();

}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::saveTable(string tableName, string fileName) {
    savedTables.at(tableName).save(fileName);


}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::renameTable(string oldName, string newName) {
    if(savedTables.count(newName) != 0){
        cout << "Error! Table with such name already exist!" << endl;
        return;
    }
    savedTables.at(oldName).setName(newName);
     string oldKey = oldName;
    string newKey = newName;
    savedTables.insert(pair<string,Table<T,Y,V>>(newName, savedTables.at(oldName)));
    savedTables.erase(oldKey);
    }
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::addColumn(string tableName, string columName, string columType) {
    if(columType == "string"){
        TableRow<string> row(columName,columType);
        savedTables.at(tableName).insertStringTableRow(row);
    }
    else if(columType == "int"){
        TableRow<int> row(columName,columType);
        savedTables.at(tableName).insertIntTableRow(row);
    }
    else {
        TableRow<double> row(columName,columType);
        savedTables.at(tableName).insertDoubleTableRow(row);
    }

}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::count(string tableName, int searchedColumn, string value) {
    string type = savedTables.at(tableName).getRowType(searchedColumn);
    if(type == "string"){
        savedTables.at(tableName).countStringValues(searchedColumn,value);
    }
    else if(type == "int"){
        int Result;
        istringstream convert(value);
        convert >> Result;
        savedTables.at(tableName).countIntValues(searchedColumn,Result);

    }
    else if(type == "double"){
        double Result;
        istringstream convert(value);
        convert >> Result;
        savedTables.at(tableName).countDoubleValues(searchedColumn,Result);

    }

}
template <typename T, typename Y, typename V>
void TableRepo<T, Y, V>::aggregate(string tableName, int searchColumn, double value, int targetColumn, string operation) {
    if(operation == "sum")
        savedTables.at(tableName).sum(searchColumn, targetColumn, value);
    else if(operation=="minimum")savedTables.at(tableName).min(searchColumn,targetColumn, value);
    else if(operation=="maximum")savedTables.at(tableName).max(searchColumn,targetColumn, value);


}


template class TableRepo<int, string, double>;