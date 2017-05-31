//
// Created by Lenovo on 4/25/2017.
//

#ifndef DATABASE_TABLEROW_H
#define DATABASE_TABLEROW_H

#include <array>
#include <vector>

using namespace std;
template <class T>
class TableRow {
private:
    string rowName;
    string rowType;

public:
    vector<T> values;
    TableRow(const string &rowName, const string &rowType);

    const string &getRowName() const;

    void setRowName(const string &rowName);

    const string &getRowType() const;

    void setRowType(const string &rowType);



    void setRowValue(const T rowValue);

    T* getRowValues() const;




};


#endif //DATABASE_TABLEROW_H
