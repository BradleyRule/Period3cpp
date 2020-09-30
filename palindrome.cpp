#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  // this integer countes the number of character in adjusted input
  int count = 0;
  //the user input
  char input[80];
  //the user input with uppercase converted to lower case and punctuation and spaces removed
  char adjustedInput[80];
  //the reverse of adjusted input
  char reverseInput[80];
  //read in the user input
  cin.get(input, 81);
  cin.get();
  // this integer countes the number of character in reverse input
  int count2 = 0;
  //stores what upper case character is in input (is used to convert uppercase to lower case
  int character = 0;
  //keeps track of wether or not the input is a palindrome
  bool tf = 1;


  
  for (int i = 0; i < 81; i++)//in this for loop the punctuation will be removed and uppercase converted to lower case
    {
      if (input[i] >= 97 && input[i] <= 122){
	adjustedInput[count] = input[i];
	++count;
      }

      if (input[i] == '\0'){
	adjustedInput[i] = '\0';
	i = 81;
      }

      //if the characater is an uppercase letter
      if (input[i] >= 65 && input[i] <= 90){
	//save what the letter is
	character = input[i];
	//put the lowercase version of the letter in adjusted input
	adjustedInput[count] = (character + 32);
	//increase the counter
	++count;
      }
      
    }





  
  
  for (int i = 0; i < (count + 1); i++){//this for loop copies the adjustedInput into the reverse input but backwards
    if (adjustedInput[count - i] >= 97 && adjustedInput[count - i] <= 122){//if it is a letter
      //take the adjusted input and put it into the reverse input
       reverseInput[count2] = adjustedInput[count - i];
       //increase counter two
       ++count2;
     }
  }
  //add a null character to the end
  reverseInput[count2] = '\0';






  

  for (int i = 0; i < count; i++){//for loop to check if reverseInput and adjustedInput are equal
    if(reverseInput[i] != adjustedInput[i]){//if they are not eqaul
      //set tf to false
      tf = 0;
      //cout << i << ": " << reverseInput[i] << ", " << adjustedInput[i] << endl;
    }
 }







  
  if(tf == 1){//if they are equal
    //tell the user that it is a palindrome
   cout << "This is a palindrome" << endl;
 }
  else{//if not equal
    //tell the user it is not a palindrome
   cout << "Not a palindrome." << endl;
 }





 
  return 0;
}
