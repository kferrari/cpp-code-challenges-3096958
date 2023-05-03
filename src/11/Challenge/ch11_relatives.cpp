// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    bool found = false;
    // Read the CSV file.
    if(file.is_open()){

        // Write your code here
        std::map<std::string, std::string> names;
        std::string line, first, last;

        while(std::getline(file, line, ',')){
            std::cout << line << std::endl;

            auto end = line.find(' ');
            first = line.substr(0, end);
            line.erase(line.begin(), line.begin() + end + 1);
            end = line.find(' ');
            last = line.substr(0, end);

            if (names[last] != ""){
                std::cout << "Relatives found:" << std::endl;
                std::cout << first << " " << last << std::endl;
                std::cout << names[last] << " " << last << std::endl;
                found = true;
                break;
            }

            names[last] = first;
        };
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    if (found){
        return 0;
    }
    
    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 