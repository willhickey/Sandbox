#include <iostream>
#include <time.h>
using namespace std;

void quicksort(int*, int, int, int);        //recursive quicksort for int array
void swapElements(int*, int, int);          //swap two elements of an int array
int partitionArray(int*, int, int);         //partition array section between two indicies
void printArray(int*, int);                 //print array, comma separated
int main()
{
    srand(time(NULL));
    //int foo[10] = {1, 9, 4, 12, 33, 2, 6, 5, 65, 10};
    int arraySize = 200;
    int* foo = new int[arraySize];
    for(int i=0; i<arraySize; i++)
    {
       foo[i] = rand() % 1000;
    }
    printArray(foo, arraySize);
    cout<<"Sorting..."<<endl;
    quicksort(foo, 0, arraySize-1, 0);
    printArray(foo, arraySize);
}

void quicksort(int* inputArray, int startIndex, int endIndex, int depth)
{
    //Depth is for debugging, but could also be used to avoid stack overflow
    //if the input data is simply too big for the call stack size
    //cout<<depth<<": "<<startIndex<<","<<endIndex<<endl;
    depth = depth + 1;
    if(startIndex < endIndex)
    {
        int pivotIndex = partitionArray(inputArray, startIndex, endIndex);
        //printArray(inputArray, 10);
        quicksort(inputArray, startIndex, pivotIndex-1, depth);
        quicksort(inputArray, pivotIndex+1, endIndex, depth);
    }
}
int partitionArray(int* inputArray, int startIndex, int endIndex)
{
    //This is a poor pivot choice. random or median(first middle last) avoid worst case on sorted inputs
    int pivot = inputArray[endIndex];
    int pivotIndex = endIndex;
    int i = startIndex;
    int j = endIndex - 1;
    while (i<j)
    {
        while(i < endIndex-1 && inputArray[i]<= pivot)
            i++;
        while(j > startIndex && inputArray[j] >= pivot)
            j--;
        if(i<j)
        {
            swapElements(inputArray, i, j);
        }
    }
    if(inputArray[i] > inputArray[pivotIndex])
    {
        swapElements(inputArray, i, pivotIndex);
        pivotIndex = i;
    }
    return pivotIndex;
}
//swap two elements of inputArray.
void swapElements(int* inputArray, int index1, int index2)
{
    //cout<<"Swapping: "<<inputArray[index1]<<" and "<<inputArray[index2]<<endl;
    int temp = inputArray[index1];
    inputArray[index1] = inputArray[index2];
    inputArray[index2] = temp;
}

void printArray(int* inputArray, int length)
{
    for(int i=0; i<length; i++)
    {
        cout<<inputArray[i]<<",";
    }
    cout<<endl;
}
