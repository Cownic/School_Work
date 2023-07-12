#include <iostream>
using namespace std;

class Animals {
  private: //members cannot be accessed from outside the class
    //class attributes (in private and use getters and setters to change them - encapsulation)
    string name;
    string color;
    int age;
  protected: //members cannot be accessed from outside the class, however they can be accessed in inherited classes

  public: //members are accessible from outsie the class
    

    //constructor
    Animals(){}; //default
    Animals(string xname, string xcolor , int xage){
      cout << "A new animal is created..\n";
      name = xname;
      color = xcolor;
      age = xage;
    };

    //methods
    void move();
    void intro(string co){
      cout << name << endl;
      cout << color << endl;
      cout << age << endl;
      cout << co << endl;
    }

    //getters and setters
    string getName(){
      return name;
    }

    void setName(string xName){
      name = xName;
    }
};

void Animals::move(){
  cout << "Move\n";
}

int main()
{
  Animals dog("Gay" , "Black" , 15);
  dog.move();
  dog.intro("Help");
  dog.setName("Qwerty");
  cout << dog.getName();

  exit(0);
}