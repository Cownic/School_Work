#include <bits/stdc++.h>
using namespace std;

void print_list(vector<int>&list);
void sort_list(vector<int>&list);

int main()
{
  int n;
  vector<int> list;

  cout << "Enter the number of integers you want to sort: " << endl;
  cin >> n;

  for (int i = 0 ; i < n ; i++){
    list.push_back(rand()%100);
  }

  print_list(list);

  sort_list(list);



  print_list(list);


  
}

void sort_list(vector<int>&list)
{
  int temp;
  for (int i = 0 ; i < list.size() ; i++){
    for (int j = 0 ; j < list.size() ; j++){
      if (list[i] > list[j]){
        temp = list[j];
        list[j] = list[i];
        list[i] = temp;
      }
    }
  }
}

void print_list(vector<int>&list)
{
  for(int i = 0 ; i < list.size() ; i++){
    cout << list[i] << " ";
  }
  cout << endl;
}