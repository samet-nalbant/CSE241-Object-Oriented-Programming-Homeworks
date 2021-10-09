#ifndef HEXARRAY1D_H_
#define HEXARRAY1D_H_
#include "abstracthex.h"

namespace hex{
    class HexArray1D:public AbstractHex{

        public:
            HexArray1D();
            HexArray1D(const int &size);
            virtual void reset();
            virtual void create_board() ;
            virtual Cell& operator() (const int &index1,const int &index2);  
            ~HexArray1D(); // Destructor
            HexArray1D& operator = (const HexArray1D &other);
            HexArray1D(const HexArray1D &other);
        private:
            Cell *hexCells;

    };
}

#endif