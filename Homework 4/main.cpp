#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "hex.h"

void find_marked_cells(vector <Hex> games);

int Hex::game_num =0;
int Hex::marked_cells =0;

int main(){
    int g1,g2;
    string file;
    vector <Hex> games;
    int current_game;
    int control;
    games.push_back(Hex());
    games[0].increase_game_num();
    current_game = 0;
    control = games[0].playGame(3,file);
    while(1){
        if(control == -2){
            games.push_back(Hex());
            
            current_game = games[0].get_games_num()-1;
            
            control = games.back().playGame(1,file);
        }
        else if(control == -1){
            games.push_back(Hex());
            current_game = games[0].get_games_num()-1;
            control = games.back().playGame(3,file);
        }
        else if(control ==0){
            break;
        }
        else if(control == -9){
           games[current_game].set_move_number(0);
            control = games[current_game].playGame(3,file);
        }
        else{
            current_game = control-1;
            control =  games[current_game].playGame(2,file);
        }
    }
    while(1){
        cout << "In this part we will compare two games or listed all marked cells\n";
        cout << "1.)Compare two games.\n2.)Print marked cells\n3.)Exit\n" ;
        cin >> control;
        if(control == 1){
            cout <<"There is " << games[0].get_games_num() << "played games.Which ones do you want to compare?\n";
            cout << "Enter the number of first game:" << endl;
            cin >> g1;
            cout << "Enter the number of second game:" << endl;
            cin >> g2;
            if(g1 < 0 || g1 > games[0].get_games_num() ||g2 < 0 || g2 > games[0].get_games_num()){
                cout << "Wrong entry!.Please try again!\n";
            }
            else{
                if(games[g1-1] == games[g2-1]){
                    cout << "First game has more hexced cell than the other.\n";
                }
                else{
                    cout << "Second game has more number of marked cell\n";
                }
            }
        }
        else if(control == 2){
            find_marked_cells(games);
            cout << "There is " << games[0].get_marked_cells()<< " marked cell at all games\n";
        }
        else{
            cout << "Have a nice day again!\n";
            break;
        }
    }
    return 0;
}

void find_marked_cells(vector <Hex> games){
    games[0].set_marked_cell();
    for(int i=0;i<games.size();i++){
        games[i].increase_marked_cells();
    }
}
