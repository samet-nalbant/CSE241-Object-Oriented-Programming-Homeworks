#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "abstracthex.h"
using namespace hex;
AbstractHex::AbstractHex(){
}
void AbstractHex::set_last_user(int num){
    last_user = num;
}

void AbstractHex::set_user(int user_num){
    user = user_num;
}
bool AbstractHex::setSize(int size){
    if(size < 5){
        return false;
    }
    game_size = size;
    return true;
}
void AbstractHex::set_mode(int mode){
    game_mode = mode;
}
void AbstractHex::set_computer_moves(int row_num,int column_value){
    computer_row = row_num;
    computer_column =column_value;
}
void AbstractHex::find_location(){
    int x = get_size();
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if((*this)(i,j).get_cell() == board_cells::empty){
                set_computer_moves(j,i);
                break;
            }
        }
    }
}
bool AbstractHex::isEnd(){
    bool flag =false;
    if(get_user() == 1){
        for(int i=0;i<get_size();i++){
            if((*this)(i,0).get_cell() == board_cells::user1){
                if(is_finish_user1(i,0) == true){
                    (*this)(i,0).set_cell(board_cells::u_user1);
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
        for(int i=0;i<get_size();i++){
            if((*this)(0,i).get_cell() == board_cells::user2){
                if(is_finish_user2(0,i) == true){
                    ((*this))(0,i).set_cell(board_cells::u_user2);
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
}
void AbstractHex::set_lastMove(Cell other){
    last_move.set_cell(other.get_cell());
    last_move.set_row_column(other.get_row(),other.get_column());
}
Cell AbstractHex::lastMove(){
    if(last_move.get_cell() == board_cells::empty){
        throw EmptyBoardError();
    }
    else{
        return last_move;
    }
}
int AbstractHex::numberOfMoves(){
    int counter =0;
    for(int i=0;i<get_size();i++){
        for(int j=0;j<get_size();j++){
            if((*this)(i,j).get_cell() != board_cells::empty){
                counter++;
            }
        }
    }
    return counter;
}
bool AbstractHex::operator == (AbstractHex &other){
    if(get_size() != other.get_size()){
        return false;
    }
    for(int i=0;i<get_size();i++){
        for(int j=0;j<get_size();j++){
            if((*this)(i,j).get_cell() != other(i,j).get_cell()){
                return false;
            }
        }
    }
    return true;
}
bool AbstractHex::control_move(int row_num,int column_value){
    if(row_num < 0 || column_value< 0){
        return false;
    }
    else{
        
        if(row_num >get_size()-1 || (int)column_value > get_size()-1){
            return false;
        }
        else{
            return true;
        }
    }
}

bool AbstractHex::is_possible(int row_num,char column_value){
	int temp_column = column_value - 64;
	if(temp_column > get_size()  || row_num >get_size()){
		return false;
	}
	else if(temp_column < 0 || row_num < 0){
		return false;
	}
	if((*this)(row_num-1,temp_column-1).get_cell() != board_cells::empty){ // check this line
		return false;
	}
	else{
		return true;
	}
}
bool AbstractHex::writeToFile(string file_name){
    fstream file;
	file.open(file_name,ios::out);
	if(file.fail()){
		cout << "File couldn't open!\n";
		return false;
	}
    if(get_mode() == 1){
        file << 1 << endl;
    }
    else{
 	    file << 2 << endl;
	    file << get_computer_row() << endl;
	    file << get_computer_column() << endl;  
    }
    file << get_last_user() << endl;
    file << get_size() << endl;     
	for(int i=0;i<get_size();i++){
		for(int j=0;j<get_size();j++){
            file << static_cast<char>((*this)(i,j).get_cell()) ;
		}
		file << endl;
	}
	file.close();
	return true;
}
int AbstractHex::readFromFile(string file_name){
    fstream file;
    int temp1,temp2,tempSize;
    char ch;
    int status;
    tempSize = game_size;
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
        if(temp1 < 5){
            cerr << "File has wrong size!\n";
            return -1;
        }
        game_size = temp1;
        create_board();
        for(int i=0;i<game_size;i++){
            for(int j=0;j<game_size;j++){
                file>> ch;
                if(ch != 'o' && ch != 'x' && ch != '.' && ch != 'X' && ch != 'O'){
                    cerr << "File has wrong move!\n";
                    game_size = tempSize;
                    create_board();
                    reset();
                    return -1;
                }
                (*this)(i,j).set_cell(static_cast<board_cells>(ch));
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

void AbstractHex::print(){
    int size = get_size();
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
            
            cout << static_cast<char>((*this)(i,j).get_cell()) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
bool AbstractHex::play(int row_num,char column_value){
    int temp_column = (column_value)-64;
    if(is_possible(row_num,column_value) == false){
        cout << "User" <<user << " entered wrong move.Please Try Again!\n";
        return false;
    }
    else{
        if(user == 1){
            (*this)(row_num-1,temp_column-1).set_cell(board_cells::user1);
            last_move.set_cell(board_cells::user1);
        }
        else if(user== 2){
           (*this)(row_num-1,temp_column-1).set_cell(board_cells::user2);
        }
       (*this)(row_num-1,temp_column-1).set_row_column(row_num,column_value);
        last_move.set_row_column(row_num,column_value);
        return true;
    }
}
void AbstractHex::play(){
    int x = get_computer_row(),y = get_computer_column();
    if((*this)(0,game_size/2).get_cell() == board_cells::empty){
        set_computer_moves(0,game_size/2);
        (*this)(0,game_size/2).set_cell(board_cells::user2);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else if(control_move(x+1,y) == true && (*this)(x+1,y).get_cell() == board_cells::empty){
        (*this)(x+1,y).set_cell(board_cells::user2);
        set_computer_moves(x+1,y);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else if(control_move(x+1,y-1) == true && (*this)(x+1,y-1).get_cell() == board_cells::empty){
        (*this)(x+1,y-1).set_cell(board_cells::user2);
        set_computer_moves(x+1,y-1);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else if(control_move(x,y-1) == true && (*this)(x,y-1).get_cell() == board_cells::empty){
        (*this)(x,y-1).set_cell(board_cells::user2);
        set_computer_moves(x,y-1);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }  
    else if(control_move(x,y+1) == true && (*this)(x,y+1).get_cell() == board_cells::empty){
        (*this)(x,y+1).set_cell(board_cells::user2);
        set_computer_moves(x,y+1);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else if(control_move(x-1,y+1) == true && (*this)(x-1,y+1).get_cell() == board_cells::empty){
        (*this)(x-1,y+1).set_cell(board_cells::user2);
        set_computer_moves(x-1,y+1);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else if(control_move(x-1,y) == true && (*this)(x-1,y).get_cell() == board_cells::empty){
        (*this)(x-1,y).set_cell(board_cells::user2);
        last_move.set_cell(board_cells::user2);

        set_computer_moves(x-1,y);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }
    else{
        find_location();
        (*this)(get_computer_row(),get_computer_column()).set_cell(board_cells::user2);
        last_move.set_cell(board_cells::user2);
        last_move.set_row_column(get_computer_row(),get_computer_column());
    }         
}
int AbstractHex::mode1(string &file_name){
    game_mode = 1;
    string input,first,second;
    char y;
    int x;
    int control;
    while(1){
        print();
        if(get_last_user() != 1){
            user = 1;
            cout << "User 1 should enter the move:(ex: A 1)\n";
            cout << "You can enter LOAD or SAVE with file name to save or load game.\n";
            cout << "Enter 'NEW GAME' to create a new game\n";
            cout << "You can change size of the game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "You can reset game by typing RESET\n";
            cout << "You can see the last move by typing LAST MOVE:\n";
            cout << "You can see the number of steps by typing MOVE NUMBER\n";
            cout << "You can control the game whether finish or not by typing IS END\n";
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                control = readFromFile(second);
                if(control == false){
                    last_user = 2;
                }
                else{
                    return control;
                }

            }
            else if(first == "SAVE"){
                control = writeToFile(second);
                if(control ==false){
                    last_user = 2;
                }            
            }
            else if(first == "NEW" && second == "GAME"){
                return -1;
            }
            else if(first == "CHANGE"){
                if(setSize(my_atoi(second)) != true){
                    cout << "Size can not take this value!\n" << endl;
                }
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "RESET"){
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "LAST" && second == "MOVE"){
                try
                {

                    cout << "Last move is:"  << lastMove().get_column() <<  lastMove().get_row()<< endl;
                }
                catch(const EmptyBoardError& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
                
            }
            else if(first == "MOVE" && second == "NUMBER"){
                cout << "There is :" << numberOfMoves() << " move on the board\n";
            }
            else if(first == "IS" && second == "END"){
                if(isEnd() == false){
                    cout << "Game has not finished yet.\n";
                }
                else{
                    cout << "Game is already finished\n";
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
                    if(isEnd() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print();
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
            cout << "You can change size of the game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "You can reset game by typing RESET\n";
            cout << "You can see the last move by typing LAST MOVE:\n";
            cout << "You can see the number of steps by typing MOVE NUMBER\n";
            cout << "You can control the game whether finish or not by typing IS END\n";
            cout << "Type EXIT to return to menu.\n";
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                file_name = second;       
                control = readFromFile(second);              
                if(control ==false){
                    last_user = 1;
                }
                else{
                    return control;
                }

            }
            else if(first == "SAVE"){
                control = writeToFile(second);
                if(control ==false){
                    last_user = 1;
                }          
            }
            else if(first == "NEW" && second == "GAME"){
                return -1;
            }
            else if(first == "CHANGE"){
                if(setSize(my_atoi(second)) != true){
                    cout << "Size can not take this value!\n" << endl;
                }
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "RESET"){
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "LAST" && second == "MOVE"){
                try
                {
                    cout << "Last move is:"  << lastMove().get_column() <<  lastMove().get_row()<< endl;
                }
                catch(const EmptyBoardError& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            else if(first == "MOVE" && second == "NUMBER"){
                cout << "There is :" << numberOfMoves() << "move on the board\n";
            }
            else if(first == "IS" && second == "END"){
                if(isEnd() == false){
                    cout << "Game has not finished yet.\n";
                }
                else{
                    cout << "Game is already finished\n";
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
                    if(isEnd() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print();
                        break;
                    }                     
                }
            }            
        }
    }
    return -9;
}
int AbstractHex::mode2(string &file_name){
    string input,first,second;
    int control;
    game_mode = 2;
    char a;
    int b;
    int counter=0;
    while(1){
        print();
        if(last_user != 1){
            user = 1;
            cout << "User 1 should enter the move:(ex: A 1)\n";
            cout << "You can enter LOAD or SAVE with file name to save or load game.\n";
            cout << "Enter 'NEW GAME' to create a new game\n";
            cout << "You can change size of the game with typing CHANGE NUMBER.(ex: CHANGE 2)\n";
            cout << "You can reset game by typing RESET\n";
            cout << "You can see the last move by typing LAST MOVE:\n";
            cout << "You can see the number of steps by typing MOVE NUMBER\n";
            cout << "You can control the game whether finish or not by typing IS END\n";
            cout << "Type EXIT to return to menu.\n";
            getline(cin,input);
            split_string(input,first,second);
            if(first == "LOAD"){
                control = readFromFile(second);
                if(control ==-1){
                    last_user = 2;
                }
                else{
                    return control;
                }
            }
            else if(first == "SAVE"){
                control = writeToFile(second);
                if(control ==false){
                    last_user = 2;
                }            
            }
            else if(first == "NEW" && second == "GAME"){
                return -1;
            }
            else if(first == "CHANGE"){
                if(setSize(my_atoi(second)) != true){
                    cout << "Size can not take this value!\n" << endl;
                }
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "RESET"){
                reset();
                last_move.set_cell(board_cells::empty);
                last_user = 2;
            }
            else if(first == "LAST" && second == "MOVE"){
                try
                {
                    cout << "Last move is:"  << static_cast<char>(lastMove().get_column()+ 65)  <<  lastMove().get_row()+1<< endl;
                }
                catch(const EmptyBoardError& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            else if(first == "MOVE" && second == "NUMBER"){
                cout << "There is :" << numberOfMoves() << "move on the board\n";
            }
            else if(first == "IS" && second == "END"){
                if(isEnd() == false){
                    cout << "Game has not finished yet.\n";
                }
                else{
                    cout << "Game is already finished\n";
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
                    if(isEnd() == true){
                        cout << "User1 Won!\n";
                        last_user = 2;
                        print();
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
                if(isEnd() == true){
                    cout << "Computer won!\n";
                    print();
                    return -9;
                }                 
        }
    }
    return -9;
}
void split_string(const string &str,string &str1,string &str2){
    int index;
    index = str.find(' ');
    str1 = str.substr(0,index);
    str2 = str.substr(index+1,str.length());
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
bool AbstractHex::is_finish_user1(const int &x,const int &y){
    if(y == game_size-1){
        return true;
    }
    if(control_move(x,y) == true && (*this)(x,y).get_cell() == board_cells::user1 || (*this)(x,y).get_cell() == board_cells::u_user1){
        if(control_move(x,y+1) == true && (*this)(x,y+1).get_cell() == board_cells::user1){
            (*this)(x,y+1).set_cell(board_cells::u_user1);
            if(is_finish_user1(x,y+1) == true){
                return true;
            }
            (*this)(x,y+1).set_cell(board_cells::user1);
        }
        else if(control_move(x-1,y+1) == true && (*this)(x-1,y+1).get_cell() == board_cells::user1){
           (*this)(x-1,y+1).set_cell(board_cells::u_user1);
            if(is_finish_user1(x-1,y+1) == true){
                return true;
            }
            (*this)(x-1,y+1).set_cell(board_cells::user1);
        }
        else if(control_move(x+1,y) == true && (*this)(x+1,y).get_cell() == board_cells::user1){
            (*this)(x+1,y).set_cell(board_cells::u_user1);
            if(is_finish_user1(x+1,y) == true){
                return true;
            }
            (*this)(x+1,y).set_cell(board_cells::user1);
        }
        else if(control_move(x+1,y-1) == true && (*this)(x+1,y-1).get_cell() == board_cells::user1){
            (*this)(x+1,y-1).set_cell(board_cells::u_user1);
            if(is_finish_user1(x+1,y-1) == true){
                return true;
            }
            (*this)(x+1,y-1).set_cell(board_cells::user1);
        }
        else if(control_move(x-1,y) == true && (*this)(x-1,y).get_cell() == board_cells::user1){
            (*this)(x-1,y).set_cell(board_cells::u_user1);
            if(is_finish_user1(x-1,y) == true){
                return true;
            }
            (*this)(x-1,y).set_cell(board_cells::user1);
        } 
        else if(control_move(x,y-1) == true && (*this)(x,y-1).get_cell() == board_cells::user1){
            (*this)(x,y-1).set_cell(board_cells::u_user1);
            if(is_finish_user1(x,y-1) == true){
                return true;
            }
            (*this)(x,y-1).set_cell(board_cells::user1);
        }                               
    }
    return false;
}
bool AbstractHex::is_finish_user2(const int &x,const int &y){
    if(x == game_size-1){
        return true;
    }
    if(control_move(x,y) == true && (*this)(x,y).get_cell() == board_cells::user2 || (*this)(x,y).get_cell() == board_cells::u_user2){
        if(control_move(x+1,y) == true && (*this)(x+1,y).get_cell() == board_cells::user2){
            (*this)(x+1,y).set_cell(board_cells::u_user2);
            if(is_finish_user2(x+1,y) == true){
                return true;
            }
            (*this)(x+1,y).set_cell(board_cells::user2);
        }
        else if(control_move(x+1,y-1) == true && (*this)(x+1,y-1).get_cell() == board_cells::user2){
            (*this)(x+1,y-1).set_cell(board_cells::u_user2);
            if(is_finish_user2(x+1,y-1) == true){
                return true;
            }
            (*this)(x+1,y-1).set_cell(board_cells::user2);
        }
        else if(control_move(x,y+1) == true && (*this)(x,y+1).get_cell() == board_cells::user2){
            (*this)(x,y+1).set_cell(board_cells::u_user2);
            if(is_finish_user2(x,y+1) == true){
                return true;
            }
            (*this)(x,y+1).set_cell(board_cells::user2);
        }
        else if(control_move(x-1,y+1) == true && (*this)(x-1,y+1).get_cell() == board_cells::user2){
            (*this)(x-1,y+1).set_cell(board_cells::u_user2);
            if(is_finish_user2(x-1,y+1) == true){
                return true;
            }
            (*this)(x-1,y+1).set_cell(board_cells::user2);
        }
        else if(control_move(x,y-1) == true && (*this)(x,y-1).get_cell() == board_cells::user2){
            (*this)(x,y-1).set_cell(board_cells::u_user2);
            if(is_finish_user2(x,y-1) == true){
                return true;
            }
            (*this)(x,y-1).set_cell(board_cells::user2);
        } 
        else if(control_move(x-1,y) == true && (*this)(x-1,y).get_cell() == board_cells::user2){
            (*this)(x-1,y).set_cell(board_cells::u_user2);
            if(is_finish_user2(x-1,y) == true){
                return true;
            }
           (*this)(x-1,y).set_cell(board_cells::user2);
        }                               
    }
    return false;
}
int AbstractHex::playGame(int state,string &file_name){
    int choice;
    int size;
    int control;
    last_move.set_cell(board_cells::empty);
    while(1){  
        cout << "Enter the size of the board:\n";
        cin  >> size;
        while(setSize(size) != true){
            cout <<"Size of the number can not take this value !" << "Enter the size of the board:\n";
            cin  >> size;   
        }
        cout << "Welcome to HEX!\n" << "1.Human vs Human\n2.Human vs Computer\n3.Exit\n";
        cin >> choice;
        cin.ignore();  
        if(choice == 3){
            break;
        }       
        else if(choice == 1){
            create_board();
            control = mode1(file_name);
            return control;
        }
        else if(choice == 2){
            create_board();
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