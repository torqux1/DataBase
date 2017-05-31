//
// Created by Lenovo on 4/25/2017.
//

#include "TableRow.h"
template <class T>
TableRow<T>::TableRow(const string &rowName, const string &rowType, const T &rowValue) {
    this->setRowName(rowName);
    this->setRowType(rowType);
    this->setRowValue(rowValue);
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
const T &TableRow<T>::getRowValue() const {
    return rowValue;
}
template <class T>
void TableRow<T>::setRowValue(const T &rowValue) {
    this->rowValue = rowValue;
}




