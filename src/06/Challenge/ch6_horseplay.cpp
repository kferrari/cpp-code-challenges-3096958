// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    // Write your code here

    // Validate input
    if (knight.size() != 2){
        std::cout << "Invalid input string" << std::endl;
        return moves;
    }

    // Parse knight into row (letter) and column (mumber)
    const char startCol = knight[0];
    const char startRow = knight[1];

    if (startCol < 'a' || startCol > 'h'){
        std::cout << "Invalid start column" << std::endl;
        return moves;
    }

    if (startRow < '1' || startRow > '8'){
        std::cout << "Invalid start row" << std::endl;
        return moves;
    }

    // Calculate 8 possible moves and validate each (number within 1-8, letter within a-h)
    int col_moves[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int row_moves[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    char tempCol, tempRow;

    for (int i = 0; i<8; i++){
        tempCol = startCol + col_moves[i];
        tempRow = startRow + row_moves[i];

        // validate
        if (tempCol < 'a' || tempCol > 'h' || tempRow < '1' || tempRow > '8'){
            continue;
        }

        // push
        std::string s;
        s.push_back(tempCol);
        s.push_back(tempRow);

        moves.push_back(s);
    }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}