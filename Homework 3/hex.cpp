#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "hex.h"

int my_atoi(string value);  //This function turns the user input to integer if it is between 1,29 otherwise it returns -1 and the other situations.        

void split_string(const string &str,string &str1,string &str2); // This function takes 3 string and split first string acording to blankspace and assign parts to other two string.                                     

Hex::Hex(){};

Hex::Cell::Cell(){};



Hex::Cell::Cell(int row_num, char column_value, board_cells cell_value)
    :row(row_num),column(column_value)
{}

void Hex::Cell::set_row_column(int row_num,char column_value){
    row = row_num;
    column = column_value;
}
void Hex::Cell::set_cell(board_cells cell_value){
    value = cell_value;
}
Hex::Hex(int size = 5){
    game_size = 5;
}

Hex::Hex(int size,int mode){
    set_size(size);
    set_mode(mode);
}
void Hex::set_size(int size){
    game_size = size;
}
void Hex::set_mode(int mode){
    game_mode = mode;
}
void Hex::set_user(int user_num){
    user = user_num;
}
void Hex::set_computer_moves(int row_num,int column_value){
    computer_row = row_num;
    computer_column =column_value;
}
void Hex::create_board(){
    int size = get_size();
    hexCells.push_back(vector<Hex::Cell>());
    for(int i=0;i<size;i++){
        hexCells.push_back(vector<Hex::Cell>());
        for(int j=0;j<size;j++){
            hexCells[i].push_back(Hex::Cell());
        }
    }
}
void Hex::fill_game_board(){
    for(int i=0;i<game_size;i++){
        for(int j=0;j<game_size;j++){
            hexCells[i][j].set_cell(board_cells::empty);
            hexCells[i][j].set_row_column(i,static_cast<char>(j+48));
        }
    }
}
void Hex::print_game(){
    int size = game_size;
    char temp = 'a';
    for(int i=0;i<size;i++){;
        cout << " " << static_cast<char>(temp+i) << " ";        
    }
    cout << "\n";

    for(int i=0;i<size;i++){
        cout <<i+1;
        for(int j =0;j<i;j++){
            cout << " ";
        }
        for(int j =0;j<size;j++){
            cout << static_cast<char>(hexCells[i][j].get_cell()) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
bool Hex::is_possible(int row_num,char column_value){
	int temp_column = column_value - 64;
	if(temp_column > game_size  || row_num >game_size){
		return false;
	}
	else if(temp_column < 0 || row_num < 0){
		return false;
	}
	if(hexCells[row_num-1][temp_column-1].get_cell() != board_cells::empty){ // check this line
		return false;
	}
	else{
		return true;
	}
}
bool Hex::play(int row_num,char column_value){
    int temp_column = (column_value)-64;
    if(is_possible(row_num,column_value) == false){
        cout << "User" <<user << " entered wrong move.Please Try Again!\n";
        return false;
    }
    else{
        if(user == 1){
            hexCells[row_num-1][temp_column-1].set_cell(board_cells::user1);
        }
        else if(user== 2){
            hexCells[row_num-1][temp_column-1].set_cell(board_cells::user2);
        }
        hexCells[row_num-1][temp_column-1].set_row_column(row_num,column_value);
        return true;
    }
}
bool Hex::test_size(int num){
    if(num < 5){
        return false;
    }
    else{
        return true;
    }
}

void Hex::set_last_user(int num){
    last_user = num;
}
bool Hex::is_finish_user1(int x,int y){
    if(y == game_size-1){
        return true;
    }
    if(hexCells[x][y].get_cell() == board_cells::user1 || hexCells[x][y].get_cell() == board_cells::u_user1){
        if(control_move(x,y+1) == true && hexCells[x][y+1].get_cell() == board_cells::user1){
            hexCells[x][y+1].set_cell(board_cells::u_user1);
            if(is_finish_user1(x,y+1) == true){
                return true;
            }
            hexCells[x][y+1].set_cell(board_cells::user1);
        }
        else if(control_move(x-1,y+1) == true && hexCells[x-1][y+1].get_cell() == board_cells::user1){
            hexCells[x-1][y+1].set_cell(board_cells::u_user1);
            if(is_finish_user1(x-1,y+1) == true){
                return true;
            }
            hexCells[x-1][y+1].set_cell(board_cells::user1);
        }
        else if(control_move(x+1,y) == true && hexCells[x+1][y].get_cell() == board_cells::user1){
            hexCells[x+1][y].set_cell(board_cells::u_user1);
            if(is_finish_user1(x+1,y) == true){
                return true;
            }
            hexCells[x+1][y].set_cell(board_cells::user1);
        }
        else if(control_move(x+1,y-1) == true && hexCells[x+1][y-1].get_cell() == board_cells::user1){
            hexCells[x+1][y-1].set_cell(board_cells::u_user1);
            if(is_finish_user1(x+1,y-1) == true){
            }
            hexCells[x+1][y-1].set_cell(board_cells::user1);
        }
        else if(control_move(x-1,y) == true && hexCells[x-1][y].get_cell() == board_cells::user1){
            hexCells[x-1][y].set_cell(board_cells::u_user1);
            if(is_finish_user1(x-1,y-1) == true){
                return true;
            }
            hexCells[x-1][y].set_cell(board_cells::user1);
        } 
        else if(control_move(x,y-1) == true && hexCells[x][y-1].get_cell() == board_cells::user1){
            hexCells[x][y-1].set_cell(board_cells::u_user1);
            if(is_finish_user1(x,y-1) == true){
                return true;
            }
            hexCells[x][y-1].set_cell(board_cells::user1);
        }                               
    }
    return false;
}
bool Hex::is_finish_user2(int x,int y){
    if(x == game_size-1){
        return true;
    }
    if(hexCells[x][y].get_cell() == board_cells::user2 || hexCells[x][y].get_cell() == board_cells::u_user2){
        if(control_move(x+1,y) == true && hexCells[x+1][y].get_cell() == board_cells::user2){
            hexCells[x+1][y].set_cell(board_cells::u_user2);
            if(is_finish_user2(x+1,y) == true){
                return true;
            }
            hexCells[x+1][y].set_cell(board_cells::user2);
        }
        else if(control_move(x+1,y-1) == true && hexCells[x+1][y-1].get_cell() == board_cells::user2){
            hexCells[x+1][y-1].set_cell(board_cells::u_user2);
            if(is_finish_user2(x+1,y-1) == true){
                return true;
            }
            hexCells[x+1][y-1].set_cell(board_cells::user2);
        }
        else if(control_move(x,y+1) == true && hexCells[x][y+1].get_cell() == board_cells::user2){
            hexCells[x][y+1].set_cell(board_cells::u_user2);
            if(is_finish_user2(x,y+1) == true){
                return true;
            }
            hexCells[x][y+1].set_cell(board_cells::user2);
        }
        else if(control_move(x-1,y+1) == true && hexCells[x-1][y+1].get_cell() == board_cells::user2){
            hexCells[x-1][y+1].set_cell(board_cells::u_user2);
            if(is_finish_user2(x-1,y+1) == true){
                return true;
            }
            hexCells[x-1][y+1].set_cell(board_cells::user2);
        }
        else if(control_move(x,y-1) == true && hexCells[x][y-1].get_cell() == board_cells::user2){
            hexCells[x][y-1].set_cell(board_cells::u_user2);
            if(is_finish_user2(x,y-1) == true){
                return true;
            }
            hexCells[x][y-1].set_cell(board_cells::user2);
        } 
        else if(control_move(x-1,y) == true && hexCells[x-1][y].get_cell() == board_cells::user2){
            hexCells[x-1][y].set_cell(board_cells::u_user2);
            if(is_finish_user2(x-1,y) == true){
                return true;
            }
            hexCells[x-1][y].set_cell(board_cells::user2);
        }                               
    }
    return false;
}
bool Hex::can_control(){
    bool flag =false;
    if(user == 1){
        for(int i=0;i<game_size;i++){
            if(hexCells[i][0].get_cell() == board_cells::user1){
                if(is_finish_user1(i,0) == true){
                    hexCells[i][0].set_cell(board_cells::u_user1);
                    flag = true;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        return flag;
    }
    else{
        for(int i=0;i<game_size;i++){
            if(hexCells[0][i].get_cell() == board_cells::user2){
                if(is_finish_user2(0,i) == true){
                    hexCells[0][i].set_cell(board_cells::u_user2);
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
}
bool Hex::control_move(int row_num,int column_value){
    if(row_num < 0 || column_value< 0){
        return false;
    }
    else{
        
        if(row_num > game_size-1 || (int)column_value > game_size-1){
            return false;
        }
        else{
            return true;
        }
    }
}
void Hex::play(){
    int x = get_computer_row(),y = get_computer_column();
    if(hexCells[0][game_size/2].get_cell() == board_cells::empty){
        set_computer_moves(0,game_size/2);
        hexCells[0][game_size/2].set_cell(board_cells::user2);
    }
    else if(control_move(x+1,y) == true && hexCells[x+1][y].get_cell() == board_cells::empty){
        hexCells[x+1][y].set_cell(board_cells::user2);
        set_computer_moves(x+1,y);
    }
    else if(control_move(x+1,y-1) == true && hexCells[x+1][y-1].get_cell() == board_cells::empty){
        hexCells[x+1][y-1].set_cell(board_cells::user2);
        set_computer_moves(x+1,y-1);
    }
    else if(control_move(x,y-1) == true && hexCells[x][y-1].get_cell() == board_cells::empty){
        hexCells[x][y-1].set_cell(board_cells::user2);
        set_computer_moves(x,y-1);
    }  
    else if(control_move(x,y+1) == true && hexCells[x][y+1].get_cell() == board_cells::empty){
        hexCells[x][y+1].set_cell(board_cells::user2);
        set_computer_moves(x,y+1);
    }
    else if(control_move(x-1,y+1) == true && hexCells[x-1][y+1].get_cell() == board_cells::empty){
        hexCells[x-1][y+1].set_cell(board_cells::user2);
        set_computer_moves(x-1,y+1);
    }
    else if(control_move(x-1,y) == true && hexCells[x-1][y].get_cell() == board_cells::empty){
        hexCells[x-1][y].set_cell(board_cells::user2);
        set_computer_moves(x-1,y);
    }
    else{
        find_location();
        hexCells[get_computer_row()][get_computer_column()].set_cell(board_cells::user2);
    }              
}

void Hex::find_location(){
    int x = game_size;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(hexCells[i][j].get_cell() == board_cells::empty){
                set_computer_moves(j,i);
                break;
            }
        }
    }
}
bool Hex::save_game(string file_name){
    fstream file;
	file.open(file_name,ios::out);
	if(file.fail()){
		cout << "File couldn't open!\n";
		return false;
	}
    if(game_mode == 1){
        file << 1 << endl;
    }
    else{
 	    file << 2 << endl;
	    file << get_computer_row() << endl;
	    file << get_computer_column() << endl;  
    }
    file << last_user << endl;
    file <<game_size<< endl;     
	for(int i=0;i<game_size;i++){
		for(int j=0;j<game_size;j++){
            file << static_cast<char>(hexCells[i][j].get_cell()) ;
		}
		file << endl;
	}
	file.close();
	return true;	
}
bool Hex::compare_games(Hex other){
    int counter1=0,counter2=0;;
    for(int i=0;i<get_size();i++){
        for(int j=0;j<get_size();j++){
            if(hexCells[i][j].get_cell() != board_cells::empty){
                counter1++;
            }
        }
    }
    for(int i=0;i<other.get_size();i++){
        for(int j=0;j<other.get_size();j++){
            if(other.hexCells[i][j].get_cell() != board_cells::empty){
                counter2++;
            }
        }
    }
    if(counter1 > counter2){
        return true;
    }
    else{
        return false;
    }
}
int Hex::mode1(string &file_name){
    game_mode = 1;
    string input,first,second;
    char y;
    int x;
    int control;
    while(1){
        print_game();
        if(get_last_user() != 1){
            user = 1;
            cout << "User 1 should enter the move:(ex: A 1)\n";
            cout << "You can enter LOAD or SAVE with file name to save or load game.\n";
            cout << "Enter 'NEW GAME' to create a new game\n";
            cout << "You can change game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "There is:" << Hex::game_num << "opened game\n" << endl;
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                cout << "Do you want to create a new game?(Yes(1),No(0))\n";
                cin >> control;
                if(control == 1){
                    file_name = second;
                    Hex::game_num++;
                    return -2;
                }
                else{
                    control = load_game(second);
                    return control;
                }
                if(control ==-1){
                    last_user = 2;
                }
                else{

                    break;
                }
            }
            else if(first == "SAVE"){
                control = save_game(second);
                if(control ==false){
                    last_user = 2;
                }            
            }
            else if(first == "NEW" && second == "GAME"){
                Hex::game_num++;
                return -1;
            }
            else if(first == "CHANGE"){
                x = my_atoi(second);
                if(x<0 || x >Hex::game_size){
                    cout << "Game can not found!\n";
                    last_user = 2;
                }
                else{
                    return x;
                }
            }
            else if(first == "EXIT"){
                return 0;
            }            
            else{
                x = my_atoi(second);
                if(first.length() < 2){
                    y = first[0];
                }    
                else{
                    y = '.';
                }
                if(play(x,y) == false){
                    last_user = 2;
                }
                else{
                    last_user = 1;  
                    if(can_control() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print_game();
                        break;
                    }
                }
            }
        }
        else if(get_last_user() != 2){
            user = 2;
            cout << "User 2 should enter the move:(ex: A 1)\n";
            cout << "You can enter LOAD or SAVE with file name to save or load game.\n";
            cout << "Enter 'NEW GAME' to create a new game\n";
            cout << "You can change game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "There is:" << Hex::game_num << "opened game\n" << endl;
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                cout << "Do you want to create a new game?(Yes(1),No(0))\n";
                cin >> control;
                if(control == 1){
                    file_name = second;
                    Hex::game_num++;
                    return -2;                   
                }
                else{
                    control = load_game(second);
                    return control;
                }                
                if(control ==false){
                    last_user = 1;
                }
                else{
                    break;
                }
            }
            else if(first == "SAVE"){
                control = save_game(second);
                if(control ==false){
                    last_user = 1;
                }          
            }
            else if(first == "NEW" && second == "GAME"){
                Hex::game_num++;
                return -1;
            }
            else if(first == "CHANGE"){
                 x = my_atoi(second);
                if(x<0 || x >Hex::game_size){
                    cout << "Game can not found!\n";
                    last_user = 1;
                }
                else{
                    return x;
                }               
            }
            else if(first == "EXIT"){
                return 0;
            }
            else{
                x = my_atoi(second);
                if(first.length() <2){
                    y = first[0];
                }
                else{
                    y = '.';
                }
                if(play(x,y) == false){
                    last_user = 1;
                }
                else{
                    last_user = 2;
                    if(can_control() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print_game();
                        break;
                    }                     
                }
            }            
        }
    }
    return -9;
}
int Hex::playGame(int state,string &file_name){
    int choice;
    int size;
    int control;
    if(state == 1){
        control = load_game(file_name);
        return control;
    }
    else if(state == 2){
        if(game_mode == 1){
            control = mode1(file_name);
            return control;
        }
        else{
            control = mode2(file_name);
            return control;
        }
    }
    while(1){  
        cout << "Enter the size of the board:\n";
        cin  >> size;
        while(test_size(size) == false){
            cout <<"Size of the number can not take this value !" << "Enter the size of the board:\n";
            cin  >> size;   
        }
        cout << "Welcome to HEX!\n" << "1.Human vs Human\n2.Human vs Computer\n3.Exit\n";
        cin >> choice;
        cin.ignore();  
        if(choice == 3){
            cout << "Have a nice day!\n";
            break;
        }       
        else if(choice == 1){
            game_size = size;
            create_board();
            fill_game_board();
            control = mode1(file_name);
            return control;
        }
        else if(choice == 2){
            game_size = size;
            create_board();
            fill_game_board();
            set_computer_moves(0,0);
            control = mode2(file_name);
            return control;
        }
        else{
            cout << "Wrong Choice!\n";
        }
    }
    
    return 0; 
}
int Hex::load_game(string file_name){
    fstream file;
    int temp1,temp2;
    char ch;
    int status;
    file.open(file_name,ios::in);   
    if(file.fail()){
        cerr << "File couldn't open!\n";
        return -1;
    }
    else{
        file >> temp1;
        game_mode = temp1;
        if(temp1 == 2){
            file >> temp1;
            file >> temp2;
            set_computer_moves(temp1,temp2);
        }
        file >> temp1;
        last_user = temp1;
        file >> temp1;
        game_size = temp1;
        create_board();
        for(int i=0;i<game_size;i++){
            for(int j=0;j<game_size;j++){
                file>> ch;
                hexCells[i][j].set_cell(static_cast<board_cells>(ch));
            }
        }
    }
    file.close();
    if(game_mode == 1){
        status = mode1(file_name);
        return status;
    }
    else{
        status = mode2(file_name);
        return status;
    }
}
int Hex::mode2(string &file_name){
    string input,first,second;
    int control;
    game_mode = 2;
    char a;
    int b;
    int counter=0;
    while(1){
        print_game();
        if(last_user != 1){
            user = 1;
            cout << "User 1 should enter the move:(ex: A 1)\n";
            cout << "You can enter LOAD or SAVE with file name to save or load game.\n";
            cout << "Enter 'NEW GAME' to create a new game\n";
            cout << "You can change game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "There is:" << Hex::game_num << "opened game\n" << endl;
            cout << "Type EXIT to quit!\n";
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                cout << "Do you want to create a new game?(Yes(1),No(0))\n";
                cin >> control;
                cin.ignore();
                if(control == 1){
                    file_name = second;
                    Hex::game_num++;
                    return -2;
                }
                else{
                    control = load_game(second);
                    return control;
                }
                if(control ==-1){
                    last_user = 2;
                }
            }
            else if(first == "SAVE"){
                control = save_game(second);
                if(control ==false){
                    last_user = 2;
                }            
            }
            else if(first == "NEW" && second == "GAME"){
                Hex::game_num++;
                return -1;
            }
            else if(first == "CHANGE"){
                b = my_atoi(second);
                if(b<0 || b > Hex::game_num){
                    cout << "Game can not found!\n";
                    last_user = 2;
                }
                else{
                    return b;
                }               
            }
            else if(first == "EXIT"){
                return 0;
            }            
            else{
                a = my_atoi(second);
                if(first.length() < 2){
                    b = first[0];
                }
                else{
                    b = '.';
                }
                if(play(a,b) == false){
                    last_user = 2;
                }
                else{
                    last_user = 1;   
                    if(can_control() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print_game();
                        break;
                    }
                }
            }            
        }
        else if(get_last_user() != 2){
            user = 2;
            play();
            cout << "Computer move is:" << static_cast<char>(get_computer_column()+65) << get_computer_row()+1 << endl;
                last_user = 2;
                if(can_control() == true){
                    cout << "Computer won!\n";
                    print_game();
                    return -9;
                }                     
        }
    }
    return -9;
}
void Hex::increase_marked_cells(){
    int counter =0;
    for(int i=0;i<get_size();i++){
        for(int j=0;j<get_size();j++){
            if(hexCells[i][j].get_cell() != board_cells::empty){
                counter++;
            }
        }
    }
    Hex::marked_cells += counter;
}
void Hex::set_marked_cell(){
    Hex::marked_cells = 0;
}
void Hex::increase_game_num(){
    Hex::game_num += 1; 

}
int my_atoi(string value){
    int size = value.length();
    int counter =0;
    if(size == 1){
        counter = value[0]-48;
    }
    else if(size == 2){
        counter = ((value[0]-48)*10)+(value[1]-48);
    }
    else{
        return -1;
    }
    if(counter < 1 || counter > 29){
        return -1;
    }
    else{
        return counter;
    }
}
void split_string(const string &str,string &str1,string &str2){
    int index;
    index = str.find(' ');
    str1 = str.substr(0,index);
    str2 = str.substr(index+1,str.length());
}  