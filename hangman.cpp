//da cpp

#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

void displayGameDetailes(int maxTries, int remainingTries);
string chooseSecretWord();
void replaceDashes(char guessWord[], int length, string secretWord);
void checkAndUpdateGuess(char guessWord[], int length, string secretWord, char guess;

int main()
{
    int maxTries(9);
    int remainingTries(9);
    char guessLetter;
    string  secretWord= chooseSecretWord();
    int secretWordLength= secretWord.legth();
    char guessWord[secretWordLength + 1];
    replaceDashes(guessWord, secretWordLength, secretWord);
    guessWord[secretWordLength] = '\0'; 
    checkAndUpdateGuess(guessWord, secretWordLength, secretWord, guessLetter);
    displayWord(guessWord, secretWordLength);
    
    displayGameDetails(maxTries, remainingTries);
    cout << "Your guess word is: ";
    displayWord(guessWord, secretWordLength);
    //ere ene i am going to cry uuuu
    cout << "Enter a letter to guess: ";
    cin >> guessLetter;


    return 0;
}

//this calls out the display game details functions 
void displayGameDetailes (int maxTries, int remainingTries){
    cout<<"welcome to hangman dawg, where we hang your man"<<endl;
    cout<<"the number of trials you have is "<<maxTries<<endl;
    cout <<"the number of trials left is "<< remainingTries<<endl;

    
}
//first part of the code, initializing and the printing stuff
//yes it was indeed a pain in the ass to make 


string chooseSecretWord() {
    srand(time(NULL));
    string flowers[]= 
    {"daffodils", "dandalion", "baby-breaths","forget-me-not",
    "roses", "tulips","sunflowers","annemone", "cherry-blossoms", 
    "camellia", "honey-suckle", "daisy", "mangolia","orchide", "lavender",
    "lily", "violet", "jasmine", "carnation", "peony" };

    int randomIndex = (rand() % 20);
    string word = flowers[randomIndex];
    return word;
}
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
