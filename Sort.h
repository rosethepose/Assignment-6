#include <iostream>
#include <cstdlib>
using namespace std;
class Sort
{
public:
  Sort();
  Sort(int* a, int s);
  ~Sort();
  void printList();
  void BubbleSort();
  void insertionSort();
  void swap(int a, int b);
  int partition(int lo, int hi);
  void quickSort(int lo, int hi);
  void bogoSort();
  void randomize();
  bool sorted();
private:
  int* arr;
  int size;
};
