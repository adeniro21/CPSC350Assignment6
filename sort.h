#include <iostream>

using namespace std;

class Sorts
{
  public:
    Sorts();
    ~Sorts();
    void readFile(string location);
    void viewArray();
    void bubblesort(int* myArray);
    void insertsort(int* myArray2);
    void swap(int* a, int* b);
    int partition (int* myArray3, int low, int high);
    int quicksort(int* myArray3, int low, int high);
    void displayQuickSort();
    void shakersort(int* myArray4);
    void run();
};
