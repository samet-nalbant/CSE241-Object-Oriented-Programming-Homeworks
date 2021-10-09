#ifndef HEXVECTOR_H_
#define HEXVECTOR_H_
#include "abstracthex.h"

namespace hex{

    class HexVector:public AbstractHex{

        public:
            HexVector();
            HexVector(const int &size);
            void reset();
            void create_board() ;
            Cell &operator() (const int &index1,const int &index2);        


        private:
            vector<vector<Cell>> hexCells;

    };
}
#endif