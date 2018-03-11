//https://practice.geeksforgeeks.org/problems/finding-the-numbers/0
//#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
	int numberOfTests;
    cin>>numberOfTests;
    for(int i=0; i<numberOfTests; i++)
    {
        int numberOfInputs;
        int n;
        cin>>n;
        numberOfInputs = 2*n + 2;

        unordered_map<int, bool> numberHash;
        for(int j=0; j<numberOfInputs; j++)
        {
            int temp;
            cin>>temp;
            //This depends on the map values defaulting to false. If we didn't know this we'd need to
            //check if the key existed already.
            numberHash[temp] = !numberHash[temp];
        }
        const int numberOfAnswers = 2;
        int answers[numberOfAnswers];
        int answerCounter = 0;
        //iterate through the hash looking for true values
		for(auto const& x : numberHash)
		{
			//printf("%d: %d\n", x.first, x.second);
			if(x.second == true)	//these keys were flipped an odd number of times
			{
				answers[answerCounter] = x.first;
				answerCounter++;
			}
		}
		sort(answers, answers + numberOfAnswers);
		for(int i=0; i<numberOfAnswers; i++)
		{
			printf("%d ", answers[i]);
		}
		printf("\n");

    }
	return 0;
}
