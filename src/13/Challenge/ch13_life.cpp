// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 25
#define M 25

// Check neighbors
int check_neighbors( char game[][M], int n, int m){
    int livingNeighbors = 0, row, col;
    n += N;
    m += M;
    for (int i = -1; i<2; i++){
        for (int j = -1; j<2; j++){
            if (i == 0 && j == 0){
                continue;
            }
            row = (n+i) % N;
            col = (m+j) % M;

            if (game[row][col] == 'X'){
                livingNeighbors++;
            }
        }
    }

    return livingNeighbors;
}

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // // A glider     // - - - - - - - - - -
    // game[1][1]='X'; // - X - - - - - - - -
    // game[2][2]='X'; // - - X - - - - - - -
    // game[3][0]='X'; // X X X - - - - - - -
    // game[3][1]='X';
    // game[3][2]='X';

    // // A blinker    // - - - - - - - - - -
    // game[3][6]='X'; // - - - - - - - - - -
    // game[3][7]='X'; // - - - - - - - - - -
    // game[3][8]='X'; // - - - - - - X X X -

    // An R-pentomino
    game[11][12] = 'X';
    game[11][13] = 'X';
    game[12][11] = 'X';
    game[12][12] = 'X';
    game[13][12] = 'X';
    
    int generation = 0;
    char frame[N][M];
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        // Write your code here
        if (generation > 0){
            int neighbors;
            
            std::memcpy(frame, game, N*M);
            for (int i = 0; i<N; i++){
                for (int j = 0; j<M; j++){
                    neighbors = check_neighbors(frame, i, j);

                    if (game[i][j] == 'X' && neighbors < 2){
                        game[i][j] = '-';
                    }

                    // if (neighbors == 2){
                    //     continue;
                    // }

                    // if (game[i][j] == 'X' && neighbors == 3){
                    //     continue;
                    // }

                    if (game[i][j] == 'X' && neighbors > 3){
                        game[i][j] = '-';
                    }                

                    if (game[i][j] == '-' && neighbors==3){
                        game[i][j] = 'X';
                    }
                }
            }
        }
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
