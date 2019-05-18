#include "Sort.h"
using namespace std;
Sort::Sort()
{
  arr = new int[10];
  size = 10;
}
Sort::Sort(int* a, int s)
{
  arr = a;
  size = s;
}
Sort::~Sort()
{
  delete arr;
}
void Sort::printList()
{
  for(int i = 0; i < size; ++i)
    cout << arr[i] << endl;
}
void Sort::BubbleSort()
{
  for(int i = 0; i < size; i++)
	   for(int j = 0; j < size; j++)
	      if(arr[j] > arr[j+1])
		        swap(j, j+1);
}
void Sort::swap(int a, int b) //swaps indexes
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}
void Sort::insertionSort()
{
  int i, key, j;
  for (i = 1; i < size; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int Sort::partition(int lo, int hi)
{
  int pivot = arr[hi];
  int i = lo - 1;
  for(int j = lo; j <= hi - 1; j++)
    if (arr[j] <= pivot)
    {
      i++;
      swap(i, j);
    }
  swap(i+1, hi);
  return i+1;
}
void Sort::quickSort(int lo, int hi)
{
  if (lo < hi)
  {
    int pi = partition(lo, hi);
    quickSort(lo, pi-1);
    quickSort(pi+1, hi);
  }
}
void Sort::bogoSort()
{
  while(!sorted())
  {
    randomize();
    printList();
  }
}
void Sort::randomize()
{
  srand(0);
  for (int i = 0; i < size-1; i++)
  {
    int r = rand() % size;  // generate a random position
    swap(i, r);
  }
}
bool Sort::sorted()
{
  int i = 0;
  while(i < size - 1)
  {
    if(arr[i] > arr[i+1])
      return false;
    i++;
  }
  return true;
}
