#include <string.h>
#include <iostream>
#include <fstream>
#include <ios>
#include "Register.hpp"


Register::Register(){};
Register::Register(std::string username, std::string password):username_t(username), password_t(password){};
Register::~Register(){
  std::cout << "Register is deleted\n";
};
std::string Register::getUsername(){
  return username_t;
};
std::string Register::getPassword(){
  return password_t;
};
bool Register::isValidPassword(std::string password){
  if (password.length() <= 6){
    return true;
  }
  return false;
};

/// @brief Convert the input data into text form , and then store into the text file
/// @param username 
/// @param password 
/// @return True / False on the storing operation
bool Register::dataToText(std::string username ,std::string password){

  std::ofstream openUsername , openPassword;

  openUsername.open("Username.txt" , std::ios_base::app);
  openPassword.open("Password.txt" , std::ios_base::app);


  openUsername << username << "\n"; 
  openPassword << password << "\n";

  return true;
};