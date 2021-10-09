#include<iostream>
using namespace std;
#include "hw1.h"



void mod1(){

	char table[12][12];
	char column,move;
	int line,size;
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
	while(1){
		print_table(table,size);
		cout << "User 1 should enter the move:(ex: A 1)\n";
		cin >> column;
		cin >> line;
		while(is_possible(line,column,table,size) == 0){
			cout << "User 1 entered wrong move.Try Again!\n";
			cin >> column >> line;
		}
		fill_move(line,column,'x',table);
		if(control_finish(table,'x',size) == 1){
			cout << "User1 Won!\n";
			print_table(table,size);
			break;
		}
		print_table(table,size);
		cout << "User 2 should enter the move:(ex: A 2)\n";
		cin >> column >> line;
		while(is_possible(line,column,table,size) ==0){
			cout << "User 2 entered wrong move.Try Again!\n";
			cin >> column >> line;
		}	
		fill_move(line,column,'o',table);
		if(control_finish(table,'o',size) == 1){
			cout << "User2 Won!\n";
			print_table(table,size);
			break;
		}
		print_table(table,size);
	}		
}

void mod2(){
	int flag = 0;
	int size,choice,line;
	char table[12][12];
	char column,move;
	int x,y = -1;
	int counter =0;
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
	while(1){
		print_table(table,size);
		cout << "User 1 should enter the move:(ex: A 1)\n";
		cin >> column;
		cin >> line;
		while(is_possible(line,column,table,size) == 0){
			cout << "User 1 entered wrong move.Try Again!\n";
			cin >> column >> line;
		}
		fill_move(line,column,'x',table);
		if(control_finish(table,'x',size) == 1){
			cout << "User Won!\n";
			print_table(table,size);
			break;
		}
		print_table(table,size);
		pc_turn(table,size,counter,&x,&y);
		column = y+65;
		cout << "Computer Move:" << column << x+1 << "\n";
		counter++;
		if(control_finish(table,'o',size) == 1){
			cout << "Computer Won\n";
			print_table(table,size);
			break;
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
			//table[x][y] = 'X';
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
			//table[x][y] = 'x';	
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
			//table[x][y] = 'O';
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
			//table[x][y] = 'o';

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