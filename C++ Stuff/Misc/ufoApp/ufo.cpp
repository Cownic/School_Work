#include <iostream>
#include "ufo_functions.hpp"

int main() {
  
  greet();
  std::string codeword = "codecademy";
  std::string answer ="__________";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  while (answer != codeword && misses < 7){
    display_misses(misses);
    display_status(answer, incorrect);

    std::cout << "Please enter your guess: \n";
    std::cin >> letter;

    for (int i = 0 ; i < codeword.size() ; i++){
      if (codeword[i] == letter){
        guess = true;
        answer[i] = letter;
      }
    }

    if (guess){
      std::cout << "Correct!\n";
    }
    else {
      std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }

    guess = false;
  }
  end_game(misses);
}
