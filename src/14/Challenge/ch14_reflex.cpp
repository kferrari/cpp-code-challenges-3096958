// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    do{

        // Write your code here
        std::string answer;

        std::srand(std::time(nullptr));
        int random_delay = std::rand()%7;
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(4+random_delay));

        int random_word = std::rand()%10;
        bool fail = false;

        std::cout << " Type >>> " << words[random_word] << std::endl;

        auto start = std::chrono::steady_clock::now();
        std::getline(std::cin, answer);
        auto end = std::chrono::steady_clock::now();
        double elapsed_seconds = (end-start).count()/1e9;

        // Check conditions: timing and word
        if (elapsed_seconds >= 2.0){
            fail = true;
        }

        std::transform(answer.begin(), answer.end(), answer.begin(), toupper);
        
        if (answer.compare(words[random_word]) != 0){
            fail = true;
            std::cout << answer << " does not match " << words[random_word] << std::endl;
        }

        if (fail){
            std::cout << "You failed in " << elapsed_seconds << "s" << std::endl;
        } else {
            std::cout << "You won in " << elapsed_seconds << "s" << std::endl << std::flush;
        }

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
