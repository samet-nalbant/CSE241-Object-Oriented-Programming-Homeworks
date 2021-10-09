#ifndef HEXADAPTER_H_
#define HEXADAPTER_H_
#include "abstracthex.h"

namespace hex{

    template<template<typename...> class T>
    class HexAdapter:public AbstractHex{

        public:
            HexAdapter();
            HexAdapter(const int &size);
            void reset();
            void create_board() ;
            Cell &operator() (const int &index1,const int &index2);        


        private:
            T<T<Cell>> hexCells;

    };

}
#endif