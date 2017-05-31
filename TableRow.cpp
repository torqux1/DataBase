//
// Created by Lenovo on 4/25/2017.
//

#include <iostream>
#include "TableRow.h"

template <class T>
TableRow<T>::TableRow(const string &rowName, const string &rowType) {
    this->setRowName(rowName);
    this->setRowType(rowType);

}

template <class T>
const string &TableRow<T>::getRowName() const {
    return rowName;
}

template <class T>
void TableRow<T>::setRowName(const string &rowName) {
    this->rowName = rowName;
}
template <class T>
const string &TableRow<T>::getRowType() const {
    return rowType;
}
template <class T>
void TableRow<T>::setRowType(const string &rowType) {
    this->rowType = rowType;
}

template <class T>
T* TableRow<T>::getRowValues() const {
    T elements[values.size()];
    for(int x = 0; x < this->values.size(); x++)
        elements[x] = values.at(x);
    return elements;
}
template <class T>
void TableRow<T>::setRowValue(const T rowValue) {
    this->values.push_back(rowValue);
}


template class TableRow<int>;
template class TableRow<double>;
template class TableRow<string>;




