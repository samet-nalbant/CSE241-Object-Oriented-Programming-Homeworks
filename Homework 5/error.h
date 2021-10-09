#ifndef ERROR_H_
#define ERROR_H_

#include <exception>
#include <stdexcept>

namespace hex{
    class InvalidAdressError:public runtime_error{
        public:
        InvalidAdressError():runtime_error("You can not access this adress\n"){};
    };
    class EmptyBoardError:public runtime_error{
        public:
        EmptyBoardError():runtime_error("There is no move on the board"){};
    };
}

#endif