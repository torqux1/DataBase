#include <iostream>
#include "Table.h"
#include "TableRow.h"
#include "DataBase.git/Engine.h"
#include "DataBase.git/TableRepo.h"

int main() {
    /*Engine engine();
    engine.run();*/

    TableRow<double> row("id","double");
    row.setRowValue(5.234);
    row.setRowValue(5.234);
    TableRow<double> row3("id","double");
    row3.setRowValue(2.14);
    row3.setRowValue(2.14);
    row3.setRowValue(2.14);
    row.setRowValue(5.234);
    row.setRowValue(5.234);
    TableRow<string> row1("name","string");
    row1.setRowValue("Gonzo");
    row1.setRowValue("Ersen");
    TableRow<int> row2("secondName","string");
   /* cout<< row.getRowName() << endl;
    cout << row.getRowType() << endl;
    row1.getRowValues();*/

    Table<int,string, double> table("Table");
    table.insertDoubleTableRow(row);
    table.insertStringTableRow(row1);
    table.insertIntTableRow(row2);
    table.insertDoubleTableRow(row3);


    TableRepo <int,string, double> repo;
    repo.addTable(table);

    /*repo.describeTableTypes("Table");*/
    repo.addColumn("Table","age", "int");
    repo.print("Table");
    repo.aggregate("Table",3,2.14,0,"minimum");

    /*repo.saveTable("NewTable","saved_tables.txt");*/
        /*table.save("outputFile.txt");*/



    return 0;
}