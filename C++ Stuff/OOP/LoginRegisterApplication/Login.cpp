#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Login.hpp"

Login::Login(){};

Login::Login(std::string username, std::string password):username(username) , password(password){};

Login::~Login(){
  std::cout << "Deleting Login Object\n";
};

std::string Login::getUsername(){
  return username;
};

std::string Login::getPassword(){
  return password;
};

bool Login::checkCredentials(std::string username_t , std::string password_t){

  std::vector<std::string> usernameList;
  std::vector<std::string> passwordList;
  bool usernameFlag = false;
  bool passwordFlag = false;

  //create a text string, which is used to output the text file
  std::string username;
  std::string password;

  //read from the username file
  std::ifstream readUsername("Username.txt");
  std::ifstream readPassword("Password.txt");

  //Use a while loop together with the getline() function to read the file line by line
  while (getline(readUsername , username)){
    //output the text from the file
    usernameList.push_back(username);
    //std::cout << username << "\n";
  }

  while (getline(readPassword , password)){
    //output the text from the file
    passwordList.push_back(password);
    //std::cout << password << "\n";
  }
  readUsername.close();
  readPassword.close();

  for (int i = 0 ; i < usernameList.size() ; i++){
    //std::cout << usernameList[i] << username_t << "\n";
    if (usernameList[i] == username_t){
      
      usernameFlag = true;
    }
  }

  for (int j = 0 ; j < passwordList.size() ; j++){
    //std::cout << passwordList[j] << password_t << "\n";
    if(passwordList[j] == password_t){
      
      passwordFlag = true;
    }
  }

  if (passwordFlag && usernameFlag){
    return true;
  }
  return false;
};
