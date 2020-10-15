#include <iostream>
#include <vector>

using namespace std;



struct Student {//student object that holds data on each student
  char* firstname;
  char* lastname;
  int id;
  float gpa;  
};

void addStudent(vector<Student*>*);

int main(){
  //used in the DELETE function
  int number = 0;
  //gets user input for what they want to do
  char input[10];
  //gets input of what student id to delete
  int inputTwo = 0;
  //boolean to use in while loop
  bool running = 1;
  //vector that contains students
  vector<Student*>* list = new vector<Student*>();

  
  while (running == 1){
    //Ask user what they want to do
    cout << endl;
    cout << "What would you like to do? (ADD, PRINT, DELETE, QUIT)" << endl;
    //get the input
    cin.get(input, 10);
    cin.get();

    
    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D'){//if input is ADD
      //run addStudent
      addStudent(list);
    }

    if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T'){//if input is PRINT
      for (std::vector<Student*>::iterator it = list->begin(); it != list->end(); ++it){//iterator that goes through eac student
	//print out the first and last name as well as id and gpa of each student
	cout << (*it)->firstname << " " << (*it)->lastname << ", " << (*it)->id << ", ";
	//formating the gpa (it's a float)
	cout.precision(3);
	cout << (*it)->gpa << endl;
      }
    }
    
    //if input is DELETE
    if(input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E'){
      //ask for student id
      cout << "Input the id of the student" << endl;
      //get user input of student id
      cin >> inputTwo;
      cin.get();
      number = 0;
      //anotheriterator to find the student with the matching id
      for (std::vector<Student*>::iterator it = list->begin(); it != list->end(); ++it){
	if((*it)->id == inputTwo){//if the id matches the input
	  //delete the student
	  list->erase(list->begin() + number);
	  //and end the iterator
	  break;
	}
	//increase number by one
	number++;
      }
    }

    if(input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T'){//if input is QUIT
      //set running to zero
      running = 0;
    }
	
    for(int i = 0; i < 11; i++){//clear the input
      input[i] = '\0';
    }
  }



  
  return 0;
}


void addStudent(vector<Student*>* paramlist){//read in the vector
  //create a new student
  Student* newstudent = new Student();
  //create new first and last names
  newstudent->firstname = new char[20];
  newstudent->lastname = new char[20];
  //get first name
  cout << "Enter first name" << endl;
  cin >> newstudent->firstname;
  cin.get();
  //get last name
  cout << "Enter last name" << endl;
  cin >> newstudent->lastname;
  cin.get();
  //get student id
  cout << "enter id number" << endl;
  cin >> newstudent->id;
  cin.get();
  //get gpa
  cout << "Enter GPA" << endl;
  cin >> newstudent->gpa;
  cin.get();
  //add the new student to the end of the vector
  paramlist->push_back(newstudent);
}
