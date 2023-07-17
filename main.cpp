#include <stdio.h>
#include <iostream>

using namespace std;

const int BOARD_WIDTH = 50;
const int BOARD_HEIGHT = 50;
char gameBoard[BOARD_HEIGHT][BOARD_WIDTH];

void initializeGameBoard(){
    for (int i = 0; i < BOARD_HEIGHT; i++){
        for (int j = 0; j < BOARD_WIDTH; j++){
            if(i == 0 || i == BOARD_HEIGHT - 1 || j == 0 || j == BOARD_WIDTH - 1){
                gameBoard[i][j] = '#';
            } else {
                gameBoard[i][j] = ' ';
            }
        }
    }
}
void renderGameBoard(){
    for(int i = 0; i < BOARD_HEIGHT-1; i++){
        for(int j = 0; i < BOARD_WIDTH-1; j++){
            cout << gameBoard[i][j];
        }
        cout << endl;
    }
}

int main(){
    return 0;
}