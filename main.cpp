#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_WIDTH = 16;
const int BOARD_HEIGHT = 16;

char gameBoard[BOARD_HEIGHT][BOARD_WIDTH];
int snakePosition[256][256];
enum class Direction {UP, DOWN, LEFT, RIGHT};
class Snake{
private:
    bool isOppositeDirection(Direction newDirection) const{
        return (direction == Direction::UP && newDirection == Direction::DOWN) ||
                (direction == Direction::DOWN && newDirection == Direction::UP) ||
                (direction == Direction::LEFT && newDirection == Direction::RIGHT) ||
                (direction == Direction::RIGHT && newDirection == Direction::LEFT);
    }
    vector<pair<int, int>> body;
    int size;
public:
    

    Direction direction;

    Snake(int startX, int startY, int initialSize) : direction(Direction::RIGHT), size(initialSize){
        for(int i = 0; i < size - 1; i++){
            body.push_back(make_pair(startX - i, startY));
        }
    }

    void move(){
        int newX, newY;
        switch (direction){
            case Direction::UP:
                newY--;
                break;
            case Direction::DOWN:
                newY++;
                break;
            case Direction::LEFT:
                newX--;
                break;
            case Direction::RIGHT:
                newX++;
                break;
        }
        body.insert(body.begin(), make_pair(newX, newY));

        if (body.size() > size){
            body.pop_back();
        }
    }
    
    void setDirection(Direction newDirection){
        if(isOppositeDirection(newDirection)){
            return;
        }
        direction = newDirection;
    }
    Direction getDirection(){
        return direction;
    }

    vector<pair<int, int>> getBody(){
        return body;
    }

    int getSize(){
        return body.size();
    }

    void grow(){
        size++;
    }
};
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