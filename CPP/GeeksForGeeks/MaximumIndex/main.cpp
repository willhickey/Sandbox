//2018-03-09 10:32
//#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int numberOfTests;
    cin>>numberOfTests;
    for(int t=0; t<numberOfTests; t++)
    {
        int arrayLength;
        cin>>arrayLength;
        int* inputArray = new int[arrayLength];
        for(int j=0; j<arrayLength; j++)
        {
            cin>>inputArray[j];
        }
        int maxDifference = 0;
        int startIndexOfMax = 0;
        int endIndexOfMax = 0;
		for(int i=0; i<arrayLength-maxDifference; i++)
        {
            int j;
            //for(j=0; j<arrayLength; j++)
            for(j=i+maxDifference; j<arrayLength; j++)
			{
                if(inputArray[i] <= inputArray[j] && (j-i) > maxDifference)
				{
					maxDifference = j-i;
					startIndexOfMax = i;
					endIndexOfMax = j;
				}
			}
        }
        //cout<<maxDifference<<": "<<startIndexOfMax<<","<<endIndexOfMax<<endl;
        cout<<maxDifference<<endl;
        delete[] inputArray;
	}
	return 0;
}
