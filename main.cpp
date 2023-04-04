#include "battleship.h"

int main(){ //funciones del programa al ejecutarse
    Player j1;
    j1.read_j1();
    Player j2;
    j2.read_j2();

    char tablero[5][5] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    cout<<"Tablero oceano jugador 1:"<<endl;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << tablero[i][j];
            if ((j==0 or j>0) and j<4){
                cout << " | ";
            }
        }
        cout << endl;
    }
}