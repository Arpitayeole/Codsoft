#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int B = 10;
    int randomnumber = rand() % B + 1;
    string name;
    int userguess;
    int maxattempts = 5;
    int attempts = 0;

    cout << "PLEASE ENTER YOUR NAME: " << endl;
    getline(cin, name);
    cout << "WELCOME " << name << " TO THE NUMBER GUESSING GAME" << endl;

    do {
        cout << "Enter your guess in the range from 1 to " << B << ": ";

        if (!(cin >> userguess)) {
            cout << "Invalid input! Please enter a numeric value.\n";
            cin.clear();   // Clear the error state
            cin.ignore();  // Discard the invalid input
            continue;      // Ask for input again
        }

        if (userguess > B || userguess < 1) {
            cout << "Invalid guess! Please enter a number within the valid range.\n";
            continue; // Ask for input again
        }
        
        if (userguess < randomnumber) {
            cout << "TOO LOW! TRY AGAIN." << endl;
        } else if (userguess > randomnumber) {
            cout << "TOO HIGH! TRY AGAIN." << endl;
        } else {
            cout << "CONGRATULATIONS! YOU WON." << endl;
            break;
        }
        
        attempts++;

        if (attempts >= maxattempts) {
            cout << "Sorry, you've reached the maximum number of attempts. The correct number was " << randomnumber << ". Better luck next time!\n";
            break;
        }

    } while (userguess != randomnumber);

    return 0;
}