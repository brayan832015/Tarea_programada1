#ifndef BATTLESHIP_H
#define BATTLESHIP_H
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

class Player {
    public:
        void read_j1();
        void read_j2();
};

class Cell {
public:
    bool occupied = false;
    bool fire = false;
    char symbol = 'X';
};

// Clase para representar el tablero
class Board {
    public:
        int size;
        std::vector<std::vector<Cell>> cells;
        Board(int size) : size(size), cells(size, std::vector<Cell>(size)) {}
        void imprimir();
        void place_submarine(int fila, int columna);
        void place_cruise(int fila, int columna);
        void place_boat(int fila, int columna);
};



/*

class Board_shot {
    public:
        Ships ship;
        Board_shot();
        bool attack_cell(int x, int y);
        bool game_over();
        void print_board_shot();
        static const int Rows = 5;
        static const int Columns = 5;
        
};

*/
#endif