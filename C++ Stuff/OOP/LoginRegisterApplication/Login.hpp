#include <iostream>
#include <string.h>


class Login{
  private:
    std::string username;
    std::string password;
  
  public:
    Login();
    Login(std::string username, std::string password);
    ~Login();
    std::string getUsername();
    std::string getPassword();
    bool checkCredentials(std::string username , std::string password);
    
};