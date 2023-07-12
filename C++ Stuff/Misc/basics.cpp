#include <iostream>
#include <string.h> //use string functions 
#include <cmath> //use math functions
using namespace std;

void print();

int main()
{
  //Double \n will created a blank line
  //Using const will prevent others from changing the declared variable
  //use getline(cin , variable name) to get string with spacing from stdin
  //use sizeof(array) / sizeof(array[0]) to get the length of the array
  //changing the value at the pointer address will change the value of the variable at that particular address also
  //Pass by reference when we wanna change the value of the arguements in our functions directly - pass in the addresses of the variables

  const int fixed = 10;
  int num = 4;
  double nums = 4.1;
  char c = 'c';
  string name ;
  bool task = true;
  string cars[] = {"Volvo" , "BMW" , "Ford" , "Mazda"};
  string food = "Pizza"; //food variable
  string &meal = food; //reference to food
  string* foodptr = &food;

  //print();
  //cout << food << meal << *foodptr << endl;
  // for (int i = 0 ; i < sizeof(cars) / sizeof(cars[0]) ; i++){
  //   cout << cars[i] + "\n";
  // }
  // cout << "Enter your name\n";
  // getline(cin , name);
  // cout << name ;
  // cout << max(5,10);
  // cout << max('A' , 'B');

  int n = 1012;
  int temp = n;
  int count = 0;

  while (temp > 0){
    if ((temp%10) == 0){
      //continue; this will break one loop of the while loop , which means i will never divide the temp
    }
    else {
      if (n % (temp%10) == 0){
          count++;
      }
    }
    temp /= 10;
  }

  
}

void print()
{
  cout << "Hello World\n";
}