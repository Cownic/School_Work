#include <iostream>
#include <string>


class Register
{
  private:
    std::string username_t;
    std::string password_t;
  
  public:
    Register();
    Register(std::string username, std::string password);
    ~Register();
    std::string getUsername();
    std::string getPassword();
    bool isValidPassword(std::string Password);
    bool dataToText(std::string username ,std::string password);
};