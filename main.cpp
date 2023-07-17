#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_WIDTH = 16;
const int BOARD_HEIGHT = 16;

char gameBoard[BOARD_HEIGHT][BOARD_WIDTH];
int snakePosition[256][256];

class Snake{
public:
    enum class Direction {UP, DOWN, LEFT, RIGHT};

    Direction direction;
    int size;

    Snake(int startX, int startY, int initialSize) : direction(Direction::RIGHT), size(initialSize){
        /* for(i = 0; i < size - 1; i++){
            body.grow(std::make_pair(startX - i, startY));
        }
        */
    }
}

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
void updateSnakePos(){

}

int main(){
    initializeGameBoard();
    renderGameBoard();
    return 0;
}