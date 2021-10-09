#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

#include "hexarray1d.h"
using namespace hex;
HexArray1D::HexArray1D(){
    setSize(5);
    create_board();
}
HexArray1D::HexArray1D(const int &size){
    setSize(size);
    create_board();
}
void HexArray1D::create_board(){
    hexCells = (Cell*)malloc(sizeof(Cell)*(get_size()*get_size()));
    for(int i=0;i<get_size()*get_size();i++){
            hexCells[i].set_cell(board_cells::empty);
            hexCells[i].set_row_column(i/5,static_cast<char>(i%5));
    }
}
void HexArray1D:: reset(){
    free(hexCells);
    create_board();
}
HexArray1D::HexArray1D(const HexArray1D &other):
    AbstractHex(other)
{

    hexCells = (Cell*)malloc(sizeof(Cell)*other.get_size());
    for(int i=0;i<get_size();i++){
        hexCells[i] = other.hexCells[i];
    }
}                              
Cell & HexArray1D::operator() (const int &index1,const int &index2) {
    int index;
    if(index1 >= get_size() || index2 >= get_size()|| index1 < 0 || index2 < 0){
        throw InvalidAdressError();
    }
    index = index1*(get_size())+index2;
    return hexCells[index];
}
HexArray1D & HexArray1D::operator = (const HexArray1D &other){
    if(get_size() != other.get_size()){
        hexCells = (Cell*)realloc(hexCells,other.get_size()*sizeof(Cell));
    }
    game_size = other.game_size;
    game_mode =other.game_mode;
    last_user = other.last_user;
    user = other.user;
    mode =other.mode;
    computer_row = other.computer_row;
    computer_column = other.computer_column;
    last_move = other.last_move;
    for(int i=0;i<game_size;i++){
        hexCells[i] = other.hexCells[i];
    }
    return *this;
}
HexArray1D::~HexArray1D(){
    hexCells = NULL;
    free(hexCells);
}