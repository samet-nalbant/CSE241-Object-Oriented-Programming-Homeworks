#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;
#include "cell.h"
using namespace hex;

Cell::Cell(int row_num, char column_value, board_cells cell_value)
    :row(row_num),column(column_value)
{}

Cell::Cell(){

}
void Cell:: set_row_column(int row_num,char column_value){
    row = row_num;
    column = column_value;
}
void Cell::set_cell(board_cells cell_value){
    value = cell_value;
}
