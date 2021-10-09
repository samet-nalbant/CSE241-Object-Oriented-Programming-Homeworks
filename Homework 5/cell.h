#ifndef CELL_H_
#define CELL_H_
namespace hex{
	enum class board_cells{user1 = 'x',u_user1 = 'X',user2 = 'o',u_user2 = 'O',empty='.'};
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

}

#endif
