#include <iostream>
#include "Room.h"
#include <cstring>

using namespace std;

Room::Room(char* newdescription){
  description = newdescription;
  id = 0;
  for (int i = 0; i < 5; i++){
    items[i] = new char[20];
    items[i][0] = '\0';
  }
}

char* Room::getDescription(){
  return description;
}

int Room::getID() {
  return id;
}

void Room::addItems(char* item){
  for(int i = 0; i < 5; i++){
    if(items[i][0] == '\0'){
      strcpy(items[i], item);
      i = 5;
    }
  }
}

void Room::getItems(){
  for(int i = 0; i < 5; i++){
    if(!(items[i][0] == '\0')){
      cout << items[i] << endl;
    }
  }
}
