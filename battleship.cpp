#include <iostream>
#include "battleship.h"
std::ifstream archive_j1("barcos_j1.txt");
std::ifstream archive_j2("barcos_j2.txt");
int error = 0;
int impact_j1 = 0;
int impact_j2 = 0;
int sub_j1_impact = 0;
int cruise_j1_impact = 0;
int sub_j2_impact = 0;
int cruise_j2_impact = 0;
Player j1;
Player j2;
Board board_ocean_j1(6);
Board board_fire_j1(6);
Board board_ocean_j2(6);
Board board_fire_j2(6);

bool game_over() {
    if(impact_j2 == 6 || impact_j1 == 6){
        if (impact_j2==6){
            cout<<"Se acabo el juego"<<endl;
            cout<<"Gano el jugador 2"<<endl;
        }
        if (impact_j1==6){
            cout<<"Se acabo el juego"<<endl;
            cout<<"Gano el jugador 1"<<endl;
        }
        return true;
    }
    else{
        return false;
    }
}

int main(){ 
    if (!game_over()){
        j1.read_j1();
        j2.read_j2();
        game_over();
        while (!game_over() and error==0) {
            // Turno del jugador 1
            j1.shot_j1();
            if (j1.last_shot_hit) {
                continue;
            }
            while (!game_over()) {
                // Turno del jugador 2
                j2.shot_j2();
                if (j2.last_shot_hit) {
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
    else{
        cout<<"Acabo"<<endl;
    } 
}

void Player::shot_j1(){
    cout<<"Jugador: "<<"Jugador 1"<<endl;
    cout<<endl;
    cout<<"Tablero de tiro"<<endl;
    board_fire_j1.print();
    cout<<endl;
    cout<<"Tablero oceano "<<endl;
    board_ocean_j1.print();
    int columna = 0;
    int fila = 0;
    string coordenada_disparo;
    cout<<endl;
    cout << "Turno del jugador 1. Ingrese la coordenada de disparo: ";
    cin >> coordenada_disparo;
    columna = coordenada_disparo[0] - 'A' + 1;
    fila = coordenada_disparo[1] - '1' + 1;
    board_ocean_j2.fire_j1(columna,fila);
}

void Player::shot_j2(){
    cout<<"Jugador: "<<"Jugador 2"<<endl;
    cout<<endl;
    cout<<"Tablero de tiro"<<endl;
    board_fire_j2.print();
    cout<<endl;
    cout<<"Tablero oceano "<<endl;
    board_ocean_j2.print();
    int columna = 0;
    int fila = 0;
    string coordenada_disparo;
    cout<<endl;
    cout << "Turno del jugador 2. Ingrese la coordenada de disparo: ";
    cin >> coordenada_disparo;
    columna = coordenada_disparo[0] - 'A' + 1;
    fila = coordenada_disparo[1] - '1' + 1;
    board_ocean_j1.fire_j2(columna,fila);
}

void Board::place_submarine(int fila, int columna) {
        cells[fila][columna].occupied = true;
        cells[fila][columna].symbol = 'S';
    }

void Board::place_cruise(int fila, int columna) {
        cells[fila][columna].occupied = true;
        cells[fila][columna].symbol = 'C';
    }

void Board::place_boat(int fila, int columna) {
        cells[fila][columna].occupied = true;
        cells[fila][columna].symbol = 'L';
        
    }

void Board::print(){
        cells[0][0].occupied = false;
        cells[0][0].symbol = 'x';
        cells[1][0].occupied = false;
        cells[1][0].symbol = 'A';
        cells[2][0].occupied = false;
        cells[2][0].symbol = 'B';
        cells[3][0].occupied = false;
        cells[3][0].symbol = 'C';
        cells[4][0].occupied = false;
        cells[4][0].symbol = 'D';
        cells[5][0].occupied = false;
        cells[5][0].symbol = 'E';
        cells[0][1].occupied = false;
        cells[0][1].symbol = '1';
        cells[0][2].occupied = false;
        cells[0][2].symbol = '2';
        cells[0][3].occupied = false;
        cells[0][3].symbol = '3';
        cells[0][4].occupied = false;
        cells[0][4].symbol = '4';
        cells[0][5].occupied = false;
        cells[0][5].symbol = '5';
        for (int fila = 0; fila < size; fila++) {
            for (int columna = 0; columna < size; columna++) {
                std::cout << cells[fila][columna].symbol << " ";
            }
            std::cout << std::endl;
        }
    }

void Player::read_j1(){
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
                error++;
                out_submarine_j1++;
            }
            else{
                board_ocean_j1.place_submarine(letter,number);
                large_submarine_j1++;
                if (large_submarine_j1 > 3){
                    cout<<"Error: el submarino del jugador 1 tiene mas de 3 coordenadas"<<endl;
                    error++;
                }  
            }
            
        }
        for (auto coord_submarine_j1 : numeric_coordinates_submarine) {
            if (large_submarine_j1 != 3 || out_submarine_j1 != 0){
                if (large_submarine_j1 < 3 and out_submarine_j1 == 0){
                    cout<<"Error: el submarino del jugador 1 tiene menos de 3 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }
        
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
                error++;
                out_cruise_j1++;
            }
            else{
                board_ocean_j1.place_cruise(letter,number);
                cruise_large_j1++;
                if (cruise_large_j1 > 2){
                    cout<<"Error: el crucero del jugador 1 tiene mas de 2 coordenadas"<<endl;
                    error++;
                }
            }
        }
        for (auto coord_cruise_j1 : numeric_coordinates_cruise) {
            if (cruise_large_j1 != 2 || out_cruise_j1 != 0){
                if (cruise_large_j1 < 3 and out_cruise_j1 == 0){
                    cout<<"Error: el crucero del jugador 1 tiene menos de 2 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }


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
                error++;
                out_boat_j1++;
            }
            else{
                board_ocean_j1.place_boat(letter,number);
                large_boat_j1++;
                if (large_boat_j1 > 1){
                   cout<<"Error: la lancha del jugador 1 tiene mas de 1 coordenada"<<endl; 
                   error++;
                }
            }
        }
        for (auto coord_boat_j1 : numeric_coordinates_boat) {
            if (large_boat_j1 != 1 || out_boat_j1 !=0 ){
                break;
            }
        }
        archive_j1.close();
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j1.txt" << std::endl;
    }
}

void Player::read_j2(){
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
                error++;
                out_submarine_j2++;
            }
            else{
                board_ocean_j2.place_submarine(letter,number);
                large_submarine_j2++;
                if (large_submarine_j2 > 3){
                    cout<<"Error: el submarino del jugador 2 tiene mas de 3 coordenadas"<<endl;
                    error++;
                }
            }
        }
        for (auto coord_submarine_j2 : numeric_coordinates_submarine) {
            if (large_submarine_j2 != 3 || out_submarine_j2 != 0){
                if (large_submarine_j2 < 3 and out_submarine_j2 == 0){
                    cout<<"Error: el submarino del jugador 2 tiene menos de 3 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }

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
                error++;
                out_cruise_j2++;
            }
            else{
                board_ocean_j2.place_cruise(letter,number);
                cruise_large_j2++;
                if (cruise_large_j2 > 2){
                cout<<"Error: el crucero del jugador 2 tiene mas de 2 coordenadas"<<endl;
                error++;
                }
            }
        }
        for (auto coord_cruise_j2 : numeric_coordinates_cruise) {
            if (cruise_large_j2 != 2 || out_cruise_j2 != 0){
                if (cruise_large_j2 < 3 and out_cruise_j2 == 0){
                    cout<<"Error: el crucero del jugador 2 tiene menos de 2 coordenadas"<<endl;
                    error++;
                }
                break;
            }
        }

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
                error++;
                out_boat_j2++;
            }
            else{
                board_ocean_j2.place_boat(letter,number);
                large_boat_j2++;
                if (large_boat_j2 > 1){
                   cout<<"Error: la lancha del jugador 2 tiene mas de 1 coordenada"<<endl; 
                   error++;
                }
            }
        }
        for (auto coord_boat_j2 : numeric_coordinates_boat) {
            if (large_boat_j2 != 1 || out_boat_j2 !=0 ){
                break;
            }
        } 
        archive_j2.close(); 
    } 
    else {
        cout << "No se pudo abrir el archivo barcos_j2.txt" << std::endl;
    }
}

void Board::fire_j1(int fila, int columna){
    if (cells[fila][columna].occupied){
        board_fire_j1.impact(fila, columna);
        if (cells[fila][columna].symbol == 'S'){
            sub_j2_impact++;
            if (sub_j2_impact == 3){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[fila][columna].symbol == 'C'){
            cruise_j2_impact++;
            if (cruise_j2_impact == 2){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[fila][columna].symbol == 'L'){
            cout<<"Hundido!"<<endl;
        }
        cells[fila][columna].fire = true;
        cells[fila][columna].symbol = 'I';
        impact_j1++;
        if(impact_j1 < 6){
            j1.last_shot_hit = true;
        }
        cout<<endl;
    }
    else {
        j1.last_shot_hit = false;
        board_fire_j1.water(fila, columna);
        cout<<"Agua!"<<endl;
        cells[fila][columna].symbol = 'A';
        cout<<endl;
    }
}

void Board::fire_j2(int fila, int columna){
    if (cells[fila][columna].occupied){
        if (cells[fila][columna].symbol == 'S'){
            sub_j1_impact++;
            if (sub_j1_impact == 3){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[fila][columna].symbol == 'C'){
            cruise_j1_impact++;
            if (cruise_j1_impact == 2){
                cout<<"Hundido!"<<endl;
            }
            else{
                cout<<"Impacto!"<<endl;
            }
        }
        if (cells[fila][columna].symbol == 'L'){
            cout<<"Hundido!"<<endl;
        }
        board_fire_j2.impact(fila, columna);
        cells[fila][columna].fire = true;
        cells[fila][columna].symbol = 'I';
        impact_j2++;
        if(impact_j2 < 6){
            j2.last_shot_hit = true;
        }
        cout<<endl;
    }
    else {
        j2.last_shot_hit = false;
        board_fire_j2.water(fila, columna);
        cout<<"Agua!"<<endl;
        cells[fila][columna].symbol = 'A';
        cout<<endl;
    }
}

void Board::impact(int fila, int columna){
    cells[fila][columna].symbol = 'I';
}

void Board::water(int fila, int columna){
    cells[fila][columna].symbol = 'A';
}