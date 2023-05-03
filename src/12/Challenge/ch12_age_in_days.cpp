// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

bool isLeap(int y){
    if (y % 4 != 0){
        return false;
    } else if (y % 100 != 0){
        return true;
    } else if (y % 400 != 0){
        return false;
    } else {
        return true;
    }
}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here

    // Get todays date
    const time_t now = time(0);
    tm *ltm = localtime(&now);

    today_d = ltm->tm_mday;
    today_m = 1 + ltm->tm_mon;
    today_y = 1900 + ltm->tm_year;


    age = 0;
    bool leap = false;

    // Months in birth year
    for (int i = 12; i>=birth_m; i--){
        if ((i % 2 == 1 && i<8) || (i%2 == 0 && i>= 8)){
            age += 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11){
            age += 30;
        }
        if ( i == 2){
            if (isLeap(i)){
                age += 29;
            } else {
                age += 28;
            }
        }
    }

    // Minus days
    age -= birth_d;

    // Calculate days from year + 1
    for (int i = birth_y+1; i<=today_y; i++){
        if (isLeap(i)) {
            age += 366;
        } else {
            age += 365;
        }
    }

    std::cout << age << std::endl;

    // From month
    for (int i = 12; i >= today_m; i--){
        if ((i % 2 == 1 && i<8) || (i%2 == 0 && i>= 8)){
            age -= 31;
        }
        if (i == 4 || i == 6 || i == 9 || i == 11){
            age -= 30;
        }
        if ( i == 2){
            if (leap){
                age -= 29;
            } else {
                age -= 28;
            }
        }
    }

    std::cout << age << std::endl;

    // Add days
    age += today_d;

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
