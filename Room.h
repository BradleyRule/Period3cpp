#include <iostream>
#include <cstring>


using namespace std;

class Room{
 public:
  Room(char*);
  char* getDescription();
  int getID();
  void addItems(char*);
  void getItems();
 private:
  char* description;
  int id;
  char* items[5];
};
