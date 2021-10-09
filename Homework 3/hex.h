#ifndef HW2_H_
#define HW2_H_
enum class board_cells{user1 = 'x',u_user1 = 'X',user2 = 'o',u_user2 = 'O',empty='.'};
class Hex{
	private:
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
        int game_size;
        int game_mode;
        int last_user=2;
        vector<vector<Cell>> hexCells;
        void play(); // This functions makes computer moves.
        bool is_possible(int row_num,char column_value); // This function checks locations from computer whether it is possible to move there or not.
        int user;
        bool test_size(int num); // This function tests the validity of size.
        int mode1(string &file_name);
        void mod1(char table[12][12],int &size ,int &last_user,int &x,int &y,int a =0); // This function runs the human vs human mode.Acording to selections from user it returns a value.Change game,new game or etc.
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
        bool play(int row_num,char column_value);  // This functions play for user1 or user2.
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

	public: 
        int get_games_num(){return game_num;}
        static int get_marked_cells(){return marked_cells;} // This static function returns number of marked cells.
        void increase_game_num();
        int get_width() const {return game_size;}  // This function returns the width value.
        int get_height() const {return game_size;} // This function return height value.
        void set_marked_cell(); // This function sets number of marked cells to zero.
        bool compare_games(Hex other); // This function compare the two games acording to number of marked cells.
        void increase_marked_cells(); // This function increase the mark cell for one game.
        Hex(int size);
        Hex(int size,int mode);
        Hex();
        int playGame(int state,string &file_name); // This functions starts the game.According to state value it starts loaded game or changed game.
};































#endif