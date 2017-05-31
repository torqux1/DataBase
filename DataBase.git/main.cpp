#include <iostream>
#include "TableRow.h"
#include "Table.h"

int main() {
    TableRow<int> row("Ivan","Pesho",15);
    cout<< row.getRowName() << endl;
    cout << row.getRowType() << endl;
    cout << row.getRowValue() << endl;
    Table<int> table("Table");
    table.insertTableRow(row);



    return 0;
}