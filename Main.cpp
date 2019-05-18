#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
#include "Sort.h"
using namespace std;
int* getFile(string fileName, int size);
int main(int argc, char** argv)
{
  int *arr0 = getFile("very_small_boy.txt", 3);
  int *arr1 = getFile("small_boy.txt", 100);
  int *arr2 = getFile("med_boy.txt", 1000);
  int *arr3 = getFile("big_boy.txt", 10000);
  Sort sort0 = Sort(arr0, 3);
  Sort sort1 = Sort(arr1, 100);
  Sort sort2 = Sort(arr2, 1000);
  Sort sort3 = Sort(arr3, 10000);

  clock_t startTime;
  double time;
  startTime = clock();
  sort0.bogoSort();
  sort0.printList();
  time = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  /*
  for(int i = 0; i < 100; i++)
  {
    startTime = clock();
    //sort1.BubbleSort(); //4.613e-5
    //sort1.insertionSort(); //4.25e-6
    sort1.quickSort(0, 100); //8.519e-5
    //sort1.printList();
    //sort0.bogoSort();
    time += (double)(clock() - startTime) / CLOCKS_PER_SEC;
  }
  time /= 100;*/
  cout << "Average Time Taken: " << time << " seconds" << endl;
  return 0;
}
int* getFile(string fileName, int size)
{
  int *arr = new int[size];
  ifstream file;
  file.open(fileName, ifstream::in);
  string line;
  int num;
  for(int i = 0; i < size; ++i)
  {
    if(!file.eof())
    {
      getline(file, line);
      num = stoi(line);
      arr[i] = num;
    }
  }
  file.close();
  return arr;
}
