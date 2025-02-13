//da cpp

#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

//these are the functions 
//a.
void displayGameDetailes(int maxTries, int remainingTries);
//b.
string chooseSecretWord();
//c.
void replaceDashes(char guessWord[], int length, string secretWord);
//d.
//void checkAndUpdateGuess(char guessWord[], int length, string secretWord, char guess);
//e.
string guessWord;
int secretWordLength;

//string displayWord(guessWord, secretWordLength);

int main()
{
    int maxTries(9);
    int remainingTries(9);
    char guessLetter;
    string  secretWord= chooseSecretWord();
    int secretWordLength= secretWord.length();
    char guessWord[secretWordLength + 1];
    
    // this is me calling out the functions
    replaceDashes(guessWord, secretWordLength, secretWord);
    guessWord[secretWordLength] = '\0'; 
    //checkAndUpdateGuess(guessWord, secretWordLength, secretWord, guessLetter);
    displayGameDetailes(maxTries, remainingTries);
    cout << "Your guess word is: ";
    //displayWord (guessWord, secretWordLength);
    
    //what needs to be printed 
    cout << "Enter a letter to guess: ";
    cin >> guessLetter;

    srand(time(NULL));  
    cout << "Random flower: " << chooseSecretWord() << endl;
    
    //aight what i am about to do rn is tocall out the void function that makes checkes n updates guesses
    int guesses = 0, correctGuesses = 0;
    char letter;
    string word, guess0 = "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
    bool correct = false;

    cout<<"Welcome to Hangman!\nWhat word would you like the player to guess?\n";
    cin>>word;
    int n = word.length();
    cout << "\n\n\n\n\n";

    
    string guess = guess0.substr(0, 2 * n);
    char guessWord[n + 1];
    for (int i = 0; i < n; i++) {
        guessWord[i] = '_';
    }
    guessWord[n] = '\0';  // Null-terminate the array

    while (true) {
       for (int i = 0; i < n; i++) {
       cout<<guessWord[i]<<" ";
        }
        cout<<endl;
        cin>>letter;
        checkAndUpdateGuess(guessWord, n, word, letter);
        correctGuesses = 0;
        for (int i = 0; i < n; i++) {
            if (guessWord[i] != '_') {
                correctGuesses++;
            }
        }

        // Check win or lose condition
        if (correctGuesses == n) {
            cout<<word<<"\nYou won!"<<endl;
            break;
        }
        else if (guesses == 9) {
            cout<< word<< "\nYou lost!"<< endl;
            break;
        }

        guesses++;
    }

    return 0;
}
    
}
//there is still an error on line 37 but miving on for now


//this calls out the display game details functions and defines it
//a.
void displayGameDetailes (int maxTries, int remainingTries){
    cout<<"welcome to hangman dawg, where we hang your man"<<endl;
    cout<<"the number of trials you have is "<<maxTries<<endl;
    cout <<"the number of trials left is "<< remainingTries<<endl;

    
}
//b
// aight this is me defining b as well
//also i moved the srand thingy to the main function so fingers crossed
string chooseSecretWord() {
    srand(time(NULL));
    string flowers[]= 
    {"daffodils", "dandelion", "zinnia","dahlia","lavender",
    "roses", "tulips","sunflowers","annemone", "freesia", 
    "camellia", "bluebell", "daisy", "magnolia","orchid",
    "lily", "violet", "jasmine", "carnation", "peony" };
    
    int arraySize = sizeof(flowers) / sizeof(flowers[0]); 
    int randomIndex = rand() % arraySize;
    return flowers[randomIndex];
    }


//c.
//aight lets go with the guessing option, here it goes and i added a hinting feature 
void replaceDashes(char guessWord[], int length, string secretWord) {
    int hints = 2;
    for (int i = 0; i < length; ++i) {
        guessWord[i] = '-';
    }
    while (hints > 0) {
        int pos = rand() % length;
        if (guessWord[pos] == '-') {
            guessWord[pos] = secretWord[pos];
            hints--;
        }
    }
}
//d
//okay i am supposed to define the function that validates n checks wors but i swear that doofuse's code just look so good 
    
   void checkAndUpdateGuess(char guessWord[], int length, string secretWord, char guess) {
    bool correct = false;  // To track if the guess is correct
       
    for (int i = 0; i < length; i++) {
        if (guess == secretWord[i]) {
            guessWord[2 * i] = guess;  // Update the guessWord at the correct position
            correct = true;
        }
    }
    
    if (!correct) {
        cout << "mtsm Incorrect guess!" << endl;
    }
}

      /*  if (attemptsLeft == 9) {
            cout<< " " <<endl;
            cout<< " " <<endl;
            cout<<"  " <<endl;
            cout<< " " <<endl;
            cout<< "  "<<endl;
            cout<< "  "<<endl;
            cout<< "  "<<endl;
        }
        else if (attemptsLeft == 8) {
            cout<< "    " <<endl;
            cout<< "  | " <<endl;
            cout<< "  | " <<endl;
            cout<< "  | "<<endl;
            cout<< "  | " <<endl;
            cout<< "  | " <<endl;
            cout<< "  | " <<endl;
        }
        else if (attemptsLeft == 7) {
            cout<< "   _____" <<endl;
            cout<< "  |     " <<endl;
            cout<< "  |     " <<endl;
            cout<< "  |     " <<endl;
            cout<< "  |     " <<endl;
            cout<< "  |     " <<endl;
            cout<< "  |     " <<endl;
        }
        else if (attemptsLeft == 6) {
            cout<< "   _____" <<endl;
            cout<< "  |     |" <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
        }
        else if (attemptsLeft == 5) {
            cout<< "   _____" <<endl;
            cout<< "  |     |" <<endl;
            cout<< "  |     O" <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |      " <<endl;
        }
        else if (attemptsLeft == 4) {
            cout<< "   _____" <<endl;
            cout<< "  |     |" <<endl;
            cout<< "  |     O" <<endl;
            cout<< "  |     |" <<endl;
            cout<< "  |      " <<endl;
            cout<< "  |" << endl;
            cout<< "  |" << endl;
        }
        else if (attemptsLeft ==3){
            cout<< "   _____"<<endl;
            cout<< "  |     |"<<endl;
            cout<< "  |     O"<<endl;
            cout<< "  |    /|"<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl;   
            }
        else if (attemptsLeft ==2){
            cout<< "   _____"<<endl;
            cout<< "  |     |"<<endl;
            cout<< "  |     O"<<endl;
            cout<< "  |    /|\\"<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl; 
        }
        else if (attemptsLeft ==1){
            cout<< "   _____"<<endl;
            cout<< "  |     |"<<endl;
            cout<< "  |     O"<<endl;
            cout<< "  |    /|\\"<<endl;
            cout<< "  |    /"<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl; 
}
else if (attemptsLeft ==0){
            cout<< "   _____"<<endl;
            cout<< "  |     |"<<endl;
            cout<< "  |     O"<<endl;
            cout<< "  |    /|"<<endl;
            cout<< "  |    / \\ "<<endl;
            cout<< "  |      "<<endl;
            cout<< "  |      "<<endl; 
}*/
//yes i am just gon go and cry now
//btw i hope this comes in handy cuz my 2 brai cells didnt think to copy and paste until trial 3

   
