#include <iostream>


using namespace std;


//initialize the functions
void PrintBoard(char grid[4][4]);
bool CheckWin(char grid[4][4], char playing);
bool CheckTie(char grid[4][4]);

int main(){
//keeps track of whos turn it is
  char playing = 'X';
the grid that will save the layout of moves	
  char grid[4][4];
//keeps track of wether or not user wants to continue playing	
  bool win = 1;
//stores input from user	
  char input[2];
//keeps track of number of wins for x	
  int xwins = 0;
//keeps track of number of wins for o
  int owins = 0;
//stores user response to "want to play again?"	
  char ask = 'y';
//keeps track of the last person to play
  char played = 'O';

//fills board with blank spaces to make everything line up
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      grid[i][j] = ' ';
    }
  }





  
  while(win){//while the user has not quit
	  //print the board
    PrintBoard(grid);
    cout << endl;
    
    if (playing == 'X'){//If it is x's turn to play
	    //tell them to play and get input of where they want to play
      cout << "It's X's turn to play." << endl;
      cin.get(input, 3);
      cin.get();
	    
      if (!(grid[input[0] - 48][input[1] - 96] == 'X' || grid[input[0] - 48][input[1] - 96] == 'O')){//if the place they entered is blank
	      //put their mark on the spot and switch turns
	grid[input[0] - 48][input[1] - 96] = 'X';
	playing = 'O';
      }
      else{//if space is not blank force them to play again
	cout << "You cannot overwrite a previous move! Go Again!" << endl;
	cout << endl;
      }

    
    }
    else if (playing == 'O'){//same as previous if statement but for O
      cout << "It's O's turn to play." << endl;
      cin.get(input, 3);
      cin.get();
      if (!(grid[input[0] - 48][input[1] - 96] == 'X' || grid[input[0] - 48][input[1] - 96] == 'O')){
	grid[input[0] - 48][input[1] - 96] = 'O';
	playing = 'X';
      }
      else{
	cout << "You cannot overwrite a previous move! Go Again!" << endl;
	cout << endl;
      }

    
    }


    if(playing == 'X'){//checks to see who just played
      played = 'O';
    }
    else if(playing == 'O'){
      played = 'X';
    }
    
    
    if(CheckWin(grid, played)){//if the person who just played won
       if(playing == 'O'){//tell the player they won and ask them if they want to play again
	 ++xwins;
	 cout << "X wins!" << endl;
	       //tell the players how many wins they have
	 cout << "X has " << xwins << " wins" << endl;
	 cout << "O has " << owins << " wins" << endl;
	 cout << "would you like to keep playing? (y/n)" << endl;
	 cin >> ask;
	 cin.get();
       }
       else if(playing == 'X'){
	 ++owins;
	 cout << "O wins!" << endl;
	 cout << "X has " << xwins << " wins" << endl;
	 cout << "O has " << owins << " wins" << endl;
	 cout << "would you like to keep playing? (y/n)" << endl;
	 cin >> ask;
	 cin.get();
       }

	//clear the board		       
      for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	  grid[i][j] = ' ';
	}
      }
      
    }
    
    if(CheckTie(grid)){//if the board is filled and no one won
      cout << "It's a tie!" << endl;
      //reset the board
      for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	  grid[i][j] = ' ';
	}
      }
      //ask if they would like to play again
      cout << "would you like to keep playing? (y/n)" << endl;
      cin >> ask;
      cin.get();
    }
    //if the user responded with 'n' then the program terminates
    if (ask == 'n'){
      win = 0;
    }
  }












  return 0;
}


bool CheckWin(char grid[4][4], char playing){//checks each possible 3 in a row combination for a win
  if(grid[1][1] == playing && grid[2][1] == playing && grid[3][1] == playing){
    return true;
  }
  else if(grid[1][2] == playing && grid[2][2] == playing && grid[3][2] == playing){
    return true;
  }
  else if(grid[1][3] == playing && grid[2][3] == playing && grid[3][3] == playing){
    return true;
  }
  else if(grid[1][1] == playing && grid[1][2] == playing && grid[1][3] == playing){
    return true;
  }
  else if(grid[2][1] == playing && grid[2][2] == playing && grid[2][3] == playing){
    return true;
  }
  else if(grid[3][1] == playing && grid[3][2] == playing && grid[3][3] == playing){
    return true;
  }
  else if(grid[1][1] == playing && grid[2][2] == playing && grid[3][3] == playing){
    return true;
  }
  else if(grid[1][3] == playing && grid[2][2] == playing && grid[3][1] == playing){
    return true;
    }
	//if none are true nobody won
  return false;
  
}



 bool CheckTie(char grid[4][4]){//checks if all the spaces are xs and os
   for(int i = 1; i < 4; i++){
     for(int j = 1; j < 4; j++){
       if(!(grid[i][j] == 'X' || grid[i][j] == 'O')){
	 return false;
       }
     }
   }
   return true;
 }

 
void PrintBoard(char grid[4][4]){//prints out the board to the console
  cout << "   1  2  3" << endl;
  cout << "a  " << grid[1][1] << "  " << grid[2][1] << "  " << grid[3][1] << endl;
  cout << "b  " << grid[1][2] << "  " << grid[2][2] << "  " << grid[3][2] << endl;
  cout << "c  " << grid[1][3] << "  " << grid[2][3] << "  " << grid[3][3] << endl;
}
