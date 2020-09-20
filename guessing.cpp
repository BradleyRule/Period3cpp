#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



/* BY: Bradley Rule    9/16/2020
  This program generates a random number and then asks the user to continuously guess at the number.
  It will tell the user if their guess is too high or low and when they guess it it will ask if they
  want to play again.
 */
int main()
{
  // these are the variables that will keep track of important data
  //as long as keepPlaying is 'y', the program will continue to repeat
  char keepPlaying = 'y';
  //This variable keeps track of the number of guesses the user has made
  int numberOfGuesses = 0;
  //sets the seed for the rand() function
  srand (time(NULL));
  //variable to store the user's guesses
  int guess = 0;
  //variable that holds the random number
  int number = rand()%100;
  //this variable keeps track of wether or not the user has successfully guessed the number
  char win = 'n';
   
  while(keepPlaying == 'y'){//this while loop continues for as long as the user wants to keep playing.

    //here we have to reset some of the variables in case the user decides to play again
    win = 'n';
    number = rand()%100;
    numberOfGuesses = 0;
    guess = 0;
    
    while(win == 'n'){//this while loop continues for as long as the user hasn't guessed the number.

      //this asks the user for a guess and then stores the guess and increases the number of guesses by one.
      cout << "Guess a number (1-100):" << endl;
      cin >> guess;
      numberOfGuesses++;

      //this series of if / else statements checks if the user guessed correctly or not
      if(guess < number)
	{//if the guess was too low, it tells this to the user and continues
	  cout << "Your guess was too low. Try again." << endl;
	}
      else if(guess > number)
	{//if the guess is too high, it tells this to the user and continues
	  cout << "Your guess was too high. Try again." << endl;
	}
      else {//if both of the first two conditions are false, the user must have guessed correctly
	//the program tells the user they got the number right and how many tries it took them.
	cout << "You guessed the number and it took you " << numberOfGuesses << " tries." << endl;
	//here, the program asks if the user wants to play again 
	cout << "would you like to play again? (y/n)" << endl;
	//if they respond with yes, the while loop does not end and they keep playing
	cin >> keepPlaying;
	//the win function is set to 'y', in order to reset the random number and other variables.
	win = 'y'; 
      }
    }
  }
  
  return 0;
}
