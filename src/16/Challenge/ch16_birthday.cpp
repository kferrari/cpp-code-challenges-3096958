// C++ Code Challenges, LinkedIn Learning

// Challenge #16: The Birthday Problem
// The birthday problem consists in finding the probability of having at least two people with the same birthday in a group of n people.
// Create an application that simulates the Birthday Problem 1 million times, with the number of people specified by the user.
// Use this application to prove (empirically) that the probability of having at least 2 people with the same birthday is approximately 0.5 for a group of 23 people. 
// https://en.wikipedia.org/wiki/Birthday_problem 

#include <iostream>
#include <chrono>
#include <vector>

// The Birthday Problem, main()
// Summary: This application simulates the birthday problem a large number of times to reveal the probability of a birthday match in a groupd of a given number of people.
int main(){    
    const int total = 1000000;
    int n, matches = 0;

    std::cout << "Enter the number of people in the group: " << std::flush;
    std::cin >> n;

    std::vector<int> bdays;
    std::srand (time(NULL));

    bool matchFound = false;

    if(n > 366)
        matches = total;
    else{
        // Write your code here
        for (int i = 0; i<total; i++){
            // random bdays
            for (int j = 0; j<n; j++){
                bdays.push_back(std::rand() % 366);
            }

            for (int j = 0; j<n; j++){
                for (int k = j+1; k<n; k++){
                    if (bdays[j] == bdays[k]){
                        matchFound = true;;
                    }
                }
            }

            bdays.clear();

            if (matchFound){
                matches++;
                matchFound = false;
            }
        }
    }

    std::cout << "The probability of a birthday match is " << (double)matches/total << "\n\n" << std::flush;  

    return 0;
}
