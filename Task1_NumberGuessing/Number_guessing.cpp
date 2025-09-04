#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    srand(time(0)); // seed for random number
    int numberToGuess = rand() % 100 + 1; // random number between 1 and 100
    int userGuess;
    int attempts = 0;

    cout << "🎲 Number Guessing Game 🎲" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > numberToGuess) {
            cout << "Too High! Try again." << endl;
        } else if (userGuess < numberToGuess) {
            cout << "Too Low! Try again." << endl;
        } else {
            cout << "🎉 Congratulations! You guessed the number in " 
                 << attempts << " attempts." << endl;
        }
    } while (userGuess != numberToGuess);

    return 0;
}
