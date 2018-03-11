//https://practice.geeksforgeeks.org/problems/jumping-numbers/
#include <iostream>
#include <queue>
using namespace std;

void PrintJumpingNumbers(int, int);
bool debug = false;
int main()
{
	int numberOfTests;
    cin>>numberOfTests;

    for(int t=0; t<numberOfTests; t++)
    {
        int upperLimit;
        cin>>upperLimit;

        cout<<"0 ";		//zero is an edge case here, so just print it first
		for(int i=1; i<10; i++)
		{
			//print all the jumping numbers that start with i
			PrintJumpingNumbers(i, upperLimit);
		}
		cout<<endl;
	}
	return 0;
}
void PrintJumpingNumbers(int startDigit, int upperBound)
{
	queue<int> myQueue;
	myQueue.push(startDigit);
	while(!myQueue.empty())
	{
        int currentNumber = myQueue.front();
        myQueue.pop();
        //as of 2018-03-11 the GFG copy says "less than" but the test case
        //for "10" includes "10 in the output, hence <=
        if(currentNumber <= upperBound)
		{
            cout<<currentNumber<<" ";
            int lastDigitOfCurrentNumber = currentNumber % 10;
            //if number ends in 0, its only child is n + '1'
            if(lastDigitOfCurrentNumber > 0)
			{
				int leftChild = 10 * currentNumber + (lastDigitOfCurrentNumber - 1);
				myQueue.push(leftChild);
			}
			//if number ends in 9, its only child is n + '8'
			if(lastDigitOfCurrentNumber < 9)
			{
				int rightChild = 10 * currentNumber + (lastDigitOfCurrentNumber + 1);
				myQueue.push(rightChild);
			}
		}
	}
}

