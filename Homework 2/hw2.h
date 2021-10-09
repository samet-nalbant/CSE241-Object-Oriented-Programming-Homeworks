#ifndef HW2_H_
#define HW2_H_

void fill_table(char table[12][12],int size); // This function that i create fills table to with '.'

void print_table(char table[12][12],int size); // This function that i create print table.

int is_possible(int line,char column,char table[12][12],int size); // This function checks locations from user whether it is possible to move there or not.

void fill_move(int line,char column,char move,char table[12][12]); // This function makes the user move on the table array.It's also type casting for finding column.

int is_finish_user1(char table[12][12],int x,int y,int size); // This function controls the user 1 which using 'x' symbol whether win or not.If user win it turns the letters bigger.

int control_finish(char table[12][12],char move,int size); // This function checks the game can finish if it can finish it calls the is_finish_user depends on the move argument.

int check_in(int x,int y,int size); // This function checks x and y whether they are inside of the table or not.

int is_finish_user2(char table[12][12],int x,int y,int size); // This function controls the user 1 which using 'o' symbol whether win or not.If user win it turns the letters bigger.

void pc_turn(char table[12][12],int size,int move,int *x,int *y); // This function move o on the table for computer.If it can't move for any direction(stucked) it calls find_loc function and find free location.

void find_loc(char table[12][12],int size,int *x,int *y); // This function find free location on the table.

void mod1(char table[12][12],int &size ,int &last_user,int &x,int &y,int a =0); // This function runs the human vs human mode.According to value of 'a' it starts from the begining or from saved game. 

void mod2(char table[12][12],int &size ,int &last_user,int &x,int &y,int a =0); // This function runs the human vs computer mode.According to value of 'a' it starts from the begining or from saved game.

enum class game_types{humvshum,humvscomp};

enum class board_cells{x,X,o,O,pt};

int save_game(char table[12][12],game_types mode,const int &size,const int &last_user,const string file_name); // This function save game for human vs humand mod.It takes table,board size,last user and file name to save.

int load_game(char table[12][12],game_types &mode,int &size,int &last_user,const string file_name,int &x,int &y); // This function load game according to file name.It runs according to type of game mode.It returns 0 if file couldnt open.If the game finish it returns 1 and it's provide to finish game.

int save_game(char table[12][12],game_types mode,const int &size,const int &last_user,const string file_name,int x,int y); // This function save for human vs computer mode.They are overlaping functions.

int my_atoi(string value); // This function turns the user input to integer if it is between 1,12 otherwise it returns -1 and the other situations.


#endif