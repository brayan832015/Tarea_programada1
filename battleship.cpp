#include <iostream>
#include "battleship.h"


void Player::read_j1(){
    std::ifstream archive_j1("barcos_j1.txt");
    if (archive_j1.is_open()) {
        string ignore_1;
        getline(archive_j1, ignore_1); 

        string player_1_name;
        getline(archive_j1, player_1_name);

        string ignore_2;
        getline(archive_j1, ignore_2);

        string submarine_coordinates_j1;
        getline(archive_j1, submarine_coordinates_j1); 

        string ignore_3;
        getline(archive_j1, ignore_3);

        string cruise_coordinates_j1;
        getline(archive_j1, cruise_coordinates_j1); 

        string ignore_4;
        getline(archive_j1, ignore_4);

        string boat_coordinates_j1;
        getline(archive_j1, boat_coordinates_j1); 

        vector<pair<int, int>> numeric_coordinates_submarine;
        string coord_submarine_j1;
        stringstream ss_submarine(submarine_coordinates_j1);
        int large_submarine_j1 = 0;
        int out_submarine_j1 = 0;
        while (getline(ss_submarine, coord_submarine_j1, ',')) {
            int letter = coord_submarine_j1[0] - 'A' + 1;
            int number = stoi(coord_submarine_j1.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el submarino del jugador 1 se sale del tablero"<<endl;
                out_submarine_j1++;
            }
            else{
               numeric_coordinates_submarine.push_back({number, letter}); 
               large_submarine_j1++;
               if (large_submarine_j1 > 3){
                cout<<"Error: el submarino del jugador 1 tiene mas de 3 coordenadas"<<endl;
               }
            }
            
        }
        cout << "Coordenadas del submarino jugador 1 en numeros: ";
        for (auto coord_submarine_j1 : numeric_coordinates_submarine) {
            if (large_submarine_j1 != 3 || out_submarine_j1 != 0){
                if (large_submarine_j1 < 3 and out_submarine_j1 == 0){
                    cout<<"Error: el submarino del jugador 1 tiene menos de 3 coordenadas"<<endl;
                }
                break;
            }
            cout << "(" << coord_submarine_j1.second << "," << coord_submarine_j1.first << ")";

        }
        cout<<endl;


        vector<pair<int, int>> numeric_coordinates_cruise;
        string coord_cruise_j1;
        stringstream ss_cruise(cruise_coordinates_j1);
        int cruise_large_j1 = 0;
        int out_cruise_j1 = 0;
        while (getline(ss_cruise, coord_cruise_j1, ',')) {
            int letter = coord_cruise_j1[0] - 'A' + 1;
            int number = stoi(coord_cruise_j1.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el crucero del jugador 1 se sale del tablero"<<endl;
                out_cruise_j1++;
            }
            else{
                numeric_coordinates_cruise.push_back({number, letter});
                cruise_large_j1++;
                if (cruise_large_j1 > 2){
                cout<<"Error: el crucero del jugador 1 tiene mas de 2 coordenadas"<<endl;
                }
            }
        }
        cout << "Coordenadas del crucero jugador 1 en numeros: ";
        for (auto coord_cruise_j1 : numeric_coordinates_cruise) {
            if (cruise_large_j1 != 2 || out_cruise_j1 != 0){
                if (cruise_large_j1 < 3 and out_cruise_j1 == 0){
                    cout<<"Error: el crucero del jugador 1 tiene menos de 2 coordenadas"<<endl;
                }
                break;
            }
            cout << "(" << coord_cruise_j1.second << "," << coord_cruise_j1.first << ")";
        }
        cout<<endl;


        vector<pair<int, int>> numeric_coordinates_boat;
        string coord_boat_j1;
        stringstream ss_boat(boat_coordinates_j1);
        int large_boat_j1 = 0;
        int out_boat_j1 = 0;
        while (getline(ss_boat, coord_boat_j1, ',')) {
            int letter = coord_boat_j1[0] - 'A' + 1;
            int number = stoi(coord_boat_j1.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: la lancha del jugador 1 se sale del tablero"<<endl;
                out_boat_j1++;
            }
            else{
                numeric_coordinates_boat.push_back({number, letter});
                large_boat_j1++;
                if (large_boat_j1 > 1){
                   cout<<"Error: la lancha del jugador 1 tiene mas de 1 coordenada"<<endl; 
                }
            }
        }
        cout << "Coordenada de la lancha jugador 1 en numeros: ";
        for (auto coord_boat_j1 : numeric_coordinates_boat) {
            if (large_boat_j1 != 1 || out_boat_j1 !=0 ){
                break;
            }
            cout << "(" << coord_boat_j1.second << "," << coord_boat_j1.first << ")";
        }
        cout<<endl;


        archive_j1.close();
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j1.txt" << std::endl;
    }
    
    
}

void Player::read_j2(){
    std::ifstream archive_j2("barcos_j2.txt");
    if (archive_j2.is_open()) {
        string ignore_1;
        getline(archive_j2, ignore_1); 

        string player_2_name;
        getline(archive_j2, player_2_name);

        string ignore_2;
        getline(archive_j2, ignore_2);

        string submarine_coordinates_j2;
        getline(archive_j2, submarine_coordinates_j2); 

        string ignore_3;
        getline(archive_j2, ignore_3);

        string cruise_coordinates_j2;
        getline(archive_j2, cruise_coordinates_j2); 

        string ignore_4;
        getline(archive_j2, ignore_4);

        string boat_coordinates_j2;
        getline(archive_j2, boat_coordinates_j2); 

        vector<pair<int, int>> numeric_coordinates_submarine;
        string coord_submarine_j2;
        stringstream ss_submarine(submarine_coordinates_j2);
        int large_submarine_j2 = 0;
        int out_submarine_j2 = 0;
        while (getline(ss_submarine, coord_submarine_j2, ',')) {
            int letter = coord_submarine_j2[0] - 'A' + 1;
            int number = stoi(coord_submarine_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el submarino del jugador 2 se sale del tablero"<<endl;
                out_submarine_j2++;
            }
            else{
                numeric_coordinates_submarine.push_back({number, letter});
                large_submarine_j2++;
                if (large_submarine_j2 > 3){
                    cout<<"Error: el submarino del jugador 2 tiene mas de 3 coordenadas"<<endl;
                }
            }
        }
        cout << "Coordenadas del submarino jugador 2 en numeros: ";
        for (auto coord_submarine_j2 : numeric_coordinates_submarine) {
            if (large_submarine_j2 != 3 || out_submarine_j2 != 0){
                if (large_submarine_j2 < 3 and out_submarine_j2 == 0){
                    cout<<"Error: el submarino del jugador 2 tiene menos de 3 coordenadas"<<endl;
                }
                break;
            }
            cout << "(" << coord_submarine_j2.second << "," << coord_submarine_j2.first << ")";
        }
        cout<<endl;


        vector<pair<int, int>> numeric_coordinates_cruise;
        string coord_cruise_j2;
        stringstream ss_cruise(cruise_coordinates_j2);
        int out_cruise_j2 = 0;
        int cruise_large_j2 = 0;
        while (getline(ss_cruise, coord_cruise_j2, ',')) {
            int letter = coord_cruise_j2[0] - 'A' + 1;
            int number = stoi(coord_cruise_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: el crucero del jugador 2 se sale del tablero"<<endl;
                out_cruise_j2++;
            }
            else{
                numeric_coordinates_cruise.push_back({number, letter});
                cruise_large_j2++;
                if (cruise_large_j2 > 2){
                cout<<"Error: el crucero del jugador 2 tiene mas de 2 coordenadas"<<endl;
                }
            }
        }
        cout << "Coordenadas del crucero jugador 2 en numeros: ";
        for (auto coord_cruise_j2 : numeric_coordinates_cruise) {
            if (cruise_large_j2 != 2 || out_cruise_j2 != 0){
                if (cruise_large_j2 < 3 and out_cruise_j2 == 0){
                    cout<<"Error: el crucero del jugador 2 tiene menos de 2 coordenadas"<<endl;
                }
                break;
            }
            cout << "(" << coord_cruise_j2.second << "," << coord_cruise_j2.first << ")";
        }
        cout<<endl;


        vector<pair<int, int>> numeric_coordinates_boat;
        string coord_boat_j2;
        stringstream ss_boat(boat_coordinates_j2);
        int large_boat_j2 = 0;
        int out_boat_j2 = 0;
        while (getline(ss_boat, coord_boat_j2, ',')) {
            int letter = coord_boat_j2[0] - 'A' + 1;
            int number = stoi(coord_boat_j2.substr(1));
            if (number > 5 || letter > 5){
                cout<<"Error: la lancha del jugador 2 se sale del tablero"<<endl;
                out_boat_j2++;
            }
            else{
                numeric_coordinates_boat.push_back({number, letter});
                large_boat_j2++;
                if (large_boat_j2 > 1){
                   cout<<"Error: la lancha del jugador 2 tiene mas de 1 coordenada"<<endl; 
                }
            }
        }
        cout << "Coordenada de la lancha jugador 2 en numeros: ";
        for (auto coord_boat_j2 : numeric_coordinates_boat) {
            if (large_boat_j2 != 1 || out_boat_j2 !=0 ){
                break;
            }
            cout << "(" << coord_boat_j2.second << "," << coord_boat_j2.first << ")";
        }
        cout<<endl;

        archive_j2.close();
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j2.txt" << std::endl;
    }
}






/*Board_ocean::Board_ocean(){
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
}*/