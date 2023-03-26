#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <vector>
using namespace std;

class Ships {
    public:
        int x;
        int y;
        int large;        
};

class Cell {
    public:
        bool empty;
        Ships ship;
};

class Board_ocean {
    public:
        Board_ocean();
        bool place_ship(Ships ship);
        void print_board_ocean();
        static const int Rows = 5;
        static const int Columns = 5;
        Cell cells_ocean [Rows][Columns];
        
};

class Board_shot {
    public:
        Ships ship;
        Board_shot();
        bool attack_cell(int x, int y);
        bool game_over();
        void print_board_shot();
        static const int Rows = 5;
        static const int Columns = 5;
        Cell cells_shot [Rows][Columns];
        
};


#endif