//
// Created by Lenovo on 4/25/2017.
//

#include <iostream>
#include <fstream>
#include <limits.h>
#include "Table.h"


template<typename T, typename Y, typename V>
Table<T, Y, V>::Table(const string &name) : name(name), count(0) {}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::insertIntTableRow(TableRow<T> row) {

    intRows.insert(pair<int, TableRow<T>>(count++, row));

}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::insertStringTableRow(TableRow<Y> row) {

    stringRows.insert(pair<int, TableRow<Y>>(count++, row));

}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::insertDoubleTableRow(TableRow<V> row) {

    doubleRows.insert(pair<int, TableRow<V>>(count++, row));
}


template<typename T, typename Y, typename V>
void Table<T, Y, V>::displayTableRow(int num) {
    if (stringRows.count(num) != 0)
        cout << stringRows.at(num).getRowType() << " ";
    else if (intRows.count(num) != 0)
        cout << intRows.at(num).getRowType() << " ";
    else cout << doubleRows.at(num).getRowType() << " ";

}

template<typename T, typename Y, typename V>
const string &Table<T, Y, V>::getName() const {
    return name;
}

template<typename T, typename Y, typename V>
int Table<T, Y, V>::getAllMapsSize() {
    return intRows.size() + stringRows.size() + doubleRows.size();
}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::describeTable() {
    for (int x = 0; x < count; x++) {
        displayTableRow(x);
    }

}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::print() {
    for (int x = 0; x < count; x++) {
        getTableData(x);
    }
}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::getTableData(int num) {
    if (stringRows.count(num) != 0) {
        cout << "name: ";
        cout << stringRows.at(num).getRowName() << " ";
        cout << "type: ";
        cout << stringRows.at(num).getRowType() << " ";
        cout << "values: ";
        for (int x = 0; x < stringRows.at(num).values.size(); x++)
            cout << stringRows.at(num).values.at(x) << " ";
        cout << endl;
    } else if (intRows.count(num) != 0) {
        cout << "name: ";
        cout << intRows.at(num).getRowName() << " ";
        cout << "type: ";
        cout << intRows.at(num).getRowType() << " ";
        cout << "values: ";
        for (int x = 0; x < intRows.at(num).values.size(); x++)
            cout << intRows.at(num).values.at(x) << " ";
        cout << endl;
    } else {
        cout << "name: ";
        cout << doubleRows.at(num).getRowName() << " ";
        cout << "type: ";
        cout << doubleRows.at(num).getRowType() << " ";
        cout << "values: ";
        for (int x = 0; x < doubleRows.at(num).values.size(); x++)
            cout << doubleRows.at(num).values.at(x) << " ";
        cout << endl;
    }
}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::save(string fileName) {
    string dir = "C:\\Users\\Lenovo\\Desktop\\";
    ofstream outputFile(dir + fileName);
    outputFile << this->getName() << endl;
    for (int x = 0; x < count; x++) {
        if (stringRows.count(x) != 0) {
            outputFile << stringRows.at(x).getRowName() << endl;
            outputFile << stringRows.at(x).getRowType() << endl;
            if (stringRows.at(x).values.size() == 0) outputFile << "null";
            for (int y = 0; y < stringRows.at(x).values.size(); y++)
                outputFile << stringRows.at(x).values.at(y) << " ";
            outputFile << endl;
        } else if (intRows.count(x) != 0) {
            outputFile << intRows.at(x).getRowName() << endl;
            outputFile << intRows.at(x).getRowType() << endl;
            if (intRows.at(x).values.size() == 0) outputFile << "null";
            for (int y = 0; y < intRows.at(x).values.size(); y++)
                outputFile << intRows.at(x).values.at(y) << " ";
            outputFile << endl;

        } else {
            outputFile << doubleRows.at(x).getRowName() << endl;
            outputFile << doubleRows.at(x).getRowType() << endl;
            if (doubleRows.at(x).values.size() == 0) outputFile << "null";
            for (int y = 0; y < doubleRows.at(x).values.size(); y++)
                outputFile << doubleRows.at(x).values.at(y) << " ";
            outputFile << endl;

        }
    }
    outputFile.close();
}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::setName(const string &name) {
    Table::name = name;
}

template<typename T, typename Y, typename V>
string Table<T, Y, V>::getRowType(int num) {
    if (stringRows.count(num) != 0) return "string";
    else if (intRows.count(num) != 0) return "int";
    else return "double";
}

template<typename T, typename Y, typename V>
void Table<T, Y, V>::countDoubleValues(int pos, V value) {
    int c = 0;
    for (int x = 0; x < doubleRows.at(pos).values.size(); x++) {

        if (doubleRows.at(pos).values.at(x) == value) c++;
    }
    cout << c << "rows countains the value!" << endl;
}


template<typename T, typename Y, typename V>
void Table<T, Y, V>::countIntValues(int pos, T value) {
    int c = 0;
    for (int x = 0; x < intRows.at(pos).values.size(); x++) {

        if (intRows.at(pos).values.at(x) == value) c++;
    }
    cout << c << "rows countains the value!" << endl;
}


template<typename T, typename Y, typename V>
void Table<T, Y, V>::countStringValues(int pos, Y value) {
    int c = 0;
    for (int x = 0; x < stringRows.at(pos).values.size(); x++) {

        if (stringRows.at(pos).values.at(x) == value) c++;
    }
    cout << c << "rows countains the value!" << endl;
}
template<typename T, typename Y, typename V>
void Table<T, Y, V>::min(int searchColumn, int targetColumn, double value) {
    double currMax = INT_MAX;
    if (doubleRows.count(searchColumn) != 0) {

        for (int x = 1; x < doubleRows.at(searchColumn).values.size(); x++) {

            if (doubleRows.at(searchColumn).values.at(x) == value) {

                if (doubleRows.count(targetColumn) != 0) {
                    if (doubleRows.at(targetColumn).values.size() >= x) {
                        if (doubleRows.at(targetColumn).values.at(x) < currMax)
                            currMax = doubleRows.at(targetColumn).values.at(x);
                    }
                } else if (intRows.count(targetColumn) != 0) {
                    if (intRows.at(targetColumn).values.size() >= x) {
                        if (intRows.at(targetColumn).values.at(x) < currMax)
                            currMax = intRows.at(targetColumn).values.at(x);
                    }
                }
            }
        }
    }
    cout << currMax << endl;
}
template<typename T, typename Y, typename V>
void Table<T, Y, V>::max(int searchColumn, int targetColumn, double value) {

}
template<typename T, typename Y, typename V>
void Table<T, Y, V>::sum(int searchColumn, int targetColumn, double value) {

}

template
class Table<int, string, double>;
