#include<iostream>
using namespace std;
#include "hw1.h"


int main(){
	int choice;
	while(1){
		cout << "Welcome to HEX!\n" << "1.Human vs Human\n2.Human vs Computer\n3.Exit\n";
		cin >> choice;
		if(choice == 3){
			cout << "Have a nice day!\n";
			break;
		} 		
		else if(choice == 1){
			mod1();
		}
		else if(choice == 2){
			mod2();
		}
		else{
			cout << "Wrong Choice!\n";
		}

	} 
	return 0;
}
