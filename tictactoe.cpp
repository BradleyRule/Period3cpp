#include <iostream>


using namespace std;



void PrintBoard(char grid[4][4]);
bool CheckWin(char grid[4][4], char playing);
bool CheckTie(char grid[4][4]);

int main(){
  char playing = 'X';
  char grid[4][4];
  bool win = 1;
  char input[2];
  int xwins = 0;
  int owins = 0;
  char ask = 'y';
  char played = 'O';

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      grid[i][j] = ' ';
    }
  }





  
  while(win){
    PrintBoard(grid);
    cout << endl;
    
    if (playing == 'X'){
      cout << "It's X's turn to play." << endl;
      cin.get(input, 3);
      cin.get();
      if (!(grid[input[0] - 48][input[1] - 96] == 'X' || grid[input[0] - 48][input[1] - 96] == 'O')){
	grid[input[0] - 48][input[1] - 96] = 'X';
	playing = 'O';
      }
      else{
	cout << "You cannot overwrite a previous move! Go Again!" << endl;
	cout << endl;
      }

    
    }
    else if (playing == 'O'){
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


    if(playing == 'X'){
      played = 'O';
    }
    else if(playing == 'O'){
      played = 'X';
    }
    
    
    if(CheckWin(grid, played)){
       if(playing == 'O'){
	 ++xwins;
	 cout << "X wins!" << endl;
	 cout << "X has " << xwins << " wins" << endl;
	 cout << "O has " << owins << " wins" << endl;
	 cout << "would you like to keep playing? (y/n)" << endl;
	 cin >> ask;
       }
       else if(playing == 'X'){
	 ++owins;
	 cout << "O wins!" << endl;
	 cout << "X has " << xwins << " wins" << endl;
	 cout << "O has " << owins << " wins" << endl;
	 cout << "would you like to keep playing? (y/n)" << endl;
	 cin >> ask;
       }

			       
      for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	  grid[i][j] = ' ';
	}
      }
      
    }
    
    if(CheckTie(grid)){
      cout << "It's a tie!" << endl;
      
      for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	  grid[i][j] = ' ';
	}
      }
      
      cout << "would you like to keep playing? (y/n)" << endl;
      cin >> ask;
    }
    
    if (ask == 'n'){
      win = 0;
    }
  }












  return 0;
}


bool CheckWin(char grid[4][4], char playing){
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
  return false;
  
}



 bool CheckTie(char grid[4][4]){
   for(int i = 1; i < 4; i++){
     for(int j = 1; j < 4; j++){
       if(!(grid[i][j] == 'X' || grid[i][j] == 'O')){
	 return false;
       }
     }
   }
   return true;
 }

 
void PrintBoard(char grid[4][4]){
  cout << "   1  2  3" << endl;
  cout << "a  " << grid[1][1] << "  " << grid[2][1] << "  " << grid[3][1] << endl;
  cout << "b  " << grid[1][2] << "  " << grid[2][2] << "  " << grid[3][2] << endl;
  cout << "c  " << grid[1][3] << "  " << grid[2][3] << "  " << grid[3][3] << endl;
}
