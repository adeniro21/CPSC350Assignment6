#include "sort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <ctime>
#include <stdio.h>

using namespace std;

int arraySize = 0;
int* unsortedArray;
int* unsortedArray2;
int* unsortedArray3;
int* unsortedArray4;

Sorts::Sorts()
{

}

Sorts::~Sorts()
{
  delete [] ::unsortedArray;
  delete [] ::unsortedArray2;
  delete [] ::unsortedArray3;
  delete [] ::unsortedArray4;
}

void Sorts::readFile(string file)
{
  int count = 0;
  int i = 0;
  ::unsortedArray = new int[::arraySize];
  ::unsortedArray2 = new int[::arraySize];
  ::unsortedArray3 = new int[::arraySize];
  ::unsortedArray4 = new int[::arraySize];
  string line;
  ifstream locFile;
  locFile.open(file, ios::in);
  if (locFile.is_open())
  {
    while(!locFile.eof())
    {
      getline(locFile, line);
      count++;
      if(count == 1)
      {
        stringstream sizer(line);
        int y = 0;
        sizer >> y;
        ::arraySize = y;
      }
      else
      {
        stringstream input(line);
        int x = 0;
        input >> x;
        if(i < ::arraySize)
        {
          ::unsortedArray[i] = x;
          ::unsortedArray2[i] = x;
          ::unsortedArray3[i] = x;
          ::unsortedArray4[i] = x;
          i++;
        }
      }
    }
  }
  else
  {
    cout << "Not a valid file" << endl;
  }
  locFile.close();
}

void Sorts::viewArray()
{
  for (int i = 0; i < ::arraySize; i++)
  {
    cout << ::unsortedArray[i] << " ";
  }
  cout << "" << endl;
  cout << " " << endl;
}

void Sorts::bubblesort(int* myArray)
{
  clock_t start_time = clock();
  for (int i = 0; i < ::arraySize; i++)
  {
    int temp = 0;
    for (int j = 0; j < ::arraySize; j++)
    {
      if(myArray[i] < myArray[j])
      {
        temp = myArray[j];
        myArray[j] = myArray[i];
        myArray[i] = temp;
      }
    }
  }
  clock_t end_time = clock();
  /*
  for (int i = 0; i < ::arraySize; i++)
  {
    cout << myArray[i] << " ";
  }
  cout << " " << endl;
  */
  cout << "bubble sort" << endl;
  cout << " start time: " << start_time << " seconds" << endl;
  cout << " end time: " << end_time << " seconds" << endl;
  cout << "" << endl;
}

void Sorts::insertsort(int* myArray2)
{
  clock_t start_time = clock();
  int i = 0;
  int key = 0;
  int j = 0;
  for (i = 1; i < ::arraySize; i++)
  {
      key = myArray2[i];
      j = i - 1;
      while (j >= 0 && myArray2[j] > key)
      {
          myArray2[j + 1] = myArray2[j];
          j = j - 1;
      }
      myArray2[j + 1] = key;
  }
  clock_t end_time = clock();
  /*
  for (int i = 0; i < ::arraySize; i++)
  {
    cout << myArray2[i] << " ";
  }
  cout << " " << endl;
  */
  cout << "insert sort" << endl;
  cout << " start time: " << start_time << " seconds" << endl;
  cout << " end time: " << end_time << " seconds" << endl;
  cout << " " << endl;
}


void Sorts::swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int Sorts::partition (int* myArray3, int low, int high)
{
  int pivot = myArray3[high];    // pivot
  int i = (low - 1);  // Index of smaller element

  for (int j = low; j <= high- 1; j++)
  {
    if (myArray3[j] <= pivot)
    {
      i++;    // increment index of smaller element
      swap(&myArray3[i], &myArray3[j]);
    }
  }
  swap(&myArray3[i + 1], &myArray3[high]);
  return (i + 1);
}

int Sorts::quicksort(int* myArray3, int low, int high)
{
  clock_t start_time = clock();
  if (low < high)
  {
    int pi = partition(myArray3, low, high);

    quicksort(myArray3, low, pi - 1);
    quicksort(myArray3, pi + 1, high);
  }

  clock_t end_time = clock();
  cout << "quick sort" << endl;
  cout << " start time: " << start_time << " seconds" << endl;
  cout << " end time: " << end_time << " seconds" << endl;
  cout << " " << endl;
}

void Sorts::displayQuickSort()
{

}

void Sorts::shakersort(int* myArray4)
{
  clock_t start_time = clock();
  int n = ::arraySize;
	int i = 0;
  int j = 0;
  int k = 0;
	for(i = 0; i < n;)
	{
		// First phase for ascending highest value to the highest unsorted index.
		for(j = i+1; j < n; j++)
		{
			if(myArray4[j] < myArray4[j-1])
				swap(&myArray4[j], &myArray4[j-1]);
		}
		// Decrementing highest index.
		n--;

		// Second phase for descending lowest value to the lowest unsorted index.
		for(k = n-1; k > i; k--)
		{
			if(myArray4[k] < myArray4[k-1])
				swap(&myArray4[k], &myArray4[k-1]);
		}
		// Incrementing lowest index.
		i++;
	}
  clock_t end_time = clock();
  /*
  for (int i = 0; i < ::arraySize; i++)
  {
    cout << ::unsortedArray[i] << " ";
  }
  cout << " " << endl;
  */
  cout << "shaker sort" << endl;
  cout << " start time: " << start_time << " seconds" << endl;
  cout << " end time: " << end_time << " seconds" << endl;
}

void Sorts::run()
{
  bubblesort(::unsortedArray);
  insertsort(::unsortedArray2);
  quicksort(::unsortedArray3, 0, ::arraySize);
  //displayQuickSort();
  shakersort(::unsortedArray4);
}
