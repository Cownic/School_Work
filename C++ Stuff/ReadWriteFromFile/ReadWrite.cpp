#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  //create and open a file
  //ofstream test("file1.txt");

  // //write to the file
  // test << "Files can be tricky, but it is fun enough!\n";
  // test << "Help";

  // //close the file
  // test.close();
  // cout << "File is closed..\n";

  //create a text string, which is used to output the text file
  string myText;

  //read from the text file
  ifstream readtest("file1.txt");

  //Use a while loop together with the getline() function to read the file line by line
  while (getline(readtest , myText)){
    //output the text from the file
    cout << myText << "\n";
  }
  readtest.close();
}