#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class MazeGame {
private:
    int grid[10][10];
    int rows, cols;
    int player_row, player_coloumn;

public:
    MazeGame(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = 1;
            }
        }
    }

    void initializeMaze() {
        srand(time(0));
        for (int i = 0; i < rows * cols / 5; i++) {
            int x = rand() % rows;
            int y = rand() % cols;
            if ((x != 0 || y != 0) && (x != rows - 1 || y != cols - 1)) {
                grid[x][y] = 2;
            }
        }
        grid[0][0] = 3;
        grid[rows - 1][cols - 1] = 4;
        player_row = 0;
        player_coloumn = 0;
    }

    void showMaze() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool is_valid_move(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != 2;
    }

    bool move_player(string direction) {
        int new_row = player_row, new_col = player_coloumn;

        if (direction == "up" && is_valid_move(player_row - 1, player_coloumn))
        new_row--;
        else if (direction == "down" && is_valid_move(player_row + 1, player_coloumn))
        new_row++;
        else if (direction == "left" && is_valid_move(player_row, player_coloumn - 1))
        new_col--;
        else if (direction == "right" && is_valid_move(player_row, player_coloumn + 1))
        new_col++;
        else {
            cout << "Your move is invalid. Please try again ---> " << endl;
            return false;
        }

        grid[player_row][player_coloumn] = 1;
        player_row = new_row;
        player_coloumn = new_col;
        grid[player_row][player_coloumn] = 3;

        return true;
    }

    bool is_game_over() {
        return player_row == rows - 1 && player_coloumn == cols - 1;
    }

    void play_game() {
        initializeMaze();
        cout << "Let's start the MAZE game ---> " << endl;

        while (true) {
            showMaze();
            cout << "Enter your move (up, down, left, right). To exit game, Enter 'quit': ";
            string input;
            cin >> input;

            if (input == "quit") {
                cout << "Game Ended !" << endl;
                break;
            }

            if (move_player(input)) {
                if (is_game_over()) {
                    cout << "You've escaped the maze. You win the game!" << endl;
                    break;
                }
              }
            }
         }
};

int main() {
    int row,col;
    cout<<"Enter maze grid size = "<<endl;
    cin>>row>>col;
    MazeGame start(row, col);
    start.play_game();
}












