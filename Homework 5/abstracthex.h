#ifndef ABSTRACTHEX_H_
#define ABSTRACTHEX_H_
#include "cell.h"
#include "error.h"

namespace hex{



    class AbstractHex{
        protected:
            int game_size;
            int game_mode;
            int last_user=2;
            int computer_row,computer_column;
            int mode;
            int user;
            Cell last_move;
            Cell lastMove();// This function returns the Cell object which contains last move.If there is no move on the board it throws error.
            int numberOfMoves(); // This funciton returns the number of maked move on the board.
            void set_lastMove(Cell other); // This function sets the last move.
            bool is_finish_user1(const int &x,const int &y); // This function controls the user 1 which using 'x' symbol whether win or not.If user win it turns the letters bigger.
            bool is_finish_user2(const int &x,const int &y); // // This function controls the user 2 or computer which using 'o' symbol whether win or not.If user win it turns the letters bigger.
            int get_computer_row() const {return computer_row;} // This function returns last computers move's row value.
            int get_computer_column() const {return computer_column;} // This function returns last computers move's column value.
            void set_last_user(int num); // This function sets the last user.
            int get_last_user() const {return last_user;} // This function returns the last user.        
            void set_user(int user_num); // This function sets the current user.
            int get_user() const {return user;} // This function returns current user.       
            void set_mode(int mode);// This function sets game mode.(Human vs. Human or Human vs Computer)
            int get_mode() const {return game_mode;} // This function return game mode.
            
            void set_computer_moves(int now_num,int column_value); // This function sets computer moves.
            void find_location();// This function find free location on the table.
            bool isEnd(); // It controls the game finished or not if it's finisihed it returns true.
            bool control_move(int row_num,int column_value); // This function checks the validty of users moves.      
            int mode2(string &file_name);// This function runs the human vs computer mode.
            int mode1(string &file_name);// This function runs the human vs human mode.
            bool is_possible(int row_num,char column_value); // This function checks locations from computer whether it is possible to move there or not.                                 
        public:
            AbstractHex();
            int get_size() const {return game_size;} // This function return game size.
            bool setSize(int size); // This function sets the size.
            virtual void reset()  = 0;
            virtual void create_board() = 0;
            virtual Cell& operator() (const int &index1,const int &index2) =0;
            bool operator == (AbstractHex &other); // This function the two games whether equal or not. 
            int readFromFile(string fale_name); // This function load game from file which taken as an argument.
            bool writeToFile(string file_name); // This function save game to file which taken as an argument.
            bool play(int row_num,char column_value); // This function makes user's moves.
            void play(); // This function makes computer's moves.
            void print(); // This function print game to terminal.
            int playGame(int state,string &file_name); // This function starts game.Takes game size,game mode etc. in this function.
                    
        private:


    };

}
int my_atoi(string value);
void split_string(const string &str,string &str1,string &str2); 
#endif