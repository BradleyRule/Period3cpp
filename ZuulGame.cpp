#include <iostream>
#include "Room.h"
#include <vector>
#include <cstring>

using namespace std;


int main(){

  vector<Room*> list;
  
  char* firstRoom = new char[80];
  char* firstItem = new char[20];
  strcpy(firstRoom, "Cafeteria");
  strcpy(firstItem, "lunch tray");
  list.push_back(new Room(firstRoom));

  char* secondRoom = new char[80];
  strcpy(secondRoom, "Lower Commons");
  list.push_back(new Room(secondRoom));

  

  for (std::vector<Room*>::iterator it = list.begin(); it != list.end(); ++it){
    if((*it)->getDescription() == "Cafeteria"){
      (*it)->addItems(firstItem);
    }
  }
  

  for (std::vector<Room*>::iterator it = list.begin(); it != list.end(); ++it){
    cout << (*it)->getDescription() << endl;
    (*it)->getItems();
  }
  
  
  return 0;
}
