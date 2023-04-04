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



/*class Ships {
    public:
        int x;
        int y;
        int large;        
};

class Board_ocean {
    public:
        Board_ocean();
        bool place_ship(Ships ship);
        void print_board_ocean();
        static const int Rows = 5;
        static const int Columns = 5;
        
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
        
};

*/
#endif