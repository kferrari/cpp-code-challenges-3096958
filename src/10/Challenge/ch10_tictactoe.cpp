// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

// #define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // Write your code here and comment out the definition of TWO_PLAYERS above
    
    // #define LINEAR
    #ifdef LINEAR
    // First attempt: choose first free field
    for (int row = 0; row<3; row++){
        for (int col = 0; col<3; col++){
            if (game[row][col] == ' '){
                game[row][col] = mark;
                return;
            }
        }
    }
    #endif

    #define AVOID
    #ifdef AVOID
    // Second attempt: avoid other player winning
    // Check horitontal/vertical
    char enemyMark;
    if (mark == 'O'){
        enemyMark = 'X';
    } else {
        enemyMark = 'O';
    }

    for (int row = 0; row<3; row++){
        int consCnt = 0;
        for (int col = 0; col<3; col++){
            if (game[row][col] == ' '){
               continue;
            } 
            if (game[row][col] == enemyMark){
                consCnt++;
            }
        }
        if (consCnt == 2){
            for (int col = 0; col<3; col++){
                if (game[row][col] == ' '){
                game[row][col] = mark;
                return;
                } 
            }
        }
    }

    for (int col = 0; col<3; col++){
        int consCnt = 0;
        for (int row = 0; row<3; row++){
            if (game[row][col] == ' '){
               continue;
            } 
            if (game[row][col] == enemyMark){
                consCnt++;
            }
        }
        if (consCnt == 2){
            for (int row = 0; row<3; row++){
                if (game[row][col] == ' '){
                game[row][col] = mark;
                return;
                } 
            }
        }
    }

    // Check two diagonals
    if (game[0][0] == enemyMark && game[1][1] == enemyMark && game[2][2] == ' '){
        game[2][2] = mark;
        return;
    }
    if (game[0][0] == enemyMark && game[1][1] == ' ' && game[2][2] == enemyMark){
        game[1][1] = mark;
        return;
    }
    if (game[0][0] == ' ' && game[1][1] == enemyMark && game[2][2] == enemyMark){
        game[0][0] = mark;
        return;
    }

    if (game[2][0] == enemyMark && game[1][1] == enemyMark && game[0][2] == ' '){
        game[0][2] = mark;
        return;
    }
    if (game[2][0] == enemyMark && game[1][1] == ' ' && game[0][2] == enemyMark){
        game[1][1] = mark;
        return;
    }
    if (game[2][0] == ' ' && game[1][1] == enemyMark && game[0][2] == enemyMark){
        game[2][0] = mark;
        return;
    }

    if (game[1][1] == ' '){
        game[1][1] = mark;
        return;
    }

    // In case we're still here, put in next free slot
    for (int row = 0; row<3; row++){
        for (int col = 0; col<3; col++){
            if (game[row][col] == ' '){
                game[row][col] = mark;
                return;
            }
        }
    }

    #endif
    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){

    // Write your code here

    // Check horitontal/vertical
    for (int row = 0; row<3; row++){
        char player = game[row][0];
        int consCnt = 0;
        for (int col = 0; col<3; col++){
            if (game[row][col] == ' '){
               continue;
            } 
            if (player == game[row][col]){
                consCnt++;
            }
        }
        if (consCnt == 3){
            return player;
        }
    }

    int nMoves = 0;
    for (int col = 0; col<3; col++){
        char player = game[0][col];
        int consCnt = 0;
        for (int row = 0; row<3; row++){
            if (game[row][col] == ' '){
               continue;
            } 
            nMoves++;
            if (player == game[row][col]){
                consCnt++;
            }
        }
        if (consCnt == 3){
            return player;
        }
    }

    // Check two diagonals
    if (game[1][1] != ' '){
        if (game[0][0] == game[1][1] && game[2][2] == game[1][1]){
            return char(game[0][0]);
        }

        if (game[0][2] == game[1][1] && game[0][2] == game[2][0]){
            return char(game[0][2]);
        }
    }

    // Check nMoves
    if (nMoves == 9){
        return 't';
    }

    return 'a';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
