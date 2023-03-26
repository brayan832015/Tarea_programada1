#include <iostream>
#include "battleship.h"

Board_ocean::Board_ocean(){
    for (int row = 0; row < Rows; row++){
        for (int col = 0; col < Columns; col++){
            this->cells_ocean[row][col].empty = true; //crear tablero oceano vacio
        }
    }
}

bool Board_ocean::place_ship(Ships ship){ //solo para agregar barco en horizontal, falta vertical
    //Verificar que el barco cabe
    if (ship.x + ship.large > this->Columns){
        cout<<"El barco se sale del tablero"<<endl;
        return false;
    }
    //Ver si el lugar esta desocupado
    for (int i = ship.x; i < ship.x + ship.large; i++){
        if (!this->cells_ocean[i][ship.y].empty) {
            cout <<"Hay barcos que coinciden en la misma casilla del tablero"<<endl;
            return false;
        }
    }
    //Colocar el barco
    for (int i = ship.x; i < ship.x + ship.large; i++){
        this->cells_ocean[i][ship.y].empty = false;
        this->cells_ocean[i][ship.y].ship = ship;
    }
    return true;
}

void Board_ocean::print_board_ocean(){
    cout << "Tablero oceano";   
    for (int i = 0; i < Rows; i++){
        cout << endl;
        for (int j = 0; j < Columns; j++){
            if (this->cells_ocean[i][j].empty){
                cout << "| X |";
            }
            else {
                //cout << this->cells_ocean[i][j]<< endl;
            }
        }
        
    }
    cout<<endl;
}

Board_shot::Board_shot(){
    for (int row = 0; row < Rows; row++){
        for (int col = 0; col < Columns; col++){
            this->cells_shot[row][col].empty = true; //crear tablero de tiro vacio
        }
    }
}

bool Board_shot::attack_cell(int x, int y){
    //Ver si la celda esta vacia
    if (this->cells_shot[x][y].empty){
        cout<<"¡Agua!"<<endl;
        return false;
    }
    //Barco impactado
    else{
        this->cells_shot[x][y].ship.large--;
        if (this->cells_shot[x][y].ship.large != 0){
            cout<<"¡Impacto!"<<endl;
        }
        else {
            cout<<"¡Hundido!"<<endl;
        }
    }
    return true;
}

void Board_shot::print_board_shot(){
    cout << "Tablero de tiro";   
    for (int i = 0; i < Rows; i++){
        cout << endl;
        for (int j = 0; j < Columns; j++){
            if (this->cells_shot[i][j].empty){
                cout << "| X |";
            }
            else {
                //cout << this->cells_ocean[i][j]<< endl;
            }
        }
        
    }
    cout<<endl;
}

bool Board_shot::game_over(){
    //Verifica si ya no quedan barcos
    for (int i = 0; i < Rows; i++){
        for (int j = 0; i < Columns; j++){
            if (!this->cells_shot[i][j].empty && this->cells_shot[i][j].ship.large > 0){
                return false;
            }
        }
    }
    return true;
}