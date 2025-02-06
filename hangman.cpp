//da cpp

#include <iostream>
using namespace std;
void displayGameDetailes(int maxTries, int remainingTries);

int main()
{
    int maxTries(9);
    int remainingTries(9);
    char guessLetter;
    string secretWord;
    int secretWordLength;
    
    displayGameDetailes( maxTries, remainingTries);
}
void displayGameDetailes (int maxTries, int remainingTries){
    cout<<"welcome to hangman dawg, where we hang your man"<<endl;
    cout<<"the number of trials you have is "<<maxTries<<endl;
    cout <<"the number of trials left is "<< remainingTries<<endl;

    
}
//first part of the code, initializing and the printing stuff
//yes it was indeed a pain in the ass to make 
