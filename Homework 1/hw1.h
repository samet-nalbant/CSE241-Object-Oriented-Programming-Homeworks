#ifndef HW1_H_
#define HW1_H_

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

void mod1(); // This function runs mod1.

void mod2(); // This function runs mod2.

#endif