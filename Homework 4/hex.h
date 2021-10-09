#ifndef HW2_H_
#define HW2_H_
enum class board_cells{user1 = 'x',u_user1 = 'X',user2 = 'o',u_user2 = 'O',empty='.'};
class Hex{
	public:
	        class Cell{
		public:
                        Cell(int row_num, char column_value, board_cells cell_value);
                        Cell();
                        void set_row_column(int row_num,char column_value); // This function set column and row for cell.
                        void set_cell(board_cells cell_value); //This function set cell acording to board cells value.
                        char get_column()const {return column;} // This function returns column value.
                        int get_row() const {return row;}  // This function returns row value.
                        board_cells get_cell(){return value;} // This function returns cell value.
	        private:	
                        char column;
                        int row;
                        board_cells value;
	        };

        int get_games_num(){return game_num;}
        static int get_marked_cells(){return marked_cells;} // This static function returns number of marked cells.
        void increase_game_num();
        void set_marked_cell(); // This function sets number of marked cells to zero.
        bool operator ==(const Hex &other) const; // This overloaded operator checks the marked cell for two game.If they are same amount marked cells it returns true otherwise it returns false. 
        friend ostream & operator << (ostream &output_stream,const Hex& board); // Operator overloading for output.
        friend fstream & operator >>(fstream &input,Hex& board);   // Operator overloading for stream input.     
        friend fstream & operator << (fstream &output,Hex& board); // Operator overloading for fstream output.
        void increase_marked_cells(); // This function increase the mark cell for one game.
        explicit Hex(int size);
        explicit Hex(int size,int mode);
        Hex();
        ~Hex(); // Destructor
        Hex& operator = (const Hex &other); // Copy Constructor
        Hex(const Hex &other);
        int playGame(int state,string &file_name); // This functions starts the game.According to state value it starts loaded game or changed game.        
        void set_move_number(int x);
        
        private:
        
        void new_move(Cell x);
        void add_visited(Cell x);
        Cell **hexCells = nullptr ;  
        Cell *moves = nullptr;    
        Cell *visited = nullptr;
        int number_of_visited_cell=0;
        void find_score_user2(int x,int y); // This function finds the score for user2 and computer.
        void find_score_user1(int x,int y); // This function finds the score for user1.
        int score_u1=0;
        int score_u2=0;
        int temp_score=0;
        int game_size;
        int game_mode;
        int last_user=2;
        bool is_visited(Cell x); // This function checks the x cell whether visited or not.
        Cell play(); // This functions makes computer moves.
        bool is_possible(int row_num,char column_value); // This function checks locations from computer whether it is possible to move there or not.
        int user;
        bool test_size(int num); // This function tests the validity of size.
        int mode1(string &file_name); // This function runs the human vs human mode.Acording to selections from user it returns a value.Change game,new game or etc.
        int mode2(string &file_name);// This function runs the human vs computer mode.Acording to selections from user it returns a value.Change game,new game or etc.
        bool is_finish_user1(int x,int y); // This function controls the user 1 which using 'x' symbol whether win or not.If user win it turns the letters bigger.
        bool is_finish_user2(int x,int y); // // This function controls the user 2 or computer which using 'o' symbol whether win or not.If user win it turns the letters bigger.
        bool can_control(); // It controls the game finished or not if it's finisihed it returns true.
        bool control_move(int row_num,int column_value); // This function checks the validty of users moves.
        int computer_row,computer_column;
        void set_computer_moves(int now_num,int column_value); // This function sets computer moves.
        void find_location();// This function find free location on the table.
        int mode;
        bool save_game(string file_name); // This function save the games to file.It returns true or false.
        int load_game(string fale_name); // This fundction laod games from file.According to loading and creating new file it returns control value.
        static int marked_cells;     
        int get_computer_row() const {return computer_row;} // This function returns last computers move's row value.
        int get_computer_column() const {return computer_column;} // This function returns last computers move's column value.
        Cell play(int row_num,char column_value);  // This functions play for user1 or user2.
        void set_size(int size); // This function sets the size.
        void set_mode(int mode);// This function sets game mode.(Human vs. Human or Human vs Computer)
        int get_mode() const {return game_mode;} // This function return game mode.
        int get_size() const {return game_size;} // This function return game size.
        void set_user(int user_num); // This function sets the current user.
        int get_user() const {return user;} // This function returns current user.
        void print_game(); // This function prints game.
        void fill_game_board(); // This function fill game boards with empty cells. 
        void create_board();   // This function resize the Hex vectors inside the private section acordding to game_size value.
        void set_last_user(int num); // This function sets the last user.
        int get_last_user() const {return last_user;} // This function returns the last user.
        static int game_num; 
        int number_of_move =0;
        void increment_number_of_move();// This function increment the number of maked move.
        void decrement_number_of_move();// This function decrement the number of maked move.
        int get_number_of_move(){return number_of_move;}
        Hex& operator --(int x); // This operator overloaded for undo.
        Hex& operator --();// This operator overloaded for undo.
        int get_width() const {return game_size;}  // This function returns the width value.
        int get_height() const {return game_size;} // This function return height value.
};
#endif
