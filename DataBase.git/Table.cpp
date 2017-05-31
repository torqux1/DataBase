//
// Created by Lenovo on 4/25/2017.
//

#include "Table.h"



template <class T>
void Table<T>::insertTableRow(TableRow<T> &row) {

    this->tableRows[row.getRowName()] = row;
}
template <class T>
Table<T>::Table(const string &name) : name(name) {}

/*template <class T>
const TableRow<T> & Table::getTableRow(string name)  {
    return tableRows.at(name);
}*/
