#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    int secretNum, userGuess;

    //  random number generator
    srand(time(0));
    secretNum = rand() % 100 + 1; // Random number between 1 and 100

    cout << "Guess the Number Game!\n";
    cout << "________________________\n\n";
    cout << "I have selected a number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > secretNum) {
            cout << "Too large! Try again.\n";
        } else if (userGuess < secretNum) {
            cout << "Too small! Try again.\n";
        } else {
            cout << "Win Win! You guessed the correct number: " << secretNum << endl;
        }

    } while (userGuess != secretNum);

    return 0;
}
