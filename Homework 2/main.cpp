#include<iostream>
using namespace std;
#include "hw2.h"


int main(){
	int choice,size,last_user,x,y;
	char table[12][12];
	while(1){
		cout << "Welcome to HEX!\n" << "1.Human vs Human\n2.Human vs Computer\n3.Exit\n";
		cin >> choice;
		if(choice == 3){
			cout << "Have a nice day!\n";
			break;
		} 		
		else if(choice == 1){
			mod1(table,size,last_user,x,y);
		}
		else if(choice == 2){
			mod2(table,size,last_user,x,y);
		}
		else{
			cout << "Wrong Choice!\n";
		}

	} 
	return 0;
}
