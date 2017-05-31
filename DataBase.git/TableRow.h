//
// Created by Lenovo on 4/25/2017.
//

#ifndef DATABASE_TABLEROW_H
#define DATABASE_TABLEROW_H

#include <array>

using namespace std;
template <class T>
class TableRow {
private:
    string rowName;
    string rowType;
    string maikatiDaEba;


    vector<T> rowValues;
public:
    TableRow(const string &rowName, const string &rowType, const T &rowValue);

    const string &getRowName() const;

    void setRowName(const string &rowName);

    const string &getRowType() const;

    void setRowType(const string &rowType);

    void getRowValues(string row) const;

    void setRowValue(const T rowValue);
    void aiSeEbEMBe();
};
template class TableRow<int>;
template class TableRow<double>;
template class TableRow<string>;

#endif //DATABASE_TABLEROW_H
