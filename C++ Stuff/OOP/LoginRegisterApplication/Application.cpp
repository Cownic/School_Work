#include <iostream>
#include "Login.hpp"
#include "Register.hpp"

void display();
int main()
{
  int choice, i;
  std::string username;
  std::string password;
  Login login;
  Register reg;


  display();
  std::cout << "Enter your choice:\n";
  std::cin >> choice;

  while (choice < 3)
  {
    switch (choice)
    {
    case 1:
      // call register object
      std::cout << "Enter your Username: ";
      std::cin >> username;
      std::cout << "\nEnter your Password: ";
      std::cin >> password;
      if (reg.isValidPassword(password)){
        reg.dataToText(username, password);
      }
      else {
        std::cout << "Sorry your password is invalid\n";
      }
      break;
    case 2:
      // call login object
      std::cout << "Enter your Username: ";
      std::cin >> username;
      std::cout << "\nEnter your Password: ";
      std::cin >> password;
      i = login.checkCredentials(username, password);
      if (i)
      {
        std::cout << "Sucessfully Login\n";
      }
      else
      {
        std::cout << "Login Fail, Please Try again\n";
      }
      break;
    case 3:
      exit(0);
      break;

    default:
      std::cout << "Invalid Choice Entered, Please try again..\n";
      break;
    }
    display();
    std::cin >> choice;
    username.clear();
    password.clear();
  }

  login.~Login;
  reg.~Register;
  exit(0);
}

void display()
{
  std::cout << "__________________________\n";
  std::cout << "Welcome to Hell\n";
  std::cout << "1. Register an Account\n";
  std::cout << "2. Login\n";
  std::cout << "3. Exit\n";
  std::cout << "__________________________\n";
}