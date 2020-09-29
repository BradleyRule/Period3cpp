#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  int count = 0;
  char input[80];
  char adjustedInput[80];
  char reverseInput[80];
  cin.get(input, 80);
  cin.get();
  int count2 = 0;
  int character = 0;



  cout << "input: " << input << endl;

  
  for (int i = 0; i < 81; i++)//in this for loop the punctuation will be removed
    {
      if (input[i] >= 97 && input[i] <= 122){
	adjustedInput[count] = input[i];
	++count;
      }

      /* if (input[i] >= 65 && input[i] <= 90){
	character = input[i];
	adjustedInput[count] = (character + 32);
	++count;
      }
      */
    }
  adjustedInput[count] = '\0';
  cout << "adjustedInput: " << adjustedInput << endl;





  
  
  for (int i = 0; i < 81; i++){
     if (input[80 - i] >= 97 && input[80 - i] <= 122){
       reverseInput[count2] = input[80 - i];
       ++count2;
     }
  }
reverseInput[count2] = '\0';
cout << "reverseInput: " << reverseInput << endl;




 
  return 0;
}
