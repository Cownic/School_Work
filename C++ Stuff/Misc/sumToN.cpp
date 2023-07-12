#include <iostream>
using namespace std;

int sum(int end);

int main()
{
  int end;
  cout << "Enter the number that you want to sum to from 1: \n";
  cin >> end;
  cout << "The result is : " << sum(end) << endl;
  exit(0);
}

int sum(int end)
{
  if (end == 0){ // ending condition
    return 0;
  }
  else {
    return end + sum(end - 1);
  }
}