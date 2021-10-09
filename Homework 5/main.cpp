#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
#include <deque>
#include "abstracthex.h"
#include "hexvector.h"
#include "hexarray1d.h"
#include "hexadapter.h"
#include "hexadapter.cpp"
using namespace hex;

bool checkValidty(vector<AbstractHex*>games);
int main(){
    string file;
    vector <AbstractHex*> games;
    int input,first,second;
    while(1){
        cout << "1)HexVector game.\n2)HexArray1D game.\n3)HexAdapter game.\n4)Compare Two game\n5)Check Validty\n0)Exit!\n";
        cin >> input;
        if(input == 1){
            HexVector *temp = new HexVector();
            games.push_back(temp);
            games.back()->playGame(0,file);
        }
        else if(input == 2){
            HexArray1D *temp = new HexArray1D();
            games.push_back(temp);
            games.back()->playGame(0,file);
        }
        else if(input == 3){
            cout << "1) Vector\n2) Deque\n";
            cin >> input; 
            if(input == 1){
                HexAdapter <vector> *temp = new HexAdapter<vector> () ;
                games.push_back(temp);
                games.back()->playGame(0,file);
            }
            else if(input == 2){
                HexAdapter <deque> *temp = new HexAdapter <deque> () ;
                games.push_back(temp);
                games.back()->playGame(0,file);
            }
            else{
                cout << "Wrong Selection!\n";
            }
        }
        else if(input == 4){
            if(games.size() < 2){
                cout << "There is not enough number of game for comparison!\n" ;
            }
            else{
                cout << "Enter the number of the first game to compare games:\n";
                cin >> first;
                cout << "Enter the number of the second game to compare games:\n";
                cin >> second;
                if(games[first-1] == games[second-1]){
                    cout << "Games are equal!\n";
                }
                else{
                    cout << "Games are not equal!\n";
                }           
            }
        }
        else if(input == 5){
            if(games.size() == 0){
                cout << "There is no game!\n";
            }
            else{
                if(checkValidty(games) == false){
                    cout << "One of the game is not valid!\n";
                }
                else{
                    cout << "Games are valid\n";
                }
            }
        }
        else if(input == 0){
            break;
        }
        else{
            cout <<  "Wrong Selection Try Again!\n";
        }
    }
    return 0;
}
bool checkValidty(vector<AbstractHex*>games){
    for(int i=0;i<games.size();i++){
        if(games[i]->get_size() < 5){
            return false;
        }
        for(int j=0;j<games[i]->get_size();j++){
            for(int z=0;z<games[i]->get_size();z++){
                if((*games[i])(j,z).get_cell() != board_cells::empty && (*games[i])(j,z).get_cell() != board_cells::user1 && (*games[i])(j,z).get_cell() != board_cells::user2 && (*games[i])(j,z).get_cell() != board_cells::u_user1 && (*games[i])(j,z).get_cell() != board_cells::u_user2){
                    return false;
                }                
            }
        }
    }
    return true;
}