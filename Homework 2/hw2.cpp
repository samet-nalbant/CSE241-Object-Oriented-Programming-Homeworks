#include<iostream>
#include <fstream>
#include <string>
using namespace std;
#include "hw2.h"

void mod1(char table[12][12],int &size,int &last_user,int &x,int &y,int a){
	char column,move;
	int line;
	int control;
	game_types mode =  game_types::humvshum;
	string first,second;
	if(a == 0){
		cout << "Enter the size of the table.(between 6-12)\n";
		cin >> size;
		if(size< 6 || size > 12){
			while(size< 6 || size > 12){
				cout << "Size can not take this number.Try Again!\n";
				cout << "Enter the size of the table\n";
				cin >> size;
			}
		}
		fill_table(table,size);
		last_user =2;			
	}	
	while(1){
		print_table(table,size);
		if(last_user != 1){
			cout << "User 1 should enter the move:(ex: A 1)\n";
			cin >> first;
			cin >> second;
			if(first == "LOAD"){
				control =load_game(table,mode,size,last_user,second,x,y) ;
				if( control == 0){
					last_user = 2;
				}
				else if(control == 1){
					break;
				}
			}
			else if(first == "SAVE"){
				save_game(table,mode,size,last_user,second);
			}
			else{
				column = first[0];
				line = my_atoi(second);
				if(is_possible(line,column,table,size) == 0 || first.length() > 1){
					cout << "User 1 entered wrong move.Try Again!\n";
					last_user = 2;
				}
				else{
					fill_move(line,column,'x',table);
					if(control_finish(table,'x',size) == 1){
						cout << "User1 Won!\n";
						print_table(table,size);
						break;
					}
					print_table(table,size);
					last_user = 1;	
				}
	
			}
		}
		if(last_user != 2){
			cout << "User 2 should enter the move:(ex: A 2)\n";
			cin >> first;
			cin >> second;
			if(first == "LOAD"){
				control = load_game(table,mode,size,last_user,second,x,y);
				if(control == 0){
					last_user = 2;
				}
				else if(control ==1){
					break;
				}
			}
			else if(first == "SAVE"){
				save_game(table,mode,size,last_user,second);
			}
			else{
				column = first[0];
				line = my_atoi(second);
				if(is_possible(line,column,table,size) ==0 || first.length() > 1){
					cout << "User 2 entered wrong move.Try Again!\n";
					last_user = 1;
				}
				else{
					fill_move(line,column,'o',table);
					if(control_finish(table,'o',size) == 1){
						cout << "User2 Won!\n";
						print_table(table,size);
						break;
					}
					last_user = 2;						
				}	
				
			}
		
		}
	}		
}

void mod2(char table[12][12],int &size,int &last_user,int &x,int &y,int a){
	auto flag = 0;
	int choice,line;
	int control;
	game_types mode = game_types :: humvscomp;
	string first,second;
	char column,move;
	decltype(choice) counter =0;
	if(a == 0){
		cout << "Enter the size of the table.(between 6-12)\n";
		cin >> size;
		if(size< 6 || size > 12){
			while(size< 6 || size > 12){
				cout << "Size can not take this number.Try Again!\n";
				cout << "Enter the size of the table\n";
				cin >> size;
			}
		}
			fill_table(table,size);	
			last_user = 2;	
	}
	while(1){
		print_table(table,size);
		if(last_user != 1){
			cout << "User 1 should enter the move:(ex: A 1)\n";
			cin >> first;
			cin >> second;
			if(first == "LOAD"){
				control = load_game(table,mode,size,last_user,second,x,y);
				if(control == 0){
					last_user = 2;
				}
				else if(control == 1){
					break;
				}
			}
			else if(first == "SAVE"){
				save_game(table,mode,size,last_user,second,x,y);
			}
			else{
				column = first[0];
				line = my_atoi(second);
				if(is_possible(line,column,table,size) == 0 || first.length()>1){
					cout << "User 1 entered wrong move.Try Again!\n";
					last_user = 2;	
				}
				else{
					fill_move(line,column,'x',table);
					if(control_finish(table,'x',size) == 1){
						cout << "User Won!\n";
						print_table(table,size);
						break;
					}
					print_table(table,size);
					last_user = 1;					
				}

			}				
		}
		if(last_user !=2){
			if(a == 1){
				pc_turn(table,size,1,&x,&y);
			}
			else{
				pc_turn(table,size,counter,&x,&y);
			}
			cout << "Computer num:" << x << "y:" << y << endl;
			column = y+65;
			cout << "Computer Move:" << column << x+1 << "\n";
			counter++;
			if(control_finish(table,'o',size) == 1){
				cout << "Computer Won\n";
				print_table(table,size);
				break;
			}	
			last_user = 2;		
		}
	}
}
void fill_table(char table[12][12],int size){
	for(int i=0;i<size;i++){
		for(int j =0;j<size;j++){
			table[i][j] = '.';
		}
	}
}
void print_table(char table[12][12],int size){
	for(int i=0;i<size;i++){
		cout << " " << (char)(97+i) << " ";
	}
	cout << "\n";
	for(int i=0;i<size;i++){
		cout <<i+1;
		for(int j =0;j<i;j++){
			cout << " ";
		}
		
		for(int j =0;j<size;j++){
			cout << table[i][j] << "  ";
		}
		cout << "\n";
	}
}
int is_possible(int line,char column,char table[12][12],int size){
	int temp = column - 64;
	if(temp > size  || line >size){
		return 0;
	}
	else if(temp <= 0 || line <= 0){

		return 0;
	}
	if(table[line-1][temp-1] != '.'){
	
		return 0;
	}
	else{
		return 1;
	}
}

void fill_move(int line,char column,char move,char table[12][12]){
	int temp = column-64;
	table[line-1][temp-1] = move;

}

int control_finish(char table[12][12],char move,int size){
	int flag = 0;
	if(move == 'x'){
		for(int i=0;i<size;i++){
			if(table[i][0] == 'x'){
				if(is_finish_user1(table,i,0,size) == 1){
					table[i][0] = 'X';
					flag = 1;
					break;
				}
			}
		}	
		return flag;
	}
	if(move == 'o'){
		for(int i=0;i<size;i++){
			if(table[0][i] == 'o'){
				if(is_finish_user2(table,0,i,size) == 1){
					table[0][i] = 'O';
					flag = 1;
					break;
				}
			}
		}
		return flag;	
	}
}
int is_finish_user1(char table[12][12],int x,int y,int size){
		if(y == size-1){
			return 1;
		}
		if(table[x][y] == 'x' || table[x][y] == 'X'){
			if(table[x][y+1] == 'x' && check_in(x,y+1,size) == 1){
				table[x][y+1] = 'X';
			
				if(is_finish_user1(table,x,y+1,size) == 1){
					return 1;
				}
				table[x][y+1] = 'x';
			}
			else if(table[x-1][y+1] == 'x'  && check_in(x-1,y+1,size) == 1){
				table[x-1][y+1] = 'X';
			
				if(is_finish_user1(table,x+1,y+1,size) == 1){
					return 1;
				}
				table[x-1][y+1] = 'x';
			}		
			else if(table[x+1][y] == 'x' && check_in(x+1,y,size) == 1){
				table[x+1][y] = 'X';

				if(is_finish_user1(table,x+1,y,size) == 1){
					return 1;
				}
				table[x+1][y] = 'x';
			}	
			else if(table[x+1][y-1] == 'x' && check_in(x+1,y-1,size) == 1){
				table[x+1][y-1] = 'X';
				if(is_finish_user1(table,x+1,y-1,size) == 1){
					return 1;
				}
				table[x+1][y-1] = 'x';
			}
			else if(table[x-1][y] == 'x' && check_in(x+1,y,size) == 1){
				table[x-1][y] = 'X';
				if(is_finish_user1(table,x-1,y,size) == 1){
					return 1;
				}
				table[x-1][y] = 'x';
			}
			else if(table[x][y-1] == 'x' && check_in(x,y-1,size) == 1){
				table[x][y-1] = 'X';
				if(is_finish_user1(table,x,y-1,size) == 1){
					return 1;
				}
				table[x][y-1] = 'x';
			}	
		}				
		return 0;
}
int check_in(int x,int y,int size){
	int flag = 0;
	if(x >= 0 || x < size){
		if(y >= 0 || y < size){
			flag =1;
		} 	
	}
	return flag;
}
int is_finish_user2(char table[12][12],int x,int y,int size){
		if(x == size-1){
			return 1;
		}
		if(table[x][y] == 'o' || table[x][y] == 'O'){
			if(table[x+1][y] == 'o' && check_in(x+1,y,size) == 1){
				table[x+1][y] = 'O';
				if(is_finish_user2(table,x+1,y,size) == 1){
					
					return 1;
				}
				table[x+1][y] = 'o';
			}
			else if(table[x+1][y-1] == 'o' && check_in(x+1,y-1,size) == 1){
				table[x+1][y-1] = 'O';
				if(is_finish_user2(table,x+1,y-1,size) == 1){
					return 1;
				}
				table[x+1][y-1] = 'o';
			}						
			else if(table[x][y+1] == 'o' && check_in(x,y+1,size) == 1){
				table[x][y+1] = 'O';
				if(is_finish_user2(table,x,y+1,size) == 1){
					return 1;
				}
				table[x][y+1] = 'o';
			}
			else if(table[x-1][y+1] == 'o'  && check_in(x-1,y+1,size) == 1){
				table[x-1][y+1] = 'O';
				if(is_finish_user2(table,x+1,y+1,size) == 1){
					return 1;
				}
				table[x-1][y+1] = 'o';
			}		
			else if(table[x][y-1] == 'o' && check_in(x,y-1,size) == 1){
				table[x][y-1] = 'O';
				if(is_finish_user2(table,x,y-1,size) == 1){
					return 1;
				}
					table[x][y-1] = 'o';
			}
			else if(table[x-1][y] == 'o' && check_in(x+1,y,size) == 1){
				table[x-1][y] = 'O';
				if(is_finish_user2(table,x-1,y,size) == 1){
					return 1;
				}
				table[x-1][y] = 'o';
			}		
		}					
		return 0;
}
void pc_turn(char table[12][12],int size,int move,int *x,int *y){
	if(move ==0){
		if(table[0][(size/2)] == '.'){
			*x = 0;
			*y = size/2;
			table[(0)][(size/2)] = 'o';	
		}
		else{
			table[0][(size/2)-1] = 'o';
			*x = 0;
			*y = (size/2)-1;
		}
	}
	else{
		if(table[(*x)+1][*y] == '.'){
			table[(*x)+1][*y] = 'o';
			*x = (*x)+1;
		}
		else if(table[(*x)+1][(*y)-1] == '.'){
			table[(*x)+1][(*y)-1] = 'o';
			*y = (*y)-1;
			*x = (*x)+1;
		}		
		else if(table[(*x)][(*y)-1] == '.'){
			table[(*x)][(*y)-1] = 'o';
			*y = (*y)-1;
		}
		else if(table[(*x)][(*y)+1] == '.'){
			table[(*x)][(*y)+1] = 'o';
			*y = (*y)+1;
		}
		else if(table[(*x)-1][(*y)+1] == '.'){
			table[(*x)-1][(*y)+1] = 'o';
			*y = (*y)+1;
			*x = (*x)-1;
		}
		else if(table[(*x)-1][(*y)] == '.'){
			table[(*x)-1][(*y)] = 'o';
			*x = (*x)-1;
		}
		else{
			find_loc(table,size,x,y);
			table[*x][*y] = 'o';
		}		
	}
}

void find_loc(char table[12][12],int size,int *x,int *y){
	int i,j;
	for(i=0;i<size;i++){
		for(j = 0;j<size;j++){
			if(table[i][j] == '.'){
				*y = i;
				*x = j;
				break;
			}
		}
	}

}
int save_game(char table[12][12],game_types mode,const int &size,const int &last_user,const string file_name){
	fstream file;
	file.open(file_name,ios::out);
	if(file.fail()){
		cerr << "File couldn't open!\n";
		return 0;
	}
	file << (int)game_types::humvshum << endl;
	file << last_user << endl;
	file << size << endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(table[i][j] == 'x'){
				file << (int)board_cells::x;
			}	
			if(table[i][j] == 'X'){
				file << (int)board_cells::X;
			}
			if(table[i][j] == 'o'){
				file << (int)board_cells::o;
			}
			if(table[i][j] == 'O'){
				file << (int)board_cells::O;
			}
			if(table[i][j] == '.'){
				file << (int)board_cells::pt;
			}
		}
		file << endl;
	}
	file.close();
	return 1;
}
int load_game(char table[12][12],game_types &mode,int &size,int &last_user,const string file_name,int &x,int &y){
	fstream file;
	file.open(file_name,ios::in);	
	if(file.fail()){
		cerr << "File couldn't open!\n";
		return 0;
	}
	else{
		auto counter =0;
		decltype(counter) temp;
		char garbage;
		file >> temp;
		if((game_types)temp == game_types::humvshum){
			mode = game_types::humvshum;
		}
		else if((game_types)temp == game_types::humvscomp){
			mode = game_types::humvscomp;
			file >> x;
			file >> y;
		}
		file >> last_user;
		file >> size;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				file >> garbage;
				temp = garbage-48;
				if((board_cells)temp == board_cells::x){
					table[i][j] = 'x';
				}
				else if((board_cells)temp == board_cells::X){
					table[i][j] = 'X';
				}
				else if((board_cells)temp == board_cells::o){
					table[i][j] = 'o';
				}
				else if((board_cells)temp == board_cells::O){
					table[i][j] = 'O';
				}
				else if((board_cells)temp == board_cells::pt){
					table[i][j] = '.';
				}									
			}
		}
		file.close();
		if(mode ==game_types::humvshum){
			mod1(table,size,last_user,x,y,1);
			return 1;
		}
		else{
			mod2(table,size,last_user,x,y,1);
			return 1;
			
		}		
	}
}
int save_game(char table[12][12],game_types mode,const int &size,const int &last_user,const string file_name,int x,int y){
	fstream file;
	file.open(file_name,ios::out);
	if(file.fail()){
		cout << "File couldn't open!\n";
		return 0;
	}
	file << (int)game_types::humvscomp << endl;
	file << x << endl;
	file << y << endl;
	file << last_user << endl;
	file << size << endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(table[i][j] == 'x'){
				file << (int)board_cells::x;
			}	
			else if(table[i][j] == 'X'){
				file << (int)board_cells::X;
			}
			else if(table[i][j] == 'o'){
				file << (int)board_cells::o;
			}
			else if(table[i][j] == 'O'){
				file << (int)board_cells::O;
			}
			else if(table[i][j] == '.'){
				file << (int)board_cells::pt;
			}
		}
		file << endl;
	}
	file.close();
	return 1;	
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
	if(counter < 1 || counter > 12){
		return -1;
	}
	else{
		return counter;
	}

}
