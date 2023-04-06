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
        void shot_j1();
        void shot_j2();
        bool last_shot_hit = false;
        void read_j1();
        void read_j2();
};

class Cell {
public:
    bool occupied = false;
    bool fire = false;
    char symbol = 'X';
};

class Board {
    public:
        int size;
        std::vector<std::vector<Cell>> cells;
        Board(int size) : size(size), cells(size, vector<Cell>(size)) {}
        void print();
        void place_submarine(int fila, int columna);
        void place_cruise(int fila, int columna);
        void place_boat(int fila, int columna);
        void fire_j1(int fila, int columna);
        void fire_j2(int fila, int columna);
        void impact(int fila, int columna);
        void water(int fila, int columna);
};

#endif