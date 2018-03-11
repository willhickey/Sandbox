//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include <iostream>
using namespace std;

int main()
{
    int numberOfTests;
    cin>>numberOfTests;
    for(int i=0; i<numberOfTests; i++)
    {
        int arrayLength;
        int targetSum;
        cin>>arrayLength;
        cin>>targetSum;
        int* inputArray = new int[arrayLength];
        for(int j=0; j<arrayLength; j++)
        {
            cin>>inputArray[j];
        }
        bool foundMatch = false;
        for(int startIndex=0; startIndex<arrayLength; startIndex++)
        {
            int currentSum = 0;
            int endIndex;
            for(endIndex=startIndex; endIndex<arrayLength; endIndex++)
            {
                currentSum+=inputArray[endIndex];
                if(currentSum==targetSum)
                    break;
            }
            if(currentSum==targetSum)
            {
                //The answers are existed as 1-based indexes
                cout<<startIndex+1<<" "<<endIndex+1<<endl;
                foundMatch = true;
                break;
            }
        }
        if(!foundMatch)
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
