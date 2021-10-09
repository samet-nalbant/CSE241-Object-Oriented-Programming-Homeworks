#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "hexvector.h"
using namespace hex;
HexVector::HexVector(){
    setSize(5);
    create_board();
}
HexVector::HexVector(const int &size){
    setSize(size);
    create_board();
}

void HexVector::create_board(){
    int size = get_size();
    hexCells.push_back(vector<Cell>());
    for(int i=0;i<size;i++){
        hexCells.push_back(vector<Cell>());
        for(int j=0;j<size;j++){
            hexCells[i].push_back(Cell());
            hexCells[i][j].set_cell(board_cells::empty);
            hexCells[i][j].set_row_column(i,static_cast<char>(j+48));
        }
    }
}
void HexVector::reset(){
    create_board();
}
Cell& HexVector::operator() (const int &index1,const int &index2){
    
    if(index1 >= get_size() || index2 >= get_size() || index1 < 0 || index2 < 0){
        throw InvalidAdressError();
    }
    return hexCells[index1][index2];
}