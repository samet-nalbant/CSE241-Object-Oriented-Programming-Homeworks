#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "hexadapter.h"
using namespace hex;
template<template<typename...> class T>
HexAdapter < T > ::HexAdapter(){
    setSize(5);
    create_board();
}

template<template<typename...> class T>
HexAdapter < T >::HexAdapter(const int &size){
    setSize(size);
    create_board();
}

template<template<typename...> class T>
void HexAdapter < T >::create_board(){
    int size = get_size();
    hexCells.push_back(T<Cell>());
    for(int i=0;i<size;i++){
        hexCells.push_back(T<Cell>());
        for(int j=0;j<size;j++){
            hexCells[i].push_back(Cell());
            hexCells[i][j].set_cell(board_cells::empty);
            hexCells[i][j].set_row_column(i,static_cast<char>(j+48));
        }
    }
}
template<template<typename...> class T>
void HexAdapter < T >::reset(){
    create_board();
}

template<template<typename...> class T>
Cell& HexAdapter < T >::operator() (const int &index1,const int &index2){
    
    if(index1 >= get_size() || index2 >= get_size() || index1 < 0 || index2 < 0){
        throw InvalidAdressError();
    }
    return hexCells[index1][index2];
}