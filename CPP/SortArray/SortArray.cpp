#include <iostream>
using namespace std;

int main()
{
    string input1;
    string input2;
    getline(cin, input1);
    getline(cin, input2);

    cout<<input1<<","<<input2<<endl;
    int inputLength = atoi(input1.c_str());
    int* inputArray = new int[inputLength];
    for(int i=0; i<inputLength; i++)
    {
        char* d = &input2[2*i];
        inputArray[i] = atoi(d);

    }
    //bubble sort, for speed of implementation
    for(int i=0; i<inputLength; i++)
    {
        for(int j=0; j<inputLength-1; j++)
        {
            //cout<<"comparing: "<<inputArray[j]<<" with "<<inputArray[j+1]<<endl;
            if(inputArray[j] > inputArray[j+1])
            {
                //cout<<"swapping"<<endl;
                int temp = inputArray[j];
                inputArray[j] = inputArray[j+1];
                inputArray[j+1] = temp;
            }
            //cout<<"after swap: "<<inputArray[j]<<" with "<<inputArray[j+1]<<endl;
        }
    }

    for(int i=0; i<inputLength; i++)
    {
        cout<<inputArray[i]<<",";
    }
    cout<<endl;
}
