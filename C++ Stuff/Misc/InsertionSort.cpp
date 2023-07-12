#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


void insertionSort(int arr[] , int n)
{
  int temp;
  for(int i = 1 ; i < n ; i++){
    for (int j = i ; j > 0 ; j--){
      if (arr[j] < arr[j-1]){ //pair-wise swapping
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
      else {
        break;
      }
    }
  }
}

void printArray(int arr[] , int n)
{
  for (int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
  }

  cout << "\n";
}

int main()
{
  int array[10];

  //use current time as a seed to generate random numbers
  //srand(time(0));

  for(int i = 0 ; i < 10 ; i++){
    array[i] = rand() % 100;
  }

  cout << "Before Sorting\n";

  printArray(array , 10);

  insertionSort(array , 10);

  cout << "After Sorting\n";

  printArray(array , 10);

  exit(0);
}

